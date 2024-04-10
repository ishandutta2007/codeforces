#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200010
const ll mod=1000000007;
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
int n,m,a,b,c,d,x,y,L,f[N],g[N],p[N],now;
char s[N];
ll fac[N],inv[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
ll C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll Get(int a,int b,int c,int d,int fir){
	if(a<0||b<0||c<0||d<0)return 0;
	if(b==0&&c==0){
		return a==0&&d==0||(fir?d==1&&a==0:d==0&&a==1);
	}
	if(b==c){
		return fir?C(a+b-1,b-1)*C(c+d,c)%mod:C(a+b,b)*C(c+d-1,c-1)%mod;	
	}
	else if(fir==1&&c==b+1||fir==0&&b==c+1){
		int mx=max(b,c);
		return C(mx+a-1,mx-1)*C(mx+d-1,mx-1)%mod;	
	} 
	else return 0;
}
ll dfs(int pos,int a,int b,int c,int d){
	if(pos==L+1){
		return !a&&!b&&!c&&!d&&now;
	}
	if(p[pos]==0){
		if(p[pos-1]==0)--a;
		else --c;
		return dfs(pos+1,a,b,c,d);
	}
	else{
		ll tmp=(p[pos-1]==0?Get(a-1,b,c,d,0):Get(a,b,c-1,d,0));
		if(p[pos-1]==0)--b;
		else --d;
		return (tmp+dfs(pos+1,a,b,c,d))%mod;
	}
}
ll calc1(){
	if(L>n)return 0;
	for(int i=1;i<=L;++i){
		p[i]=f[i];
	}
	now=0;
	return dfs(2,a,b,c,d);
}
ll calc2(){
	if(L<m)return Get(a,b,c,d,1);
	for(int i=1;i<=L;++i){
		p[i]=g[i];
	}
	now=1;
	return dfs(2,a,b,c,d);
}
int main(){
//	freopen("i.in","r",stdin);
//	freopen("i.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		f[i]=s[i]-'0';
	}
	scanf("%s",s+1);
	m=strlen(s+1);
	for(int i=1;i<=m;++i){
		g[i]=s[i]-'0';
	}
	a=read(),b=read(),c=read(),d=read();
	L=a+b+c+d+1;
	if(L>m||L<n||(!(b==c||c==b+1))){
		printf("0\n");
		return 0;
	}
	init(200000);
	printf("%lld\n",(calc2()-calc1()+mod)%mod);
	return 0;
}