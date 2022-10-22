#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M1,M2,f1[MAXN],f2[MAXN];vector<pair<int,int>>ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int*f,int x){return f[x]==x?x:f[x]=getf(f,f[x]);}
void mrg(int*f,int x,int y){f[getf(f,x)]=getf(f,y);}
bool check(int x,int y){return getf(f1,x)!=getf(f1,y)&&getf(f2,x)!=getf(f2,y);}
int main()
{
	N=get(),M1=get(),M2=get();For(i,1,N)f1[i]=f2[i]=i;For(i,1,M1)mrg(f1,get(),get());For(i,1,M2)mrg(f2,get(),get());
	int x=1;vector<int>l,r;For(i,2,N)if(check(1,i))ans.push_back({1,i}),mrg(f1,1,i),mrg(f2,1,i);
	For(i,2,N)if(getf(f1,i)!=getf(f1,1))l.push_back(i),mrg(f1,1,i);else if(getf(f2,i)!=getf(f2,1))r.push_back(i),mrg(f2,1,i);
	int M=min(l.size(),r.size());For(i,0,M-1)ans.push_back({l[i],r[i]});
	cout<<ans.size()<<'\n';for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';return 0;
}