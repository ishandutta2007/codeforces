#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
/*int i,j,m,n,p,k,tot,ans;
int a[26],b[26][26],d[26][26][26];
int Que[26];
char c[5];
int Got(int x)
{  Que[++tot]=x;
   int ans=0; ans+=a[x];
   for (i=1;i<tot;i++) ans-=b[Que[i]][x];
   for (i=1;i<tot-1;i++)
     for (j=i+1;j<tot;j++)
     ans+=d[Que[i]][Que[j]][x];
    return ans;
}
void dfs(int x,int sum)
{  if (x==24) { ans^=sum; return; }
   dfs(x+1,sum);
    dfs(x+1,sum+Got(x));
    tot--;
}
void Do()
{ int i,j;
  for (i=1;i<3;i++) 
    for (j=i+1;j<=3;j++)
     if (c[i-1]>c[j-1]) swap(c[i-1],c[j-1]);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
     { scanf("%s",&c);
       Do();
       a[c[0]-'a']++; a[c[1]-'a']++; a[c[2]-'a']++;
       b[c[0]-'a'][c[1]-'a']++; b[c[0]-'a'][c[2]-'a']++; b[c[1]-'a'][c[2]-'a']++;
       d[c[0]-'a'][c[1]-'a'][c[2]-'a']++;
}
dfs(0,0);
printf("%d\n",ans);
}*/ 
const int Maxn=1<<24;
int i,j,m,n,p,k;
int f[Maxn];
char c[5];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
  {  scanf("%s",&c);
     int x=c[0]-'a';
     int y=c[1]-'a';
     int z=c[2]-'a';
     f[1<<x]++; f[1<<y]++; f[1<<z]++;
     f[(1<<x)|(1<<y)]--; f[(1<<x)|(1<<z)]--; f[(1<<y)|(1<<z)]--;
     f[(1<<x)|(1<<y)|(1<<z)]++;
}
for (j=0;j<24;j++)
for (i=Maxn-1;i;i--)
if (i&(1<<j)) f[i]+=f[i-(1<<j)];
int ans=0;
for (i=0;i<Maxn;i++) ans^=f[i]*f[i];
printf("%d\n",ans);
}