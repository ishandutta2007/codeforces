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
const int MAXN=2e5+233;
const int N=5e6+233;
int p[MAXN],k[MAXN],b[MAXN],w[MAXN],t[N],pre[N],nex[N];
int n,m;
LL a[N];
LL old[N];
int seed=0,base=0;
int rnd(){
	int ret=seed;
	seed = (1ll*seed * base%1000000007 + 233) % 1000000007;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m) scanf("%d%d%d%d",&p[i],&k[i],&b[i],&w[i]);
	rb(i,1,m){
		seed=b[i];
		base=w[i];
		rb(j,p[i-1]+1,p[i]){
			t[j]=(rnd()%2)+1;
			old[j]=a[j]=(rnd()%k[i])+1;
		}
	}
	LL A=0,B=0;
	rb(i,1,n)
	{
		if(t[i]==1) A+=a[i];
		else B+=a[i];
	}
	if(A>B){
		swap(A,B);
		rb(i,1,n) t[i]=((t[i]-1)^1)+1;
	}
	if(t[1]==1){
		LL cnt=0;
		rb(i,1,n){
			if(t[i]==1){
				cnt+=a[i];
				a[i]=0;
			}
			else{
				LL tmp=min(cnt,a[i]);
				cnt-=tmp;
				a[i]-=tmp;
			}
		}
		rb(i,1,n){
			if(t[i]==1){
				cnt+=a[i];
				a[i]=0;
			}
			else{
				LL tmp=min(cnt,a[i]);
				cnt-=tmp;
				a[i]-=tmp;
			}
		}
	}
	else{
		a[1]--;
		LL cnt=0;
		rb(i,1,n){
			if(t[i]==1){
				cnt+=a[i];
				a[i]=0;
			}
			else{
				LL tmp=min(cnt,a[i]);
				cnt-=tmp;
				a[i]-=tmp;
			}
		}
		rb(i,1,n){
			if(t[i]==1){
				cnt+=a[i];
				a[i]=0;
			}
			else{
				LL tmp=min(cnt,a[i]);
				cnt-=tmp;
				a[i]-=tmp;
			}
		}
	}
	int ret=1;
	rb(i,1,n){
		a[i]=old[i]-a[i];
		ret=1ll*ret*((a[i]^(1ll*i*i))%(1000000000+7)+1)%(1000000000+7);
	}
	cout<<ret<<endl;
	return 0;
}