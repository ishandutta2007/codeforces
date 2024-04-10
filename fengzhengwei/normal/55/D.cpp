#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll l,r;
ll f[20][5][7][8][9][258];
//25823456789 
bool check(int i5,int i7,int i8,int i9,int zt)
{
	for(int i=2;i<=9;i++)
	{
		if(zt>>(i-2)&1)
		{
			if(i==2&&(i8&1))return 0;
			if(i==3&&(i9%3))return 0;
			if(i==4&&(i8%4))return 0;
			if(i==5&&i5)return 0;
			if(i==6&&((i8&1)||(i9%3)))return 0;
			if(i==7&&i7)return 0;
			if(i==8&&i8)return 0;
			if(i==9&&i9)return 0;
		}
	}
//	cout<<zt<<"\n";
	return 1;
}
int bits[20];
ll dfs(int x,int i5,int i7,int i8,int i9,int zt,int bit)
{
	if(!x)return check(i5,i7,i8,i9,zt);
	if(!bit&&f[x][i5][i7][i8][i9][zt]!=-1)return f[x][i5][i7][i8][i9][zt];
	if(!bit)f[x][i5][i7][i8][i9][zt]=0;
	int k=bit?bits[x]:9;
	ll ans=0;
	for(int i=0;i<=k;i++)
	{
		int to=zt;if(i>=2)to|=(1<<i-2);
		ans+=dfs(x-1,(i5*10+i)%5,(i7*10+i)%7,(i8*10+i)%8,(i9*10+i)%9,to,bit&(i==k));
	}
	return bit?ans:f[x][i5][i7][i8][i9][zt]=ans;
}
ll get(ll x)
{
	bits[0]=0;
	while(x)
	{
		bits[++bits[0]]=x%10;
		x/=10;
	}
	return dfs(bits[0],0,0,0,0,0,1);
}
int main(){
	int T=read();
	memset(f,-1,sizeof(f));
	while(T--)
	{
		l=read(),r=read();
		cout<<get(r)-get(l-1)<<"\n";
	}
	return 0;
}