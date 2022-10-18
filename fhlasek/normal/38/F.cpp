#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXM 50000

using namespace std;

int N,M;

map<string,int> m;
set<string> S;

typedef struct state{
  int num,first,second,wins;
  bool done;
}State;

State dp[MAXM];

int score(string s){
  int sc=0,i,ma=0;
  FOR(i,s.size()){
    sc+=s[i]-'a'+1;
    ma=max(ma,s[i]-'a'+1);
  }
  sc=sc*ma+dp[m[s]].num;
  return sc;
}

void solve(string s){
  int x=m[s],y,sc,i;
  dp[x].first=-1;
  dp[x].second=0;
  dp[x].wins=0;
  string ns;
  FOR(i,52){
    if(i<26){
      ns="";
      ns.push_back(i+'a');
      ns+=s;
    }
    else{
      ns=s;
      ns.push_back(i+'a'-26);
    }
    if(S.count(ns)){
      y=m[ns];
      if(!dp[y].done) solve(ns);
      sc=score(ns)+dp[y].second;
      if(dp[x].first==-1||(dp[y].wins==-1&&dp[x].wins==-1)||(dp[x].wins==-dp[y].wins&&(sc>dp[x].first||(sc==dp[x].first&&dp[y].first<dp[x].second)))){
        dp[x].first=sc;
        dp[x].second=dp[y].first;
        dp[x].wins=-dp[y].wins;
      }
    }
  }
  if(dp[x].first==-1){
    dp[x].first=0;
    dp[x].wins=-1;
  }
  dp[x].done=true;
}


int main(int argc, char *argv[]){
  int i,j,k,tmp;
  char line[50];
  string s;
  set<string> ss;
  M=0;
  m[""]=M++;
  scanf("%d",&N);
  FOR(i,N){
    scanf("%s",line);
    ss.clear();
    for(j=0;line[j]!='\0';j++){
      s="";
      for(k=j;line[k]!='\0';k++){
        s.push_back(line[k]);
        if(S.count(s)==0){
          S.insert(s);
          m[s]=M++;
          tmp=M-1;
          dp[M-1].num=1;
          dp[M-1].done=false;
        }
        else{
          if(ss.count(s)==0) dp[m[s]].num++;
        }
        ss.insert(s);
      }
    }
  }
  solve("");
  int res=m[""];
  if(dp[res].wins==1) printf("First\n");
  else printf("Second\n");
  printf("%d %d\n",dp[res].first,dp[res].second);
  return 0;
}