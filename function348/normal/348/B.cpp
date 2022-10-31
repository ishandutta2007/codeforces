#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
struct Edge {int y,ne;};
int n,num;
int a[N];
LL s[N],d[N];
LL p,sumd;
Edge e[N*2];int last[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
void dfs(int i,int fa)
{
	LL k=0,l=1;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
	{
		dfs(e[j].y,i);
		s[i]+=s[e[j].y];
		if (p==0) continue;
		k++;
		LL g=d[e[j].y]/gcd(l,d[e[j].y]);
		if (1.0*l*g>1e+13) p=0;
		l=l*g;
	}
	s[i]+=a[i];
	if (k==0) k=1;
	d[i]=k*l;
}
void dfs2(int i,int fa)
{
	int k=0;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa) k++;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
	{
		d[e[j].y]=d[i]/k;
		dfs2(e[j].y,i);
	}
	if (k==0) p=min(p,a[i]/d[i]),sumd+=d[i];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	p=1000000000;
	dfs(1,0);
	if (p==0) { cout<<s[1]<<endl;return 0;}
	dfs2(1,0);
	cout<<s[1]-p*sumd<<endl;
	return 0;
}