#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
const int INF=(int)1e9;
struct Node{int l,r;}Last[21];
struct Tre{int max,lmax,rmax,maxl,maxr,Lmax,Rmax,min,lmin,rmin,minl,minr,Lmin,Rmin,add,sum;}Tree[400001];
int i,j,m,n,p,k,l,r,tot,Max,ans,a[100001],type,x,L,R,val,T,Fmax,FL;
void up(Tre &a,Tre b,Tre c)
{  //For Max----------------------------------------
     if (b.rmax+c.lmax>b.max)
    {    if (b.rmax+c.lmax>c.max)
         {   a.max=b.rmax+c.lmax;
             a.maxl=b.Rmax; a.maxr=c.Lmax;
         }
         else {   a.max=c.max;
                  a.maxl=c.maxl; a.maxr=c.maxr;
              }
    }
    else {
    	    a=(b.max>c.max)?b:c;
    }
    if (b.sum+c.lmax>b.lmax)
    {   a.lmax=b.sum+c.lmax;
        a.Lmax=c.Lmax; 
    }
    else { a.lmax=b.lmax; a.Lmax=b.Lmax; }
    if (c.sum+b.rmax>c.rmax)
    {    a.rmax=c.sum+b.rmax;
         a.Rmax=b.Rmax;
    }
    else {  a.rmax=c.rmax;
            a.Rmax=c.Rmax;
         }
 //For Min---------------------------------   
      if (b.rmin+c.lmin<b.min)
    {    if (b.rmin+c.lmin<c.min)
         {   a.min=b.rmin+c.lmin;
             a.minl=b.Rmin; a.minr=c.Lmin;
         }
         else {   a.min=c.min;
                  a.minl=c.minl; a.minr=c.minr;
              }
    }
    else {  if (b.min<c.min)  
            {   a.min=b.min;
                a.minl=b.minl;
                a.minr=b.minr;
            }
            else 
            {   a.min=c.min;
                a.minl=c.minl;
                a.minr=c.minr;
            }
    }
    if (b.sum+c.lmin<b.lmin)
    {   a.lmin=b.sum+c.lmin;
        a.Lmin=c.Lmin; 
    }
    else { a.lmin=b.lmin; a.Lmin=b.Lmin; }
    if (c.sum+b.rmin<c.rmin)
    {    a.rmin=c.sum+b.rmin;
         a.Rmin=b.Rmin;
    }
    else {  a.rmin=c.rmin;
            a.Rmin=c.Rmin;
         }
// For sum------------------------
a.sum=b.sum+c.sum;
a.add=0;
}
//For seg. down
void Go(int t)
{     Tree[t].add^=1; Tree[t].sum=-Tree[t].sum;
      T=Tree[t].max; Tree[t].max=-Tree[t].min; Tree[t].min=-T;
      T=Tree[t].lmax;Tree[t].lmax=-Tree[t].lmin; Tree[t].lmin=-T;
      T=Tree[t].rmax;Tree[t].rmax=-Tree[t].rmin; Tree[t].rmin=-T;
      swap(Tree[t].maxl,Tree[t].minl); swap(Tree[t].maxr,Tree[t].minr);
      swap(Tree[t].Lmax,Tree[t].Lmin); swap(Tree[t].Rmax,Tree[t].Rmin);
}
void down(int t)
{  if (!Tree[t].add) return;
   Go(ls);Go(rs);
   Tree[t].add^=1;
}
//For Changing A[i]=x;
void update(int ll,int x,int l,int r,int t)
{   if (l==r) Tree[t].max=Tree[t].lmax=Tree[t].rmax=Tree[t].min=Tree[t].lmin=Tree[t].rmin=Tree[t].sum=x;
    else  { 
    	   down(t);
    	   if (ll<=mid) update(ll,x,l,mid,ls);
    	   else update(ll,x,mid+1,r,rs);
    	   up(Tree[t],Tree[ls],Tree[rs]);
          }
}
//For Change + to -  --------------------------------------------------
void Change(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr)  Go(t); 
   else {  down(t);
           if (ll<=mid) Change(ll,rr,l,mid,ls);
		   if (rr>mid)  Change(ll,rr,mid+1,r,rs);
		   up(Tree[t],Tree[ls],Tree[rs]);
	    }
}
//Build----------------------------------------------------------------
void build_tree(int l,int r,int t)
{   if (l==1&&r==3) 
    l=1;
    if(l==r) {
	  Tree[t].max=Tree[t].lmax=Tree[t].rmax=Tree[t].lmin=Tree[t].rmin=Tree[t].max=Tree[t].min=Tree[t].sum=a[l];
	  Tree[t].Lmax=Tree[t].Rmax=Tree[t].maxl=Tree[t].maxr=Tree[t].minl=Tree[t].minr=Tree[t].Lmin=Tree[t].Rmin=l;
  }
  else {
  build_tree(l,mid,ls);
  build_tree(mid+1,r,rs);
  up(Tree[t],Tree[ls],Tree[rs]);
}
}
//Just For ask---------------------------------------------------------
void Todo(Tre a)
{   
//From the right high
if (Fmax+a.lmax>Max)
{  Max=Fmax+a.lmax; 
   L=FL;
   R=a.Lmax;
}
//From the seg. high---------------------------------------------------
if (a.max>Max)
{  Max=a.max;
   L=a.maxl;
   R=a.maxr;
}
//For the Fmax(To right)-----------------------------------------------
    if (a.rmax>Fmax+a.sum)
   {    Fmax=a.rmax;
        FL=a.Rmax;
   }
   else Fmax+=a.sum;
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) Todo(Tree[t]);
   else { down(t);
   	  if(ll<=mid) ask(ll,rr,l,mid,ls);
   	  if (rr>mid) ask(ll,rr,mid+1,r,rs);
   }
}
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 build_tree(1,n,1);
 scanf("%d",&m);
 for (;m--;)
 {scanf("%d",&type);
  if (!type)
  {scanf("%d%d",&x,&val);
   update(x,val,1,n,1);
}
 else {
 	scanf("%d%d%d",&l,&r,&k); tot=ans=0;
 	for (i=1;i<=k;i++)
 	{ Max=-INF; Fmax=-INF; ask(l,r,1,n,1);
 	  if (Max<=0) break;
 	  ans+=Max;
 	  Change(L,R,1,n,1);
 	  tot++;
 	  Last[tot].l=L;
 	  Last[tot].r=R;
    }
    printf("%d\n",ans);
    for (i=1;i<=tot;i++) Change(Last[i].l,Last[i].r,1,n,1);
    }
}
}