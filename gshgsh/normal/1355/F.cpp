#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int M=1000,tot,prm[MAXN],K=17;ll x[18];bool Not[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(ll x){cout<<"? "<<x<<endl;return get();}
int main()
{
	For(i,2,M){if(!Not[i])prm[++tot]=i;for(int j=1;j<=tot&&i*prm[j]<=M;j++){Not[i*prm[j]]=1;if(i%prm[j]==0)break;}}
	int j=0;For(i,1,K){x[i]=1;while(1.0*x[i]*prm[j+1]<1e18)x[i]*=prm[++j];}
	int T=get();
	while(T--)
	{
		int a=1;For(i,1,K)a*=ask(x[i]);vector<int>Div;For(i,1,j)if(a%prm[i]==0)Div.push_back(prm[i]);
		int ans=1,s=Div.size();for(int i=0;i<s;i+=2){int x=1,y=1;while(1.0*x*Div[i]<1e9)x*=Div[i];if(i+1<s)while(1.0*y*Div[i+1]<1e9)y*=Div[i+1];ans*=ask(1ll*x*y);}
		int res=1;For(i,1,j)if(ans%prm[i]==0){int cnt=1;while(ans%prm[i]==0)cnt++,ans/=prm[i];res*=cnt;}
		cout<<"! "<<max(res+7,res*2)<<endl;
	}
	return 0;
}