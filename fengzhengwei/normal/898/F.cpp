#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=1145141923,base=10,mod2=998244353,xx=1e6+5;// int 
char s[xx];
ll ksm(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll sum[xx],pw[xx],ni[xx],pw2[xx],ni2[xx],sum2[xx],n;
ll get(int l,int r){return (sum[r]-sum[l-1]+mod)*ni[n-r]%mod;}
ll get2(int l,int r){return (sum2[r]-sum2[l-1]+mod2)*ni2[n-r]%mod2;}
bool check(int l,int r)
{
	if(l>=r)return 0;
	if(l+1==r)return 0;
	if(l>1&&s[0]=='0')return 0;
	//1~l l+1~r-1 r~n 
	if(r<n&&s[r]=='0')return 0;
	if(r-l-1!=1&&s[l+1]=='0')return 0;
//	if((get(1,l)+get(l+1,r-1))%mod==get(r,n))
//	cout<<l<<" "<<r<<" "<<get2(1,l)<<" "<<get2(l+1,r-1)<<" "<<get2(r,n)<<"\n";
	return (get(1,l)+get(l+1,r-1))%mod==get(r,n)&&(get2(1,l)+get2(l+1,r-1))%mod2==get2(r,n);
}
void C(int L,int R)
{
	if(check(L,R))
	{
		for(int i=1;i<=L;i++)cout<<s[i];
		cout<<"+";
		for(int i=L+1;i<=R-1;i++)cout<<s[i];
		cout<<"=";
		for(int i=R;i<=n;i++)cout<<s[i];
		puts("");
		exit(0);
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	ni[0]=1;ni[1]=ksm(base,mod-2,mod);
	for(int i=2;i<xx;i++)ni[i]=ni[i-1]*ni[1]%mod;
	pw2[0]=1;
	for(int i=1;i<xx;i++)pw2[i]=pw2[i-1]*base%mod2;
	ni2[0]=1;ni2[1]=ksm(base,mod2-2,mod2);
	for(int i=2;i<xx;i++)ni2[i]=ni2[i-1]*ni2[1]%mod2;
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+(s[i]-'0')*pw[n-i])%mod;
	for(int i=1;i<=n;i++)sum2[i]=(sum2[i-1]+(s[i]-'0')*pw2[n-i])%mod2;
	for(int i=1;i<=n;i++)// 
	{
		C(i,n-i+1);
		C(i,n-i);
		int len=(n-i+1)>>1;
		C(i,n-len+1);
		C(i,n-len);
	}
	return 0;
}