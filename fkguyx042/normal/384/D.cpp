#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,cnt,all,Nurse_ZYB,f;
struct Node{int x,y;};
Node Now[100001],doit[100001],a[100001];
inline bool cmp(Node a,Node b) { if (a.y!=b.y) return a.y<b.y; return a.x<b.x; }
int main()
{ for (;scanf("%d%d",&n,&m)!=EOF;)
{   cnt=all=0; f=1;
  for (i=1;i<=m;i++)
   scanf("%d%d",&a[i].x,&a[i].y);
  sort(a+1,a+m+1,cmp);
  Now[++cnt].x=1; Now[cnt].y=1;
  for (i=1;i<=m;i++)
   {    if (a[i].y!=a[i-1].y+1) {  cnt=1; Now[cnt].y=n; }
      for (k=i+1;k<=m&&a[i].y==a[k].y;k++); --k;Nurse_ZYB=all=0;
    for (j=i;i<=k;i++){if (a[i].x>Nurse_ZYB+1){  doit[++all].x=Nurse_ZYB+1; doit[all].y=a[i].x-1;};Nurse_ZYB=a[i].x; }
    if (n>Nurse_ZYB) doit[++all].x=Nurse_ZYB+1,doit[all].y=n;
    int tail=1;
    for (j=1;j<=cnt;j++) {
     while (tail<=all&&doit[tail].x<=Now[j].y)
    {   if (doit[tail].y>=Now[j].x) doit[tail].x=max(doit[tail].x,Now[j].x); else doit[tail].x=doit[tail].y=-1; tail++; }
    if (tail>all) break; } cnt=0;
    for (j=1;j<tail;j++)
    if (doit[j].x!=-1)  Now[++cnt]=doit[j]; 
    if (!cnt) { f=0; break; }
    i=k;
}
  if (!f) { printf("-1\n"); continue; }
  if (Now[cnt].y==n||a[m].y!=n) printf("%d\n",2*n-2);
  else printf("-1\n");
}
}