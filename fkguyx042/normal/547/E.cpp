#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ls Tree[t].l
#define rs Tree[t].r
#define Ls Tree[t1].l
#define Rs Tree[t1].r
#define mid ((l+r)>>1)
using namespace std;
vector<int>v[400005],color[400005];
struct Node{int trans[26],pre,step,ow;}sam[400005];
int i,j,m,n,p,k,E[400005],Q,tot,last,st[400005],ed[400005],start[400005],len[400005],zyb;
int root[400005],l,r,ans,G;
struct Tre{
	   int l,r,sum,id;
}Tree[7000005];
char c[200005],C[200005];
void push(int Dis) { sam[++tot].step=Dis;  }
void update(int ll,int l,int r,int t,int t1)
{
	  Tree[t].id=G;
	  if (l==r) Tree[t].sum++;
	  else 
	  {
	  	  if (ll<=mid)
	  	  { 
	  	       if (Tree[ls].id!=G) Tree[t].l=++zyb,Tree[zyb]=Tree[Ls];
	  	       update(ll,l,mid,ls,Ls);
	  	  }
	  	  else 
	  	  {
	  	  	   if (Tree[rs].id!=G) Tree[t].r=++zyb,Tree[zyb]=Tree[Rs];
	  	  	   update(ll,mid+1,r,rs,Rs);
	      }
	      Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
	  }
}
void ask(int ll,int rr,int l,int r,int t,int t1)
{
	  if (ll<=l&&r<=rr) ans+=Tree[t].sum-Tree[t1].sum;
	  else
	  {
	  	if (ll<=mid) ask(ll,rr,l,mid,ls,Ls);
	  	if (rr>mid)  ask(ll,rr,mid+1,r,rs,Rs);
      }
}
void dfs(int x)
{
  st[x]=++G;
  root[G]=++zyb;
  Tree[root[G]]=Tree[root[G-1]];
  int i;
  for (i=0;i<color[x].size();++i)
    update(color[x][i],1,n,root[G],root[G-1]);
  for (i=0;i<v[x].size();++i) 
     dfs(v[x][i]);
  ed[x]=G;
}
void Ins(int x)
{ 
   int p=sam[last].trans[x];
   if (p)
   {
           if (sam[last].step==sam[p].step-1) last=p;
           else
           {
                 push(sam[last].step+1);
                 int nq=tot;
                 sam[nq].pre=sam[p].pre;
                 sam[p].pre=nq;
                 memcpy(sam[nq].trans,sam[p].trans,sizeof(sam[p].trans));
                 for (;sam[last].trans[x]==p;last=sam[last].pre) sam[last].trans[x]=nq;
                 last=nq;
           }
   }
   else
   {
   push(sam[last].step+1);
   int p=last,np=tot;
   for (;p&&!sam[p].trans[x];p=sam[p].pre) sam[p].trans[x]=np;
   if (!p&&!sam[p].trans[x]) 
   sam[np].pre=0,sam[p].trans[x]=np;
   else
   {
          int q=sam[p].trans[x];
          if (sam[q].step!=sam[p].step+1)
          {
                 push(sam[p].step+1);
                 int nq=tot;
                 memcpy(sam[nq].trans,sam[q].trans,sizeof(sam[q].trans));
                 sam[nq].pre=sam[q].pre;
                 sam[q].pre=sam[np].pre=nq;
                 for (;sam[p].trans[x]==q;p=sam[p].pre) sam[p].trans[x]=nq;
          }  else sam[np].pre=q;
   }
   last=np;
   }
}
int main()
{
   scanf("%d%d",&n,&Q);
   for (i=1;i<=n;++i)
   {
         scanf("%s",&c); int Len=strlen(c);
         last=0; start[i]=start[i-1]+len[i-1];
         for (j=0;j<Len;++j) 
		 C[start[i]+j]=c[j],Ins(c[j]-'a');
         len[i]=Len;
   }
   for (i=1;i<=n;++i)
 {
     for (j=0,p=0;j<len[i];++j)
       {
           p=sam[p].trans[C[start[i]+j]-'a'];
           color[p].push_back(i);
       }
     E[i]=p;
 }
   for (i=1;i<=tot;++i) v[sam[i].pre].push_back(i);
   dfs(0);
   for (;Q--;)
   {
        scanf("%d%d%d",&l,&r,&k);
        ans=0;ask(l,r,1,n,root[ed[E[k]]],root[st[E[k]]-1]);
        printf("%d\n",ans);
   }
}