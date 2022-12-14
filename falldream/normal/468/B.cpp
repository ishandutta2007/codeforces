#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define Rev(x) ((x&1)?x+1:x-1)
namespace SAT2
{
    #define MX 200000
    vector<int> v[MX+5],V[MX+5];
    int n,b[MX+5],dn,q[MX+5],mark[MX+5],num,yes[MX+5];
    void init(int sz)
    {
        for(int i=1;i<=sz;++i) v[i].clear(),V[i].clear(),mark[i]=b[i]=yes[i]=0;
        dn=num=0;n=sz;
    }
    void ins(int f,int t)
    {
        v[f].push_back(t);
        v[Rev(t)].push_back(Rev(f));
        V[t].push_back(f);
        V[Rev(f)].push_back(Rev(t));
    }
    void dfs(int x)
    {
        b[x]=1;
        for(int i=0;i<v[x].size();++i)
            if(!b[v[x][i]]) dfs(v[x][i]);
        q[++dn]=x;
    }
    void rdfs(int x)
    {
        mark[x]=num;
        for(int i=0;i<V[x].size();++i)
            if(!mark[V[x][i]]) rdfs(V[x][i]);
    }
    bool Solve()
    {
        for(int i=1;i<=n;++i)
            if(!b[i]) dfs(i);
        for(int i=n;i;--i)
            if(!mark[q[i]]) ++num,rdfs(q[i]);
        for(int i=1;i<=n;++i) if(mark[i]==mark[Rev(i)]) return false;
        for(int i=1;i<=n;++i) yes[mark[i]>mark[Rev(i)]?i:Rev(i)]=1;
        return true;
    }
}
#define MN 100000
int n,a,b,s[MN+5];
map<int,int> mp;
int main()
{	
	n=read();a=read();b=read();SAT2::init(2*n);
	for(int i=1;i<=n;++i) mp[s[i]=read()]=i;
	for(int i=1;i<=n;++i)
	{
		int t1=mp[a-s[i]],t2=mp[b-s[i]];
		if(t1) SAT2::ins(2*i-1,2*t1-1);	
		else SAT2::ins(2*i-1,2*i);
		if(t2) SAT2::ins(2*i,2*t2);
		else SAT2::ins(2*i,2*i-1);
	}
	if(!SAT2::Solve()) return 0*puts("NO");
	puts("YES");
	for(int i=1;i<=n;++i) printf(SAT2::yes[2*i-1]?"0 ":"1 ");
	return 0;
}