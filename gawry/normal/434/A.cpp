#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int m,t[110000],cnt[110000];
vector<int> s[110000];
int main(){
  scanf("%*d %d",&m);
  vector<int> t;
  while(m--){
    int x;
    scanf("%d",&x);
    if(t.empty()||t.back()!=x)t.push_back(x);
  }
  int64 total=0;
  for(int i=1;i<t.size();i++){
    int x=t[i-1],y=t[i];
    s[x].push_back(y);
    s[y].push_back(x);
    total+=abs(x-y);
  }
  int64 best=total;
  FOR(i,110000){
    int64 sub=0;
    FOR(j,s[i].size())sub+=abs(i-s[i][j]);
    sort(s[i].begin(),s[i].end());
    int64 after=0;
    FOR(j,s[i].size())after+=s[i][j];
    int64 before=0;
    FOR(j,s[i].size()){
      after-=s[i][j];
      best=min(best,total-sub+(int64)s[i][j]*j-before+after-(int64)s[i][j]*((int)s[i].size()-1-j));
      //cout<<best<<":"<<i<<" "<<j<<endl;
      before+=s[i][j];
    }
  }
  cout<<best<<endl;
  return 0;
}