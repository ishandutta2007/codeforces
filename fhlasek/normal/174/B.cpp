/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char l[1000000];
int L;

vector<string> solve(){
  vector<string> ans;
  string name = "",tmp = "";
  REP(i,L){
    if(l[i] == '.'){
      if(name == ""){ if(tmp.size() == 0){ ans.clear(); return ans; } name = tmp; }
      else{
        if(name.size() > 8 || tmp.size() < 2 || tmp.size() > 11){ ans.clear(); return ans; }
        string ext = "";
        REP(j,min((int)tmp.size()-1,3)) ext.push_back(tmp[j]);
        ans.push_back(name + "." + ext);
        name.clear();
        FOR(j,min((int)tmp.size()-1,3),tmp.size()-1) name.push_back(tmp[j]); 
        tmp.clear();
      }
      tmp = "";
    }
    else tmp.push_back(l[i]);
  }
  ans.push_back(name + "." + tmp);
  if(name.size() == 0 || name.size() > 8 || tmp.size() > 3 || tmp.size() == 0) ans.clear();
  return ans;
}

int main(int argc, char *argv[]){
  scanf("%s",l); 
  L = strlen(l);
  vector<string> ans = solve();
  if(ans.size()){
    printf("YES\n");
    REP(i,ans.size()) printf("%s\n",ans[i].c_str());
  }
  else printf("NO\n");
  return 0;
}