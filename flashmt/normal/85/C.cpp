#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define maxN 100100
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n,Q,root,c[maxN],Min[maxN],Max[maxN],Cnt[maxN*5];
long long Sum[maxN*5];
double re[maxN];
vector < int > X,a[maxN];
vector < pair<int,int> > q;

void Update_Tree(int nd,int l,int r,int x,int y,int val)
{
	if (l==x && r==y)
	{
		Sum[nd]+=val;	Cnt[nd]++;
		return;
	}
	int m=(l+r)/2;
	if (x<=m) Update_Tree(nd*2,l,m,x,min(y,m),val);
	if (m<y) Update_Tree(nd*2+1,m+1,r,max(x,m+1),y,val);
}

void Add(int low,int high,int val)
{
	int x,y; 
	x=lower_bound(q.begin(),q.end(),make_pair(low,0))-q.begin();
	y=lower_bound(q.begin(),q.end(),make_pair(high+1,-1))-q.begin();
	--y; 
	if (y>=x) Update_Tree(1,0,Q-1,x,y,val);
}

void Visit(int x,int low,int high)
{
	Min[x]=Max[x]=c[x]; 
	if (a[x].empty()) return;
	int l=a[x][0],r=a[x][1];
	if (c[l]>c[r]) swap(l,r);
	Visit(l,low,c[x]-1);
	Visit(r,c[x]+1,high);
	Min[x]=Min[l]; Max[x]=Max[r];
	Add(low,c[x]-1,Min[r]);
	Add(c[x]+1,high,Max[l]);
}

void Get_Result(int nd,int l,int r,long long curSum,int curCnt)
{
	curSum+=Sum[nd]; curCnt+=Cnt[nd];
	if (l==r) re[q[l].second]=1.0*curSum/curCnt;
	else
	{
		int m=(l+r)/2;
		Get_Result(nd*2,l,m,curSum,curCnt);
		Get_Result(nd*2+1,m+1,r,curSum,curCnt);
	}
}

int main()
{
	//freopen("c.in.2","r",stdin);
	int i,x;
	cin >> n;
	fr(i,1,n)
	{
		scanf("%d%d",&x,&c[i]);
		if (x<0) root=i;
		else a[x].push_back(i);
	}
	cin >> Q;
	fr(i,1,Q) 
	{
		scanf("%d",&x);
		q.push_back(make_pair(x,i)); 
	}
	sort(q.begin(),q.end());
	Visit(root,1,1000000000);
	Get_Result(1,0,Q-1,0,0);
	fr(i,1,Q) printf("%.10lf\n",re[i]);
	return 0;
}