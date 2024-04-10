#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,f[MAXN],ans[MAXN],res;set<int>s[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(s[x].size()>s[y].size())swap(x,y);res--;res-=ans[x]+ans[y];f[x]=y;
	for(auto i:s[x]){bool f1=s[y].count(i+1),f2=s[y].count(i-1);if(f1&&f2)ans[y]--;else if(!f1&&!f2)ans[y]++;s[y].insert(i);}res+=ans[y];
}
int main()
{
	N=get(),M=get();For(i,1,N)s[get()].insert(i);For(i,1,M)f[i]=i;res=M-1;For(i,1,M){for(auto j=s[i].begin(),k=j++;j!=s[i].end();j++,k++)ans[i]+=(*k)+1!=(*j);res+=ans[i];}
	For(i,1,M-1)cout<<res<<'\n',mrg(get(),get());cout<<"0\n";return 0;
}