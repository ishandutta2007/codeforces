#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
int n, m, a[N], b[N], ans[N][N];
void no(){
  puts("NO");
  exit(0);
}
int xa[N], xb[N];
void go(int bt){
  vector<int> ixa, ixb;
  for(int i=0; i<n; i++) if(xa[i]) ixa.push_back(i);
  for(int i=0; i<m; i++) if(xb[i]) ixb.push_back(i);
  while(ixa.size() and ixb.size()){
    int iia=ixa.back(); ixa.pop_back();
    int iib=ixb.back(); ixb.pop_back();
    ans[iia][iib]^=(1<<bt);
  }
  while(ixa.size()>1u){
    int iia1=ixa.back(); ixa.pop_back();
    int iia2=ixa.back(); ixa.pop_back();
    ans[iia1][0]^=(1<<bt);
    ans[iia2][0]^=(1<<bt);
  }
  while(ixb.size()>1u){
    int iib1=ixb.back(); ixb.pop_back();
    int iib2=ixb.back(); ixb.pop_back();
    ans[0][iib1]^=(1<<bt);
    ans[0][iib2]^=(1<<bt);
  }
  if(ixa.size() or ixb.size()) no();
}
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<m; i++) cin>>b[i];
  for(int bt=0; bt<30; bt++){
    for(int i=0; i<n; i++) xa[i]=(a[i]>>bt)&1;
    for(int i=0; i<m; i++) xb[i]=(b[i]>>bt)&1;
    go(bt);
  }
  puts("YES");
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      printf("%d%c", ans[i][j], " \n"[j+1==m]);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      a[i]^=ans[i][j];
      b[j]^=ans[i][j];
    }
  assert(*max_element(a, a+n) == 0);
  assert(*max_element(b, b+m) == 0);
}