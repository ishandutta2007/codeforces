#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 20001
int N,M,a[2][MAXN],f[2][MAXN],ans;vector<int>pos[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int get16(){int c=getchar();while((c<'0'||c>'9')&&(c<'A'||c>'F'))c=getchar();return c<='9'?c-'0':c-'A'+10;}
int getf(int id,int x){return f[id][x]==x?x:f[id][x]=getf(id,f[id][x]);}
void mrg(int id,int x,int y){f[id][getf(id,x)]=getf(id,y);}
int main()
{
	N=get(),M=get();For(i,1,M)f[1][i]=i;For(i,1,M/4){int x=get16();For(j,0,3)a[1][i*4-j]=x>>j&1;}For(i,1,M-1)if(a[1][i]&&a[1][i+1])mrg(1,i,i+1);
	For(k,2,N)
	{
		int now=k&1,lst=now^1;For(i,1,M)f[now][i]=i;For(i,1,M/4){int x=get16();For(j,0,3)a[now][i*4-j]=x>>j&1;}
		For(i,1,M)if(a[lst][i]&&a[now][i])pos[getf(lst,i)].push_back(i);
		For(i,1,M)if(f[lst][i]==i&&a[lst][i])if(pos[i].empty())ans++;else{int K=pos[i].size();For(j,1,K-1)mrg(now,pos[i][j-1],pos[i][j]);}
		For(i,1,M)pos[i].clear();For(i,1,M-1)if(a[now][i]&&a[now][i+1])mrg(now,i,i+1);
	}
	For(i,1,M)if(a[N&1][i]&&f[N&1][i]==i)ans++;cout<<ans<<'\n';return 0;
}