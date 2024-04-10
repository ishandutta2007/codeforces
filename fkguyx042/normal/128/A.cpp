#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
using namespace std;
string s[8];

int dfs(int i0,int  j0, int k)
{
if (k>=7) {cout<<"WIN"; exit(0);}
for (int i=-1;i<=1;i++)
 for (int j=-1;j<=1;j++)
 {int i1=i0+i,j1=j0+j;
  if (i1<0||i1>7||j1<0||j1>7) continue;
  if (i1-k>=0&&s[i1-k][j1]=='S') continue;
  if (i1-k>=1&&s[i1-k-1][j1]=='S') continue;
  dfs(i1,j1,k+1);
 }
return 0;
}
int main()
{
for (int i=0;i<8;i++) cin>>s[i];
dfs(7,0,0);
cout<<"LOSE";
return 0;
}