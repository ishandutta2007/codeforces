#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define pb push_back
#define F first
#define S second
#define MAXN 300001
int T,N,M,a[MAXN],type[MAXN],top,sta[MAXN],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();vector<Pair>b[2];For(i,1,N)a[i]=get(),ans[i]=-1,b[a[i]&1].pb({a[i],i});For(i,1,N){char c;cin>>c;type[i]=c=='L';}
		For(j,0,1)
		{
			sort(b[j].begin(),b[j].end());
			for(auto i:b[j])
			{
				int x=i.F,id=i.S;
				type[id]?top?ans[id]=ans[sta[top]]=x-a[sta[top]]>>1,top--:a[sta[++top]=id]=-x:sta[++top]=id;
			}
			while(top>1){ans[sta[top]]=ans[sta[top-1]]=M-(a[sta[top]]+a[sta[top-1]]>>1),top-=2;}top=0;
		}
		For(i,1,N)cout<<ans[i]<<" \n"[i==N];
	}
	return 0;
}