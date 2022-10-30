#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,d[100002],fox[100002],k1,Fox[100002],size[100002],K,ans;
struct Nd{int x,y;}Ans[100002];
struct Node{int ed,before;}s[100002];
void add(int x,int y) {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1;}
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&d[i]),add(d[i],i),size[d[i]]++;
  memcpy(Fox,fox,sizeof(Fox));
  if (size[0]!=1) { printf("-1\n"); return 0;}
  for (i=1;i<n;i++)
     if (size[i])
   {  if (size[i]>0&&size[i-1]==0||size[i]/size[i-1]+(size[i]%size[i-1]>0)+(i>1)>k) { printf("-1\n"); return 0; }
      int x=size[i]/size[i-1];
       for (j=fox[i-1],K=1;j;j=s[j].before,K++) 
          for (int l=1;l<=x+(K<=size[i]%size[i-1]);l++)
            Ans[++ans].x=s[j].ed,Ans[ans].y=s[Fox[i]].ed,Fox[i]=s[Fox[i]].before;
}
printf("%d\n",ans);
for (i=1;i<=ans;i++) printf("%d %d\n",Ans[i].x,Ans[i].y);
}