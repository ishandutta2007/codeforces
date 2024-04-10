#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,l,r,cnt[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),l=get(),r=get();For(i,1,N)cnt[i][0]=cnt[i][1]=0;For(i,1,N)cnt[get()][l<=r?i<=l:i>l]++;if(l<r)swap(l,r);
		For(i,1,N){int x=min(cnt[i][0],cnt[i][1]);cnt[i][0]-=x,cnt[i][1]-=x,l-=x,r-=x;}
		int ans=0;For(i,1,N){int x=min(l-r>>1,cnt[i][0]>>1);cnt[i][0]-=x<<1,l-=x<<1,ans+=x;}cout<<ans+l<<endl;
	}
	return 0;
}