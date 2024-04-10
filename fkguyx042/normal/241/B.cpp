#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls(x) Tree[x].l
#define rs(x) Tree[x].r
using namespace std;
const int Mo=(int)1e9+7;
int i,j,n,p,k,a[50001],root[50001],tot,z[32],A,B,syc[32],y,hhd[32],Ans;
long long m,P;
struct Node{int l,r,sum,Last[32];}Tree[1800001];
void up(int x)
{  int i,j; 
    memset(z,0,sizeof(z));
    for (y=a[x];y;y>>=1) z[++z[0]]=y&1;
    Tree[root[x]]=Tree[root[x-1]];
    A=root[x]; B=root[x-1];
    for (i=31;i;i--)
    {  Tree[A].sum++;
       for (j=1;j<=31;j++) 
       if (z[j]==0)
	   Tree[A].Last[j]++;
       if (z[i]&1)
       {   Tree[++tot]=Tree[rs(B)];
           rs(A)=tot;
           
           A=rs(A);
           B=rs(B);
       }
       else { 
            Tree[++tot]=Tree[ls(B)];
            ls(A)=tot;
            A=ls(A);
            B=ls(B);
       }
       }
        for (j=1;j<=31;j++) 
        if (z[j]==0)
		Tree[A].Last[j]++;
      Tree[A].sum++; 
}
bool check(int x)
{ int i,j; memset(syc,0,sizeof(syc));
           for (y=x;y;y>>=1) syc[++syc[0]]=y&1; 
  long long ans=0;
   for (i=2;i<=n;i++)
   {
    memset(z,0,sizeof(z));
    for (y=a[i];y;y>>=1) z[++z[0]]=y&1;
    A=root[i-1];  
    for (j=31;j;j--)
    if (syc[j]==1)
    {      A=(z[j]==0)?rs(A):ls(A); }
    else {
             ans+=(z[j]==0)?Tree[rs(A)].sum:Tree[ls(A)].sum;
             A=(z[j]==0)?ls(A):rs(A);
        }
    ans+=Tree[A].sum;
}
  P=ans;
   return ans>=m;
}
void Asksum(int x)
{  memset(z,0,sizeof(z)); 
   for (;x;x>>=1) z[++z[0]]=x&1;
   A=root[i-1];
   for (j=31;j;j--)
   if (syc[j]==1)
    {      A=(z[j]==0)?rs(A):ls(A); }
   else {   if (z[j]==0)  { 
                  for (k=1;k<=31;k++) {
                   ( Ans+=1ll*hhd[k]*(z[k]^0)%Mo*Tree[rs(A)].Last[k]%Mo)%=Mo;
                   ( Ans+=1ll*hhd[k]*(z[k]^1)%Mo*(Tree[rs(A)].sum-Tree[rs(A)].Last[k])%Mo)%=Mo; }
                    A=ls(A);
        }
        else {     for (k=1;k<=31;k++) {
        	 ( Ans+=1ll*hhd[k]*(z[k]^0)%Mo*Tree[ls(A)].Last[k]%Mo)%=Mo;
                   ( Ans+=1ll*hhd[k]*(z[k]^1)%Mo*(Tree[ls(A)].sum-Tree[ls(A)].Last[k])%Mo)%=Mo; }
                    A=rs(A); }
    }
}
int main()
{ scanf("%d%I64d",&n,&m);
  if(m==0) {printf("0\n"); return 0;}
  hhd[1]=1;
  for (i=2;i<=31;i++) hhd[i]=hhd[i-1]*2; 
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++) root[i]=++tot,up(i);
  long long l=0,r=(1ll<<31ll),mid;
  for (;(l+r)/2ll!=mid;)
{ mid=(l+r)/2ll;
   if (check((int)mid)) l=mid;
   else r=mid;
}
check(l+1);
Ans+=1ll*(m-P)%Mo*l%Mo;
memset(syc,0,sizeof(syc));
for (;l;l>>=1) syc[++syc[0]]=l&1;
for (i=2;i<=n;i++)  Asksum(a[i]);
printf("%d\n",Ans);
}