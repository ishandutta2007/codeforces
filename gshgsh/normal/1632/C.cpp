#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int check(int a,int b,int c)
{
	int high=-1;
	FOR(i,c-1,0){int x=a>>i&1,y=b>>i&1;if(x&&!y){high=i;break;}}if(high==-1)return 0;
	int ans=0;For(i,high,c-1){int x=a>>i&1,y=b>>i&1;if(x&&!y){int tmp=(1<<i)-(a&(1<<i)-1);a+=tmp;ans+=tmp;}}return ans;
}
int main()
{
	int T=get();
	while(T--)
	{
		int a=get(),b=get();
		int c=1;while(1<<c<=b)c++;int ans=b-a,now=0;
		while(b<1<<c)
		{
			ans=min(ans,check(a,b,c)+1+now);b++;now++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}