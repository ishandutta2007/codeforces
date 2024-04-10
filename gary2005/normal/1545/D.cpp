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
const int MAXN=1e3+5;
int m,k,a[MAXN][MAXN],sum[MAXN];
LL calc(int A,int B,int C){
	LL suma=0,sumb=0,sumc=0;
	rb(i,1,m) suma+=1ll*a[A][i]*a[A][i];
	rb(i,1,m) sumb+=1ll*a[B][i]*a[B][i];
	rb(i,1,m) sumc+=1ll*a[C][i]*a[C][i];
	sumb-=suma;
	sumc-=suma;
	sumc-=2*sumb;
	if(sumc&1) return -1;
	return sumc/2;
}
int main(){
	scanf("%d%d",&m,&k);
	rb(i,1,k) rb(j,1,m) scanf("%d",&a[i][j]),sum[i]+=a[i][j];
	int is=(sum[k]-sum[1])/(k-1);
	int bad=0;
	rb(i,2,k-1) if(sum[i]-sum[i-1]!=is){
		bad=i;
		break;
	}
	LL Tmp;
	if(bad<=3){
		Tmp=calc(bad+1,bad+2,bad+3);
	}
	else{
		Tmp=calc(1,2,3);
	}
	int Need=(sum[bad]-sum[bad-1])-is;
	rb(i,1,m){
		a[bad][i]-=Need;
		bool ok=0;
		if(bad<=3) ok=(Tmp==calc(bad,bad+1,bad+2));
		else ok=(Tmp==calc(bad-2,bad-1,bad));
		if(ok){
			cout<<bad-1<<" "<<a[bad][i]<<endl;
			ff;
			return 0;
		}
		a[bad][i]+=Need;
	}
	return 0;
}