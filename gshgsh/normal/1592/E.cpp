#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,a[MAXN],ans;map<int,int>pos;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();
	For(j,0,19)
	{
		int sum=0;pos.clear();pos[0]=1;
		For(i,1,N)
		{
			if(!((a[i]>>j)&1)){pos.clear();sum=0;pos[0]=i+1;continue;}
			sum^=a[i];int x=(sum>>j)<<j;if(pos[x])ans=max(ans,i-pos[x]+1);else pos[x]=i+1;
		}
	}
	cout<<ans<<'\n';return 0;
}