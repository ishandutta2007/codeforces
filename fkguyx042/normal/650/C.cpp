#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,h[N],l[N],x,tot,top,P[N],id[N],L;
struct Node{int x,px,py;}Q[N],Ans[N];
inline bool cmp(Node a,Node b) { return a.x<b.x; }
inline bool cmp1(int a,int b) { return P[a]>P[b]; }
inline bool Cmp(Node a,Node b) { if (a.px!=b.px) return a.px<b.px; return a.py<b.py; }
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i)
	  for (j=1;j<=m;++j)
	  {
	  	  scanf("%d",&x);
	  	  Q[++tot]=(Node){x,i,j};
	  }
	sort(Q+1,Q+tot+1,cmp);
	for (i=1;i<=tot;i=j)
	{
		 for (j=i;j<=tot&&Q[j].x==Q[i].x;++j);
		 for (k=i;k<j;++k)
		 	P[k]=max(h[Q[k].px],l[Q[k].py])+1;
		 for (k=i;k<j;++k) 
		    id[k]=k;
		 for (L=1;L<=20;++L)
		{ 
		 sort(id+i,id+j,cmp1);
		 for (k=i;k<j;++k)
		 {
		 	  p=id[k];
		 	  P[p]=max(P[p],max(h[Q[p].px],l[Q[p].py]));
//		 	  Ans[++top]=(Node){P[p],Q[p].px,Q[p].py};
		 	  h[Q[p].px]=P[p],l[Q[p].py]=P[p];
		 }
	    }
		 sort(id+i,id+j,cmp1);
		 for (k=i;k<j;++k)
		 {
		 	  p=id[k];
		 	  P[p]=max(P[p],max(h[Q[p].px],l[Q[p].py]));
		 	  Ans[++top]=(Node){P[p],Q[p].px,Q[p].py};
		 	  h[Q[p].px]=P[p],l[Q[p].py]=P[p];
		 }
	}
	sort(Ans+1,Ans+tot+1,Cmp);
	for (i=1;i<=tot;++i)
	{ 
	      if (i>1&&Ans[i].px!=Ans[i-1].px) puts("");
		  printf("%d ",Ans[i].x);
	}
}