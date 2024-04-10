#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],cnt[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=b[i]=get();sort(b+1,b+N+1);int M=unique(b+1,b+N+1)-b-1;
		For(i,1,M)cnt[i][0]=cnt[i][1]=0;For(i,1,N)a[i]=lower_bound(b+1,b+M+1,a[i])-b;For(i,1,N)cnt[a[i]][i&1]++;
		sort(a+1,a+N+1);bool flag=1;For(i,1,N)if(cnt[a[i]][i&1])cnt[a[i]][i&1]--;else{flag=0;break;}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}