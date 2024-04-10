//2018.10.22 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const int kcz=2520;
const int N=19+10;
namespace MAIN{
	LL Q;
	inline LL get(const res &i,const res &S){
		return i<2?S:S|(1<<(i-2));
	}
	LL dp[N][256+10][kcz+10],a[N];
	LL DP(const res &dep,const res &S,const res &sum,const bool &flag){
		if(dep==0){
			for(res i=2;i<=9;i++)if(S&(1<<(i-2))&&sum%i)return 0;
			return 1;
		}
		if(!flag&&dp[dep][S][sum]>=0)return dp[dep][S][sum];
		res pos=flag?a[dep]:9,ret=0;
		for(res i=0;i<=pos;i++)ret+=DP(dep-1,get(i,S),(sum*10+i)%kcz,flag&(i==pos));
		if(!flag)dp[dep][S][sum]=ret;
		return ret;
	}
	inline LL solve(res x){
		res len=0;
		while(x)a[++len]=x%10,x/=10;
		return DP(len,0,0,1);
	}
	inline void MAIN(){
		Q=read();
		memset(dp,-1,sizeof(dp));
		while(Q--){
			res l=read(),r=read();
			printf("%lld\n",solve(r)-solve(l-1));
		}
	} 
}
int main(){
    MAIN::MAIN();
    return 0;
}