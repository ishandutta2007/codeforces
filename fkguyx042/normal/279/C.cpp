#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,st,ed,l,r,mid;
int a[100001],inc[100001],dec[100001];
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) {
    scanf("%d",&a[i]);
    if (a[i]>=a[i-1]) inc[i]=inc[i-1]+1; else inc[i]=inc[i-1]-1;
    if (a[i]<=a[i-1]) dec[i]=dec[i-1]+1; else dec[i]=dec[i-1]-1;
}
 for (i=1;i<=m;i++)
 { scanf("%d%d",&st,&ed);
   l=st; r=ed+1; mid=0;
   for (;(l+r)>>1!=mid;) 
   { mid=(l+r)>>1;
    if (inc[mid]-inc[st]<mid-st) r=mid; else l=mid;
   }
   if (dec[ed]-dec[mid]==ed-mid) printf("Yes\n"); else printf("No\n");
}
}