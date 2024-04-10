#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int x[4]={0,0,1,-1};
const int y[4]={1,-1,0,0};
int i,j,m,n,p,k,fox[2001][2001],k1,l,r,size[2001][2001],vis[2001][2001];
struct Node{int ed,before;}s[16000001];
char c[2001][2001],ans[2001][2001];
struct Nde{int x,y;}Q[4000001];
void add(int x,int y,int z)
 {s[++k1].ed=z; s[k1].before=fox[x][y]; fox[x][y]=k1; }
 bool check(int x,int y)
{  if (x<0||x>=n||y<0||y>=m) return false;
    if (c[x][y]=='*') return false;
    return true;
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=0;i<n;i++) 
  scanf("%s",&c[i]);
  for  (i=0;i<n;i++)
    for (j=0;j<m;j++) ans[i][j]=' ';
  for (i=0;i<n;i++)
   for (j=0;j<m;j++)
    if (c[i][j]=='*') ans[i][j]='*';
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      for (k=0;k<4;k++)
       if (c[i][j]!='*'&&check(i+x[k],j+y[k])) 
       add(i,j,k),size[i][j]++;
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      if (size[i][j]==1) Q[++r].x=i,Q[r].y=j;
  for (l=1;l<=r;l++)
  {
    int X=Q[l].x,Y=Q[l].y;
   if (vis[X][Y]) continue;
   vis[X][Y]=1;
   for (i=fox[X][Y];i;i=s[i].before)
       if (!vis[X+x[s[i].ed]][Y+y[s[i].ed]])
     {   int ap=X+x[s[i].ed],bp=Y+y[s[i].ed];
         vis[X+x[s[i].ed]][Y+y[s[i].ed]]=1;
         if (s[i].ed==0) ans[X][Y]='<',ans[X+x[s[i].ed]][Y+y[s[i].ed]]='>';
         else if (s[i].ed==1) ans[X][Y]='>',ans[X+x[s[i].ed]][Y+y[s[i].ed]]='<';
         else if (s[i].ed==2) ans[X][Y]='^',ans[X+x[s[i].ed]][Y+y[s[i].ed]]='v';
         else ans[X][Y]='v',ans[X+x[s[i].ed]][Y+y[s[i].ed]]='^';
         for (j=fox[ap][bp];j;j=s[j].before) 
         { 
            size[ap+x[s[j].ed]][bp+y[s[j].ed]]--; 
            if (size[ap+x[s[j].ed]][bp+y[s[j].ed]]==1) 
            Q[++r].x=ap+x[s[j].ed],Q[r].y=bp+y[s[j].ed];
         }
      }
   }
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      if (ans[i][j]==' ') { printf("Not unique\n");  return 0; }
  for (i=0;i<n;i++)
{ for (j=0;j<m;j++) printf("%c",ans[i][j]);
  printf("\n");
}            

}