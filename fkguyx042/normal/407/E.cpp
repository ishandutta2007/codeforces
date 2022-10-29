#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
struct Tre{int max1,max2,sum,Minadd,Maxadd,ad,add,l,r;}Tree[1000005];
int i,j,m,n,p,k,d,a[200005],b[200005],c[200005],r[200005],R_Max[200005],R_Min[200005];
int anslen,ansl,ansr,l,L,goal;
map<int,int>mp;
void up_min(Tre &x,int y)
{
   x.ad=1; x.Minadd=y;
   x.sum=x.max1-y;
   x.max2=-y-x.r;
}
void up_max(Tre &x,int y)
{
   x.add=1; x.Maxadd=y;
   x.sum=x.max2+y;
   x.max1=y-x.r;
}
void down(int t)
{
      if (Tree[t].ad) up_min(Tree[ls],Tree[t].Minadd),up_min(Tree[rs],Tree[t].Minadd);
      if (Tree[t].add) up_max(Tree[ls],Tree[t].Maxadd),up_max(Tree[rs],Tree[t].Maxadd);
      Tree[t].ad=Tree[t].add=0;
}
int ask(int ll,int rr,int l,int r,int t)
{
     if (Tree[t].sum>goal) return 0;
     if (l==r) { L=l; return 1; }
     down(t);
     if (ll<=l&&r<=rr) return ask(ll,rr,mid+1,r,rs)||ask(ll,rr,l,mid,ls);
     if (rr>mid&&ask(ll,rr,mid+1,r,rs)) return 1;
     if (ll<=mid&&ask(ll,rr,l,mid,ls)) return 1;
     return 0;
}
void cheat()
{
      for (i=1;i<=n;i=j)
      {
            for (j=i;j<=n&&a[i]==a[j];++j);
            if (anslen<j-i)
            {
               anslen=j-i;
               ansl=i;
               ansr=j-1;
            }
      }
      printf("%d %d\n",ansl,ansr);
}
void charge(int ll,int l,int r,int t)
{ 
     if (l==r)
     {
              Tree[t].max1=b[l]-l;
              Tree[t].max2=-b[l]-l;
              Tree[t].sum=-l;
     }
     else 
     {
           down(t);
           if (ll<=mid) charge(ll,l,mid,ls); else charge(ll,mid+1,r,rs);
           Tree[t].max1=min(Tree[ls].max1,Tree[rs].max1);
           Tree[t].max2=min(Tree[ls].max2,Tree[rs].max2);
           Tree[t].sum=min(Tree[ls].sum,Tree[rs].sum);
     }
}
void change_Min(int ll,int rr,int c,int l,int r,int t)
{
       if (ll<=l&&r<=rr) up_min(Tree[t],c);
       else 
       {
             down(t);
             if (ll<=mid) change_Min(ll,rr,c,l,mid,ls);
             if (rr>mid)  change_Min(ll,rr,c,mid+1,r,rs);
             Tree[t].max1=min(Tree[ls].max1,Tree[rs].max1);
             Tree[t].max2=min(Tree[ls].max2,Tree[rs].max2);
             Tree[t].sum=min(Tree[ls].sum,Tree[rs].sum);
       }
}
void change_Max(int ll,int rr,int c,int l,int r,int t)
{
      if (ll<=l&&r<=rr) up_max(Tree[t],c);
       else 
       {
             down(t);
             if (ll<=mid) change_Max(ll,rr,c,l,mid,ls);
             if (rr>mid)  change_Max(ll,rr,c,mid+1,r,rs);
             Tree[t].max1=min(Tree[ls].max1,Tree[rs].max1);
             Tree[t].max2=min(Tree[ls].max2,Tree[rs].max2);
             Tree[t].sum=min(Tree[ls].sum,Tree[rs].sum);
       }
}
void build_tree(int l,int r,int t)
{
      Tree[t].l=l; Tree[t].r=r;
      if (l==r) return;
      build_tree(l,mid,ls); build_tree(mid+1,r,rs);
}
int main()
{
     scanf("%d%d%d",&n,&k,&d);
     for (i=1;i<=n;++i) scanf("%d",&a[i]);
     if (!d) cheat();
     else 
     {
          for (i=1;i<=n;++i) 
          {
            b[i]=a[i]/d,c[i]=a[i]%d;
            if (c[i]<0) c[i]+=d;
          } 
          r[n]=n+1; mp[a[n]]=n;
          for (i=n-1;i;--i)
          {
            if (c[i]!=c[i+1]) r[i]=i+1;
            else  
            {
                 r[i]=r[i+1];
                 if (mp[a[i]]) r[i]=min(r[i],mp[a[i]]);
            }
            mp[a[i]]=i;
          }
          for (i=n;i;--i)
          {
               R_Max[i]=R_Min[i]=i+1;
               while (R_Max[i]<=n&&b[R_Max[i]]<b[i]) R_Max[i]=R_Max[R_Max[i]];
               while (R_Min[i]<=n&&b[R_Min[i]]>b[i]) R_Min[i]=R_Min[R_Min[i]];
          }
          build_tree(1,n,1);
          for (i=n;i;--i)
          {
            charge(i,1,n,1); goal=k-i;
            change_Min(i,R_Min[i]-1,b[i],1,n,1);
            change_Max(i,R_Max[i]-1,b[i],1,n,1);
            ask(i,r[i]-1,1,n,1);
            if (L-i+1>=anslen)
            {
                                anslen=L-i+1;
                                ansl=i;
                                ansr=L;
            }
          }
          printf("%d %d\n",ansl,ansr);
       }
}