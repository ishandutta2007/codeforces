#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 200000
int n,m,a[MN+5],X[MN+5],pos[MN+5],id[MN+5];
bool cmp(int x,int y){return a[x]<a[y];}
inline int GetBef(int L)
{
	int l=1,r=n,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(X[mid]<=L) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}

inline int GetAft(int L)
{
	int l=1,r=n,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(X[mid]>=L) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i) pos[id[i]]=i,X[i]=a[id[i]]; 
	for(int i=1;i<=m;++i)
	{
		int x=pos[read()],l=read();	
		for(;;)
		{
			int t=GetBef(X[x]+l),t2=GetAft(X[t]-(l-(X[t]-X[x])));	
	//		printf("%d %d %d %d\n",X[x],l,t,t2);
			if(t==t2) {printf("%d\n",id[t]);break;}
			else 
			{			
				l-=(X[t]-X[x]+(X[t]-X[t2]));
				l=l%(2*(X[t]-X[t2]));x=t2;
			}
		}
	}
	return 0;
}