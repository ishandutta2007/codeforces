#include<bits/stdc++.h>
#define N 505
using namespace std;
int a[N][N],del[N],f[N],s[N];
int rest,n,m,i,j,x,y,num,u,v;
int get(int u){
  if (f[u]==u) return u;
  int ret=get(f[u]);
  s[u]^=s[f[u]];
  return f[u]=ret;
}
void NO(){
  puts("NO");
  exit(0);
}
int main(){
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
    scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1;
  rest=n;
  while (rest){
    for (i=1;i<=n;i++)
      if (!del[i]){
        num=0;
        for (j=1;j<=n;j++)
          if (!del[j]&&a[i][j]) num++;
        if (num==rest-1) break;
      }
    if (i>n) break;
    del[i]=1;rest--;
  }
  for (i=1;i<=n;i++) f[i]=i,s[i]=0;
  for (i=1;i<=n;i++)
    if (!del[i])
      for (j=1;j<=n;j++)
        if (!del[j]){
          if (i==j) continue;
          u=get(i);v=get(j);
          if (u!=v) {
            f[u]=v;
            s[u]=s[i]^s[j]^(!a[i][j]);
            continue;
          }if ((s[i]==s[j])!=a[i][j]) NO();
        }
  puts("Yes");
  for (i=1;i<=n;i++)
    if (del[i]) putchar('b');
    else get(i),putchar(s[i]==0?'a':'c');
}