#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],p[MAXN],q[MAXN];set<int>b[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)b[i].clear();For(i,1,N)a[i]=get(),b[a[i]].insert(i);set<int>c;For(i,1,N)if(b[i].size()>=2)c.insert(i);
		For(i,1,N)if(b[i].empty()){bool flag=0;for(auto j:c){for(auto k:b[j])if(k!=i){p[k]=i;b[j].erase(k);flag=1;break;}if(flag){if(b[j].size()==1)c.erase(j);break;}}}
		For(i,1,N)if(!b[i].empty())p[*b[i].begin()]=i;
		int ans=0;For(i,1,N)ans+=p[i]==a[i];cout<<ans<<endl;For(i,1,N)cout<<p[i]<<" \n"[i==N];
	}
}