#include<cstdio>
#include<algorithm>
using namespace std;
int f[5],G[5],now,i,k,T,t,n,flag;
char s[100005];
inline int C(char ch)
{
  if (ch=='?') return 0;
  if (ch=='G') return 1;
  if (ch=='H') return 2;
  if (ch=='R') return 3;
  if (ch=='S') return 4;
}
inline int count()
{
  int id=0;
  for (int i=1;i<=4;i++)
    if (f[i]<f[id]||f[i]==f[id]&&id==now)
      id=i;
  return id;
}
inline void write(int x)
{
  if (x==1) puts("Gryffindor");
  if (x==2) puts("Hufflepuff");
  if (x==3) puts("Ravenclaw");
  if (x==4) puts("Slytherin");
}
inline void dfs(int k,int G,int H,int R,int S)
{
  if (k>n)
  {
    if (G<=H&&G<=R&&G<=S) f[1]=1;
    if (H<=G&&H<=R&&H<=S) f[2]=1;
    if (R<=G&&R<=H&&R<=S) f[3]=1;
    if (S<=G&&S<=H&&S<=R) f[4]=1;
    return;
  }
  int now=C(s[k]);
  if (now) dfs(k+1,G+(now==1),H+(now==2),R+(now==3),S+(now==4));
  else
  {
    if (G<=H&&G<=R&&G<=S) dfs(k+1,G+1,H,R,S);
    if (H<=G&&H<=R&&H<=S) dfs(k+1,G,H+1,R,S);
    if (R<=G&&R<=H&&R<=S) dfs(k+1,G,H,R+1,S);
    if (S<=G&&S<=H&&S<=R) dfs(k+1,G,H,R,S+1);
  }
}
void force()
{
  f[1]=f[2]=f[3]=f[4]=0;
  dfs(1,0,0,0,0);
  for (i=1;i<=4;i++)
    if (f[i]) write(i);
  if (t<T) puts("");
}
int check()
{
  for (int i=1;i<=n;i++) if (s[i]!='?') return 0;
  for (int i=1;i<=4;i++) write(i);
  if (t<T) puts("");return 1;
}
inline int ok(int now)
{
  int sum=1;
  G[1]=1;G[2]=2;G[3]=3;G[4]=4;
  while (sum<24)
  {
    f[1]=f[2]=f[3]=f[4]=0;
    for (int i=1;i<=n;i++)
    {
      int k=G[C(s[i])];
      if (k) f[k]++;
      else f[count()]++;
    }
    int pp=G[now],flag=1;
    for (int i=1;i<=4;i++)
      if (i!=pp&&f[i]<f[pp]) flag=0;
    if (flag) return 1;
    next_permutation(G+1,G+5);sum++;
  }
  return 0;
}
int main()
{
  f[0]=1000000;
  scanf("%d",&n);
  scanf("%s",s+1);
  if (check()) return 0;
  if (n<=20) {force();return 0;}
  for (now=1;now<=4;now++)
    if (ok(now)) write(now);
  return 0;
}