#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define DITOLY 320
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int num[DITOLY+5][MN+5],s[MN+5],n,cnt=0,tot=1,size,mark[MN+5],g[MN+5];
int answer[MN+5],type[DITOLY+5];

int main()
{
	n=read();size=sqrt(n);
	for(int i=1;i<=n;i++)s[i]=read();
	for(int j=1;j<=size;j++)	
	{
		int kind=0,ans=0;++tot;
		for(int i=1;i<=n;i++)
		{
			if(mark[s[i]]==tot) {if(j==size)num[cnt+1][s[i]]++;continue;}
			mark[s[i]]=tot;kind++;
			if(kind>j){if(j==size)g[++cnt]=i-1;ans++;kind=1;++tot;mark[s[i]]=tot;};
			if(j==size) num[cnt+1][s[i]]++,type[cnt+1]++;
		}
		if(kind) ans++;if(j==size)g[++cnt]=n;
		printf("%d ",ans);
	}
	for(int i=size+1;i<=n;i++)
	{
		for(int j=1;j<cnt;j++)
		{
			if(g[j]>=n) {cnt=j+1;break;}
			while(g[j]<n&&type[j]+(num[j][s[g[j]+1]]==0)<=i)
			{
				g[j]++;if(++num[j][s[g[j]]]==1) type[j]++;
				if(!--num[j+1][s[g[j]]]) type[j+1]--;
		//		cout<<j<<" "<<g[j]<<"++"<<endl;
			}
		}
		while(cnt>1&&g[cnt-1]==n) cnt--;
		printf("%d ",cnt);
	//		cout<<endl<<"!"<<cnt<<endl;
	//	for(int i=1;i<=cnt;i++)
	//	cout<<g[i]<<" ";puts("");
	}
    return 0;
}