#include<bits/stdc++.h>
using namespace std;
const int N=111;
int n, m;
string s[N];
int dn[]={-1,-1,-1,0,1,1,1,0};
int dm[]={-1,0,1,1,1,0,-1,-1};
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++)
    cin>>s[i];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      if(s[i][j] == '.') s[i][j]='0';
      if(s[i][j] == '*') continue;
      int cnt=0;
      for(int d=0; d<8; d++){
        int ni=i+dn[d];
        int nj=j+dm[d];
        if(ni<0 or ni>=n or
           nj<0 or nj>=m)
          continue;
        if(s[ni][nj] == '*')
          cnt++;
      }
      if(cnt != s[i][j] - '0'){
        puts("No");
        exit(0);
      }
    }
  puts("Yes");
}