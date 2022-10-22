#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int Q;map<int,int>f,siz,val;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void mrg(int x,int y,int w){if(!f[x]&&!siz[x])siz[x]=1;if(!f[y]&&!siz[y])siz[y]=1;while(f[x])w^=val[x],x=f[x];while(f[y])w^=val[y],y=f[y];if(x==y)return;if(siz[x]>siz[y])swap(x,y);f[x]=y,siz[y]+=siz[x];val[x]=w;}
int ask(int x,int y){int ans=0;while(f[x])ans^=val[x],x=f[x];while(f[y])ans^=val[y],y=f[y];return x==y?ans:-1;}
int main()
{
	Q=get();int lst=0;
	while(Q--)
	{
		int opt=get(),l=get()^lst,r=get()^lst;if(l>r)swap(l,r);r++;
		if(opt==1){int x=get()^lst;mrg(l,r,x);}else{int ans=ask(l,r);if(ans==-1)lst=1;else lst=ans;cout<<ans<<'\n';}
	}
	return 0;
}