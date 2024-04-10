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
int n;
LL f[5005][5005],pre[5005],suf[5005];
int a[5005],b[5005];
int main(){
	LL rest=0;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) scanf("%d",&b[i]);
	rb(i,1,n) pre[i]=1ll*a[i]*b[i]+pre[i-1];
	rl(i,n,1) suf[i]=1ll*a[i]*b[i]+suf[i+1];
	rl(i,n,1) rb(j,1,n) f[i][j]=f[i+1][j-1]+1ll*a[i]*b[j]; 
	rb(i,1,n) rb(j,i,n){
		check_max(rest,pre[i-1]+suf[j+1]+f[i][j]-f[j+1][i-1]);
//		cout<<i<<" "<<j<<' '<<pre[i-1]+suf[j+1]<<" "<<f[i+1][j-1]<<" "<<f[j+1][i-1]<<endl;
	}
	printf("%lld\n",rest);	
	return 0;
}