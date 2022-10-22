#include<iostream>
#include<vector>
#include<bitset>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define Pair pair<pair<pair<int,int>,pair<int,int> >,int>
#define F first
#define S second
#define pb push_back
#define MAXN 501
#define MAXM 600001
int N,M,Q,a[MAXN][MAXN],ans[MAXM];bitset<MAXN>f[MAXN][MAXN],g[MAXN][MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c=getchar();while(c!='.'&&c!='#')c=getchar();return c=='.';}
void solve(int l,int r,vector<Pair>q)
{
	int mid=l+r>>1;FOR(i,M,1)if(a[mid][i])f[mid][i]=f[mid][i+1],f[mid][i][i]=1;For(i,1,M)if(a[mid][i])g[mid][i]=g[mid][i-1],g[mid][i][i]=1;
	FOR(i,mid-1,l)FOR(j,M,1)if(a[i][j])f[i][j]=f[i+1][j]|f[i][j+1];For(i,mid+1,r)For(j,1,M)if(a[i][j])g[i][j]=g[i-1][j]|g[i][j-1];
	vector<Pair>ql,qr;for(auto v:q)if(v.F.S.F<mid)ql.pb(v);else if(v.F.F.F>mid)qr.pb(v);else{ans[v.S]=(f[v.F.F.F][v.F.F.S]&g[v.F.S.F][v.F.S.S]).any();}
	if(!ql.empty())solve(l,mid-1,ql);if(!qr.empty())solve(mid+1,r,qr);
}
int main()
{
	N=get(),M=get();For(i,1,N)For(j,1,M)a[i][j]=getc();vector<Pair>q;Q=get();For(i,1,Q){int x1=get(),y1=get(),x2=get(),y2=get();q.pb({{{x1,y1},{x2,y2}},i});}
	solve(1,N,q);For(i,1,Q)puts(ans[i]?"Yes":"No");return 0;
}