#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 1200001
int N,l[MAXN],r[MAXN],x[MAXN],y[MAXN],ans,fc[MAXN],inv[MAXN];string a;
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}int C(int a,int b){if(a<0||b<0||b>a)return 0;return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	cin>>a;N=a.length();a=" "+a;For(i,1,N)l[i]=l[i-1]+(a[i]=='('),x[i]=x[i-1]+(a[i]=='?');FOR(i,N,1)r[i]=r[i+1]+(a[i]==')'),y[i]=y[i+1]+(a[i]=='?');fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	For(i,1,N-1)ans=(ans+1ll*l[i]*C(x[i]+y[i+1],y[i+1]+r[i+1]-l[i])+1ll*x[i]*C(x[i]+y[i+1]-1,y[i+1]+r[i+1]-l[i]-1))%P;cout<<ans<<endl;return 0;
}