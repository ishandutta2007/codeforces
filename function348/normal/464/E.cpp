#include<cstdio>
#include<iostream>
#include<queue>
#define MP make_pair
#define FR first 
#define SC second
using namespace std;
typedef pair<int,int> PII;
struct Edge {int y,z,ne;};

const int N=100010,NN=10000000;
const int mo=1000000007;
int n,m,R,num,st,ov;
int ha[NN],flag[NN],mr[NN],lc[NN],rc[NN];
int f[N],g[N],s[N];
int pow[N];
int v[N];
Edge e[N*2];int last[N];
int smaller(int i,int j,int l,int r)
{
	if (j==0) return 0;
	if (i==0) return 1;
	if (l==r) return ha[i]<ha[j];
	if (ha[j]==0) return 0;
	if (ha[i]==0) return 1;
	
	int mid=(l+r)>>1;
	
	if (ha[rc[i]]==ha[rc[j]]) return smaller(lc[i],lc[j],l,mid);
	return smaller(rc[i],rc[j],mid+1,r);
}
struct Heap
{
	int num;
	PII t[N];
	void push(PII a)
	{
		t[++num]=a;
		int j;
		for (int i=num;i>1;i=j)
		{
			j=i/2;
			if (smaller(t[i].FR,t[j].FR,0,R)) swap(t[j],t[i]);
				else break;
		}
	}
	PII top() { return t[1]; }
	void pop()
	{
		t[1]=t[num];num--;
		int j;
		for (int i=1;i*2<=num;i=j)
		{
			j=i*2;
			if (smaller(t[j+1].FR,t[j].FR,0,R)&&j<num) j++;
			if (smaller(t[j].FR,t[i].FR,0,R)) swap(t[i],t[j]);
				else break;
		}
	}
	int empty() { return num==0; }
};
Heap H;
void down(int i,int l,int r)
{
	if (flag[i])
	{
		int j=++num,k=++num;
		int mid=(l+r)>>1;
		lc[i]=j;rc[i]=k;
		ha[j]=ha[k]=0;
		flag[j]=flag[k]=1;
		mr[j]=l;mr[k]=mid+1;
		flag[i]=0;
	}
}
void update(int i,int l,int r)
{
	int j=lc[i],k=rc[i];
	int mid=(l+r)>>1;
	ha[i]=(1LL*ha[k]*pow[mid-l+1]+ha[j])%mo;
	mr[i]=min(mr[j],mr[k]);
}
int change1(int j,int l,int r,int k)
// 0 -> 1
{
	down(j,l,r);
	int i=++num;
	mr[i]=mr[j];ha[i]=ha[j];
	lc[i]=lc[j];rc[i]=rc[j];
	if (l==r)
	{
		flag[i]=0;
		ha[i]=1;mr[i]=R;
		return i;
	}
	int mid=(l+r)>>1;
	if (k<=mid) lc[i]=change1(lc[j],l,mid,k);
	if (k> mid) rc[i]=change1(rc[j],mid+1,r,k);
	update(i,l,r);
	return i;
}
int change2(int j,int l,int r,int ll,int rr)
// 1111 -> 0000
{
	down(j,l,r);
	int i=++num;
	mr[i]=mr[j];ha[i]=ha[j];
	lc[i]=lc[j];rc[i]=rc[j];
	if (ll<=l&&r<=rr)
	{
		flag[i]=1;
		ha[i]=0;mr[i]=l;
		return i;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) lc[i]=change2(lc[j],l,mid,ll,rr);
	if (rr> mid) rc[i]=change2(rc[j],mid+1,r,ll,rr);
	update(i,l,r);
	return i;
}
int query_nextzore(int i,int l,int r,int k)
{
	down(i,l,r);
	int mid=(l+r)>>1;
	if (l==r) return mr[i];
	int ans=R;
	if (k<=mid) ans=mr[rc[i]];
	if (k<=mid) ans=min(ans,query_nextzore(lc[i],l,mid,k));
	if (k> mid) ans=min(ans,query_nextzore(rc[i],mid+1,r,k));
	return ans;
}
void add(int x,int y,int z)
{
	num++;
	e[num]=(Edge){y,z,last[x]};
	last[x]=num;
}
int build(int l,int r)
{
	int i=++num;
	if (l==r)
	{
		mr[i]=l;ha[i]=0;flag[i]=0;
		return i;
	}
	int mid=(l+r)>>1;
	lc[i]=build(l,mid);
	rc[i]=build(mid+1,r);
	mr[i]=l;ha[i]=0;flag[i]=0;
	return i;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d%d",&n,&m);
	R=N+20;
	mr[0]=R;
	pow[0]=1;
	for (int i=1;i<=R;i++) pow[i]=2LL*pow[i-1]%mo;
	for (int i=1;i<=m;i++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	scanf("%d%d",&st,&ov);
	
	if (st==ov) { printf("%d\n%d\n%d\n",0,1,st);return 0;}
	
	f[1]=build(0,R);
	for (int i=2;i<=n;i++) f[i]=f[1];
	f[ov]=change1(f[ov],0,R,R);
	for (int i=1;i<=n;i++) if (i!=st) f[i]=f[ov]; 
	
	
	H.push(MP(0,st));
	while (!H.empty())
	{
		
		PII t=H.top();
		H.pop();
		if (v[t.SC]) continue;
		
//		printf("Work %d %d\n",t.SC,ha[t.FR]);
		v[t.SC]=1;
		for (int j=last[t.SC];j;j=e[j].ne)
		{
	//		if (v[e[j].y]) continue;
	//		printf("Relax %d --> %d\n",t.SC,e[j].y);
			
			int root=f[t.SC];
			int p=query_nextzore(root,0,R,e[j].z);
			root=change1(root,0,R,p);
			if (e[j].z<p)
				root=change2(root,0,R,e[j].z,p-1);
			if (smaller(root,f[e[j].y],0,R)) 
			{
				f[e[j].y]=root;
				g[e[j].y]=t.SC;
				H.push(MP(f[e[j].y],e[j].y));
			}
		}
	}
	if (!v[ov])	printf("-1\n");
	else
	{
		printf("%d\n",ha[f[ov]]);
		int k=0;
		for (int i=ov;i!=st;i=g[i])
			s[++k]=i;
		printf("%d\n%d",k+1,st);
		for (int i=k;i>=1;i--) printf(" %d",s[i]);
		printf(" \n");
	}
	return 0;
}