#include <bits/stdc++.h>
using namespace std;
const int N=1021;
int n, m;
char c[N][N];
short up[N][N], dn[N][N], lf[N][N], rg[N][N];
vector<tuple<int,int,int>> ans;
short sup[N][N], slf[N][N];
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++)
    scanf("%s", c[i]+1);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(c[i][j] == '*'){
        up[i][j]=up[i-1][j]+1;
        lf[i][j]=lf[i][j-1]+1;
      }
  for(int i=n; i>=1; i--)
    for(int j=m; j>=1; j--)
      if(c[i][j] == '*'){
        dn[i][j]=dn[i+1][j]+1;
        rg[i][j]=rg[i][j+1]+1;
      }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      if(c[i][j] != '*') continue;
      int len=min(min(up[i][j], dn[i][j]),
                  min(lf[i][j], rg[i][j]));
      if(len <= 1) continue;
      ans.push_back(make_tuple(i, j, len-1));
      sup[i-len+1][j]++;
      sup[i+len  ][j]--;
      slf[i][j-len+1]++;
      slf[i][j+len  ]--;
    }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      sup[i][j]+=sup[i-1][j];
      slf[i][j]+=slf[i][j-1];
    }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(c[i][j] == '*' and sup[i][j]==0 and slf[i][j]==0){
        puts("-1");
        exit(0);
      }
  printf("%d\n", (int)ans.size());
  for(auto i: ans)
    printf("%d %d %d\n",
           get<0>(i),
           get<1>(i),
           get<2>(i));
}