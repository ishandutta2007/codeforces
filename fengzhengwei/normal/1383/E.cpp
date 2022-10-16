#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=1e9+7;
const int xx=1e6+5;
int to[xx][2];
char s[xx];
int sum[xx],n;//k 
int lb(int x){return x&-x;}
void add(int x,int y){x=n-x+1;for(;x<=n;x+=lb(x))sum[x]=min(sum[x],y);}
int ask(int x){x=n-x+1;int ans=2147483647;for(;x;x-=lb(x))ans=min(ans,sum[x]);return ans;}
int f[xx];
void red(int &x){if(x>=mod)x-=mod;}
int main(){
	memset(sum,0x3f,sizeof(sum));
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(to,0x3f,sizeof(f));
	if(s[1]=='0')to[0][0]=1;
	for(int j=1;j<=n;j++)if(s[j]=='1'){to[0][1]=j;break;}
	int S=0;
	for(int j=1;j<=n;j++)
	{
		if(s[j]!='0'){S=j;break;}
		if(s[j+1]=='0')to[j][0]=j+1;
		else if(s[j+1]=='1')for(int i=1;i<=j;i++)to[i][1]=j+1;
	}
	if(S==0)
	{
		cout<<n<<"\n";
		return 0;
	}
	int T=0;
	for(int j=n;j>=1;j--)if(s[j]!='0'){T=j;break;}
	int last=sum[0];
	for(int i=T;i>=S;i--)
	{
		if(s[i]=='1')to[i][1]=last,to[i][0]=ask(1),last=i;
		else 
		{
			int res=0;
			int j=i;
			while(s[i]=='0')res++,i--;
			i++;
			add(res,i);
			for(int k=i;k<=j;k++)to[k][1]=last;
			for(int k=i;k<j;k++)to[k][0]=k+1;
			to[j][0]=ask(res+1)+res;
		}
	}
	f[0]=1;
	for(int i=0;i<=n;i++)
	{
		if(to[i][0]<=n)f[to[i][0]]+=f[i],red(f[to[i][0]]);
		if(to[i][1]<=n)f[to[i][1]]+=f[i],red(f[to[i][1]]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(s[i]=='1')ans+=f[i],red(ans);
	cout<<1ll*ans*(n-T+1)%mod<<"\n";
	return 0;
}