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
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+233;
int a[MAXN],n,m;
vector<int> cyc;
bool check(int x){
	int fst=INF;
	rb(z,1,n){
		bool ok=true;
		int need=m-a[n-z+1]-x;
		if(need>x) break;
		int to=1-need;
		rb(i,1,n){
			if(a[i]<=to){
				to=a[i]+x+1;
				continue;
			}
			if(i!=n-z&&i!=n&&a[i+1]-x<=to&&a[i+1]!=a[i]+1){
				to=a[i]+x+1;
				i++;
				continue;
			}
			if(a[i]-x<=to&&i!=n-z+1){
				to=a[i]+1;
				continue;
			}
			else{
				break;
			}
		}
		if(to>=min(a[n-z+1],fst)&&ok) return true;
		check_min(fst,a[n-z+1]-x);
	}
	return false;
}
int main(){
	scanf("%d",&m);
	scanf("%d",&n);
	rb(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	int l=0,r=0;
	rb(i,1,n-1) cyc.PB(a[i+1]-a[i]-1);
	cyc.PB(m-a[n]+a[1]-1);
	vector<int> Tmp;
	r=*max_element(ALL(cyc));
	int z=0;
	rb(i,0,n-1) if(cyc[i]==r){
		z=i;
		break;
	}
	rb(i,z+1,n-1) Tmp.PB(cyc[i]);
	rb(i,0,z) Tmp.PB(cyc[i]);
	cyc=Tmp;
	a[1]=1;
	rb(i,2,n) a[i]=a[i-1]+cyc[i-2]+1;
	assert(a[n]+cyc.back()==m);
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}