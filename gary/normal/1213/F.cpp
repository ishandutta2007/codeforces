//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
int p[200000+10],q[200000+10];
map<int,int> m1,m2;
int sum[200000+10]={-INF};
int boss[200000+10];
int find_(int now){return (boss[now]==now)? now:boss[now]=find_(boss[now]);}
int color[200000+10],minus_tab[200000+10],cut[200000+10];
int main(){
	cin>>n>>k;
	rep(i,n) boss[i+1]=i+1;
	rep(i,n) scanf("%d",&p[i+1]),m1[p[i+1]]=i+1;
	rep(i,n) scanf("%d",&q[i+1]),m2[q[i+1]]=i+1;
	memset(minus_tab,0,sizeof(minus_tab));
	rb(i,1,n) sum[i]=max(sum[i-1],m2[p[i]]);
	rb(i,1,n) {
		if(sum[i-1]>=m2[p[i]]){
			int l=1,r=i-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(sum[mid]>=m2[p[i]]) r=mid;
				else l=mid+1;
			}
			minus_tab[l]++;
			minus_tab[i+1]--;
			cut[i+1]++;
		}
	}
	rb(i,1,n){
		minus_tab[i]+=minus_tab[i-1];
	}
	rb(i,1,n) if(minus_tab[i]&&minus_tab[i-1]&&cut[i]<minus_tab[i-1]) boss[find_(p[i-1])]=find_(p[i]);
	memset(cut,0,sizeof(cut));
	m2=m1;
	memset(minus_tab,0,sizeof(minus_tab));
	rb(i,1,n) sum[i]=max(sum[i-1],m2[q[i]]);
	rb(i,1,n) {
		if(sum[i-1]>=m2[q[i]]){
			int l=1,r=i-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(sum[mid]>=m2[q[i]]) r=mid;
				else l=mid+1;
			}
			minus_tab[l]++;
			minus_tab[i+1]--;
			cut[i+1]++;
		}
	}
	rb(i,1,n){
		minus_tab[i]+=minus_tab[i-1];
	}
	rb(i,1,n) if(minus_tab[i]&&minus_tab[i-1]&&cut[i]<minus_tab[i-1]) boss[find_(q[i-1])]=find_(q[i]);
	int To=0;
	rb(it,1,n){
		int i=p[it];
		if(find_(i)==i){
			color[i]=min(25,To++);
		}
	}
	if(To<k) puts("NO");
	else{
		puts("YES");
		rb(i,1,n){
			cout<<char('a'+color[find_(i)]);
		} cout<<endl;
	}
	return 0;
}