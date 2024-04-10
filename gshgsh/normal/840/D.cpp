#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,a[MAXN];vector<int>pos[MAXN];mt19937 rnd(time(0));
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int check(int k,int l,int r){return upper_bound(pos[k].begin(),pos[k].end(),r)-lower_bound(pos[k].begin(),pos[k].end(),l);}
int main()
{
	N=get(),M=get();For(i,1,N)pos[a[i]=get()].push_back(i);
	For(i,1,M)
	{
		int l=get(),r=get(),k=get();int ans=N+1;
		For(t,1,70){int x=rnd()%(r-l+1)+l;if(pos[a[x]].size()>(r-l+1)/k&&check(a[x],l,r)>(r-l+1)/k)ans=min(ans,a[x]);}
		cout<<(ans==N+1?-1:ans)<<'\n';
	}
	return 0;
}