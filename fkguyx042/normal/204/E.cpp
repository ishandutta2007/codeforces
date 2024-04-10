#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
#define Maxn 300000
using namespace std;
int i,j,m,n,p,k,id[300005],L,len,l,r,Q[300005];
char s[300005],c[300005];
int high[300005],sa[300005],Rank[300005],tri[300005];
int Orz[300005],G[300005],ELen[300005],Lx[300005];
long long ans[300005];
int Tree[3000005];
int vis[300005],sum,lx,Ls,Rs;
void get_high()
{ 
       int i,j;
       for (i=1,j=0;i<=L;i++)
     { 
          if (Rank[i]==1) continue;
          while (s[i+j]==s[sa[Rank[i]-1]+j]) ++j;
          high[Rank[i]]=j; if (j) j--;
     }
}
void Sort(int j)
{  
       int i;      
      memset(Orz,0,sizeof(Orz));
      for (i=1;i<=L;i++) Orz[Rank[i+j]]++;
      for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
      for (i=L;i;i--) G[Orz[Rank[i+j]]--]=i;
      memset(Orz,0,sizeof(Orz));
      for (i=1;i<=L;i++) Orz[Rank[i]]++;
      for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
      for (i=L;i;i--)
      sa[Orz[Rank[G[i]]]--]=G[i];
}
void get_SA()
{ 
       int i;
       for (i=1;i<=L;i++) tri[i]=s[i];
       for (i=1;i<=L;i++) Orz[tri[i]]++;
       for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
       for (i=L;i;i--) sa[Orz[tri[i]]--]=i;
       Rank[sa[1]]=1;
       for (i=2,p=1;i<=L;i++)
{ 
          if (tri[sa[i]]!=tri[sa[i-1]]) ++p;
           Rank[sa[i]]=p;
}
   for (j=1;j<=L;j*=2)
  { 
         Sort(j);
         tri[sa[1]]=1;
         for (i=2,p=1;i<=L;i++)
        { 
                if (Rank[sa[i]]!=Rank[sa[i-1]]||Rank[sa[i]+j]!=Rank[sa[i-1]+j]) ++p;
                tri[sa[i]]=p;
        }
        memcpy(Rank,tri,sizeof(tri));
   }
}
int check(int x)
{  
   if (x==0||id[sa[x]]==0) return 0;
   if (vis[id[sa[x]]]==1) return 1;
   return 0;
}
void del(int &x)
{
	  vis[id[sa[x]]]--;
	  if (id[sa[x]]&&!vis[id[sa[x]]]) sum--;
	  x++;
}
int ask(int ll,int rr,int c,int l,int r,int t)
{
	  if (l==r) {  Ls=l; return true; }
	  else if (ll<=l&&r<=rr)
	  {
	  	    if (Tree[rs]<c) ask(ll,rr,c,mid+1,r,rs);
	  	    else ask(ll,rr,c,l,mid,ls);
	  	    return true;
	  }
	  else {
	  	    if (rr>mid&&Tree[rs]<c)
	  	    {
	  	    	  if (ask(ll,rr,c,mid+1,r,rs)) return true;
	  	    }
	  	    if (ll<=mid&&Tree[ls]<c) 
	  	    {
	  	    	  if (ask(ll,rr,c,l,mid,ls)) return true;
	  	    }
	  	return false;
	  }
}
int Query(int ll,int rr,int c,int l,int r,int t)
{
	  if (l==r) {  Rs=l; return true; }
	  else if (ll<=l&&r<=rr)
	  {
	  	    if (Tree[ls]<c) Query(ll,rr,c,l,mid,ls);
	  	    else Query(ll,rr,c,mid+1,r,rs);
	  	    return true;
	  }
	  else {
	  	     if (ll<=mid&&Tree[ls]<c) 
	  	    {
	  	    	  if (Query(ll,rr,c,l,mid,ls)) return true;
	  	    }
	  	      if (rr>mid&&Tree[rs]<c)
	  	    {
	  	    	  if (Query(ll,rr,c,mid+1,r,rs)) return true;
	  	    }
	  	return false;
	  }
}
void build_tree(int l,int r,int t)
{ 
  if(l==r) Tree[t]=high[l];
  else build_tree(l,mid,ls),build_tree(mid+1,r,rs),
  Tree[t]=min(Tree[ls],Tree[rs]);
}
int main()
{
//	  freopen("string.in","r",stdin);
//	  freopen("string.out","w",stdout); 
      scanf("%d%d",&n,&k);
      for (i=1;i<=n;i++)
  {
       scanf("%s",c);
       len=strlen(c);
       if (k==1) printf("%I64d ",1ll*len*(len+1)/2ll);
       for (j=0;j<len;j++) s[++L]=c[j],id[L]=i;
       ELen[i]=L;
       s[++L]='$';
  }
  l=1,r=0;
  if (k!=1)
{ 
     get_SA();
     get_high();
     lx=0;
     for (i=1;i<=L;i++)
     {
     	  vis[id[sa[i]]]++;
     	  if (id[sa[i]]&&vis[id[sa[i]]]==1)  
		   sum++;
		   while (sum-check(lx)>=k) 
		   del(lx);
     	  Lx[i]=lx;
     }
     build_tree(1,L,1);
      for (i=1;i<=L;i++)
      if (id[sa[i]])
	 { 
	      int LL=0,RR=ELen[id[sa[i]]]+1,Mid=0;
		  for (;(LL+RR)>>1!=Mid;)
		  { 
		      Mid=(LL+RR)>>1;
		      Ls=1;
		      ask(1,i,Mid,1,L,1);
		      Rs=L+1;
		      if(i+1<=L)
		      Query(i+1,L,Mid,1,L,1);
		      Rs--;
		      if (Ls>Rs) RR=Mid;
		       else {
		                 if (Lx[Rs]>=Ls) LL=Mid;
		                 else RR=Mid;
		            }
		  }
        ans[id[sa[i]]]+=min(LL,ELen[id[sa[i]]]-sa[i]+1);	        
     }
for (i=1;i<=n;i++) printf("%I64d ",ans[i]);
}
}