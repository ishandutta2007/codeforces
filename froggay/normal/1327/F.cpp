#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define N 500050
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,k,m,l[N],r[N],x[N],s[N],lim[N];
ll ans,dp[N];
int main(){
	n=read()+1,k=read(),m=read();
	ans=1;
	for(int i=1;i<=m;++i){
		l[i]=read(),r[i]=read()+1,x[i]=read();
	}
	for(int i=0;i<k;++i){
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		memset(lim,0,sizeof(lim));
		for(int j=1;j<=m;++j){
			if((x[j]>>i)&1){
				s[l[j]]++,s[r[j]]--;
			}
			else{
				lim[r[j]]=max(lim[r[j]],l[j]);
			}
		} 
		for(int j=1;j<=n;++j){
			s[j]+=s[j-1];
			lim[j]=max(lim[j],lim[j-1]);
		}
		dp[0]=1;
		ll sum=1;
		int _0=0;
		for(int j=1;j<=n;++j){
			while(_0<lim[j])sum=(sum-dp[_0]+mod)%mod,++_0;
			if(s[j])continue;
			dp[j]=sum;
			sum=(sum+dp[j])%mod;
		}
		ans=ans*dp[n]%mod;
	}
	cout<<ans<<endl;
	return 0;
}