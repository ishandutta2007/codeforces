#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int id[100005],Id[100005],MaxQ[100005],MinQ[100005],l=0,a[100005],MinL,MinR,f[100005];
int MaxL,MaxR,len,s,n,i,j,p,k,m,ans;
int tree[500005];
void ins(int c,int ll,int l,int r,int t)
{ 
    if (l==r) tree[t]=c;
    else { 
          if (ll<=mid) ins(c,ll,l,mid,ls);
          else ins(c,ll,mid+1,r,rs);
          tree[t]=min(tree[ls],tree[rs]);
      }
}
void ask(int ll,int rr,int l,int r,int t)
{
	  if(ll<=l&&r<=rr) ans=min(ans,tree[t]);
	  else { 
	         if (ll<=mid) ask(ll,rr,l,mid,ls);
	         if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	     }
}
void insert(int x)
{
	   while (a[x]<=a[MinQ[MinR]]&&MinL<=MinR) MinR--;
	   MinQ[++MinR]=x;
	    while (a[x]>=a[MaxQ[MaxR]]&&MaxL<=MaxR) MaxR--;
	   MaxQ[++MaxR]=x;
}
bool check()
{
	   while (MinQ[MinL]<l) MinL++;
	   while (MaxQ[MaxL]<l) MaxL++;
	   if (a[MaxQ[MaxL]]-a[MinQ[MinL]]<=s) return true;
	   return false;
}
int main()
{
	 scanf("%d%d%d",&n,&s,&len);
	  memset(f,60,sizeof(f));
	  memset(tree,60,sizeof(tree));
	  f[0]=0;
	  MaxL=MinL=1;
	  MinR=MaxR=0;
	  l=1;
	  ins(0,0,0,n,1);
	 for (i=1;i<=n;i++) scanf("%d",&a[i]);
	 for (i=1;i<=n;i++)
	 {  
	   insert(i);
	     while (!check()) l++;
	   int askl=l-1,askr=i-len;
	   if (l-1<=i-len)
	   { 
	     ans=(int)1e9;
	     ask(askl,askr,0,n,1);
	     f[i]=ans+1;
	     ins(f[i],i,0,n,1);
	   }
 }
 if (f[n]<(int)1e9)
printf("%d\n",f[n]); else printf("-1\n");
}