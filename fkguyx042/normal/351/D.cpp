#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set> 
#define ls Tree[t].l
#define Ls Tree[t1].l
#define rs Tree[t].r
#define Rs Tree[t1].r
#define mid ((l+r)>>1)
using namespace std;
multiset<int>st;
struct Node{int l,r,id;}Q[1000005];
int i,j,m,n,p,k,Last[500005],LLast[500005],q,a[500005],tot,root[500005],Ans[500005];
int LA[5000005],Can[5000005],Sum[500005],su,Te[1000005];
struct Tre{int l,r,sum,id;}Tree[10000005];
inline bool cmp(Node a,Node b) {return a.r<b.r;}
void update(int ll,int c,int l,int r,int t,int t1)
{
	 Tree[t].id=i;
	 if (l==r) Tree[t].sum+=c;
	 else 
	 {
			 if (ll<=mid) 
			 {
					  if (Tree[ls].id!=i) ls=++tot,Tree[ls]=Tree[Ls];
					  update(ll,c,l,mid,ls,Ls);
			}
			else 
			{
				      if (Tree[rs].id!=i) rs=++tot,Tree[rs]=Tree[Rs];
				      update(ll,c,mid+1,r,rs,Rs);
			}
			Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
	}
}
void ask(int &x,int ll,int rr,int l,int r,int t)
{
	 if (!t) return;
	 if (ll<=l&&r<=rr) x+=Tree[t].sum;
	 else 
	 {
			 if (ll<=mid) ask(x,ll,rr,l,mid,ls);
			 if (rr>mid)  ask(x,ll,rr,mid+1,r,rs);
	 }
}
inline bool Cmp(Node a,Node b)
{
	 return a.l>b.l;
}
void change(int ll,int c,int l,int r,int t)
{
	 if (l==r) Te[t]=c;
	 else 
	 {
			  if (ll<=mid) change(ll,c,l,mid,(t<<1));
			  else         change(ll,c,mid+1,r,(t<<1)+1);
			  Te[t]=max(Te[(t<<1)],Te[(t<<1)+1]);
	 }
}
void Query(int ll,int rr,int l,int r,int t)
{ 
	 if (ll<=l&&r<=rr) su=max(su,Te[t]);
	 else 
	 {
			 if (ll<=mid) Query(ll,rr,l,mid,t<<1);
			 if (rr>mid)  Query(ll,rr,mid+1,r,(t<<1)+1);
	 }
}
void pre()
{
	 memset(Last,0,sizeof(Last));
	 int L=1;
	 sort(Q+1,Q+q+1,Cmp);
	 for (i=n;i;--i)
	 {
			  if (!Last[a[i]]) change(i,n+1,1,n,1),Sum[a[i]]=n+1;
			  else  
			  {
					  change(Last[a[i]],-1,1,n,1);
					  if (!LLast[a[i]]) change(i,n+1,1,n,1);
			          else 
			          {
							if (LLast[a[i]]-Last[a[i]]!=Last[a[i]]-i) Sum[a[i]]=LLast[a[i]];
					  change(i,Sum[a[i]],1,n,1);
					  }
			 }
		     LLast[a[i]]=Last[a[i]]; Last[a[i]]=i;
		   while (L<=q&&Q[L].l==i)
		  {
				su=0;
				Query(Q[L].l,Q[L].r,1,n,1);
				if (su<=Q[L].r) Ans[Q[L].id]++;
				++L; 
		 }
    }
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("%d",&q);
	for (i=1;i<=q;++i) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
	sort(Q+1,Q+q+1,cmp);
	int L=1;
	for (i=1;i<=n;++i)
  {
		  root[i]=++tot;
		  Tree[root[i]]=Tree[root[i-1]];
		  update(i,1,1,n,root[i],root[i-1]);
		  if (Last[a[i]]) update(Last[a[i]],-1,1,n,root[i],root[i-1]);
          Last[a[i]]=i;
		  while (L<=q&&Q[L].r==i) ask(Ans[Q[L].id],Q[L].l,Q[L].r,1,n,root[i]),++L;
 }
 pre();
 for (i=1;i<=q;++i) printf("%d\n",Ans[i]);
}