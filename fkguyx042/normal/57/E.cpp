#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,x,y,ans,Ans[501],B[4][4],A[4];
const int X[8]={-1,-1,1,1,-2,-2,2,2};
const int Y[8]={-2,2,-2,2,-1,1,-1,1};
struct Node{int x,y;}Q[10300001];
int vis[3201][3201];
long long k;
void DoA()
{  vis[1000][1000]=1;
   int l=1,r=0;
   Q[++r].x=1000;Q[r].y=1000;
   for (i=1;i<=n;i++)
   {  scanf("%d%d",&x,&y);
      vis[x+1000][y+1000]=-1;
   }
   ans=1;
   for (;l<=r;l++)
 {  x=Q[l].x; y=Q[l].y;
     if(vis[x][y]>k) continue;
    for (i=0;i<8;i++)
     if (!vis[x+X[i]][y+Y[i]])
     {  vis[x+X[i]][y+Y[i]]=vis[x][y]+1; ans++;
        Q[++r].x=x+X[i];
        Q[r].y=y+Y[i];
     }
 }
printf("%d\n",ans);
}
void ToA()
{ int C[4]={0},i,j,k;
  for (k=1;k<=3;k++)
    for (j=1;j<=3;j++)
     (C[j]+=1ll*A[k]*B[k][j]%Mo)%=Mo;
     memcpy(A,C,sizeof(C));
}
void ToB()
{  int C[4][4]={0},i,j,k;
    for (k=1;k<=3;k++)
     for (i=1;i<=3;i++)
       for (j=1;j<=3;j++)
         (C[i][j]+=1ll*B[i][k]*B[k][j]%Mo)%=Mo;
         memcpy(B,C,sizeof(B));
}
void Cheng(long long y)
{  for (;y;y>>=1ll)
  {   if (y&1) ToA();
      ToB();
  }
}
void DoB()
{     int l=1,r=0;
      Q[++r].x=1000;Q[r].y=1000;
 vis[1000][1000]=1;
    for (i=1;i<=n;i++)
    scanf("%d%d",&x,&y),vis[x+1000][y+1000]=-1;
    Ans[0]=1;
    for (;l<=r;l++)
 {  x=Q[l].x; y=Q[l].y;
     if(vis[x][y]>500) continue;
    for (i=0;i<8;i++)
     if (!vis[x+X[i]][y+Y[i]])
     {  vis[x+X[i]][y+Y[i]]=vis[x][y]+1; Ans[vis[x][y]]++;
        Q[++r].x=x+X[i];
        Q[r].y=y+Y[i];
     }
 }
 int Gc=(Ans[500]-Ans[499]);
 for (i=0;i<500;i++) (ans+=Ans[i])%=Mo;
 A[1]=Ans[500];
A[2]=ans;
A[3]=Gc;
B[3][1]=1;
B[1][1]=1;
B[1][2]=1;
B[2][2]=1;
B[3][3]=1;
 Cheng(k-499);
 printf("%d\n",A[2]);
}
int main()
{ 
  cin>>k;
  scanf("%d",&n);
  if (k<=500) DoA();
  else DoB();
}