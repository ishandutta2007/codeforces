/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=5e5+233;
int n,m;
LL k;
int q[MAXN];
int a[MAXN];
int b[MAXN];
map<int,int> pos;
vector<int> v;
bool vis[MAXN];
bool check(LL x){
	LL tur=x/m;
	LL Lm=x%m;
	LL sum=0;
	for(auto it:v){
		sum+=q[it];
	}
	if(tur/v.size()&&k/(tur/v.size())<sum){
		return 0;	
	}
	sum*=tur/v.size();
	tur%=v.size();
	rep(i,tur){
		sum+=q[v[i]]; 
	}
	int now=v[tur];
	rb(i,1,Lm){
		sum+=(a[(now+(i-1)-1)%n+1]!=b[i]);
	}
	return sum<k;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	rb(i,1,n) scanf("%d",&a[i]),pos[a[i]]=i;
	rb(i,1,m){
		scanf("%d",&b[i]);	
		if(pos.find(b[i])!=pos.end()){
			int I,J;
			I=pos[b[i]];
			J=i;
			I-=(J-1);
			I--;
			I+=n*2;
			I%=n;
			I++;
			q[I]++;
		}
	}
	rb(i,1,n) q[i]=m-q[i];
	int now=1;
	while(!vis[now]){
		vis[now]=1;
		v.PB(now);
		now+=m;
		now--;
		now%=n;
		now++;
	}
	LL l=0,r=1e18;
	while(l<r-1){
		LL mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l+1<<endl;
	return 0;
}