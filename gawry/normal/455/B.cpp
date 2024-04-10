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
int n,k;
const int MAX=1000000;
char buf[MAX];
bool leaf_wins;
struct node {
  node *next[26];
  node(){
    memset(next,0,sizeof(next));
  }
  void add(char *buf){
    if(!*buf)return;
    char tmp=*buf-'a';
    if(!next[tmp])next[tmp]=new node();
    next[tmp]->add(++buf);
  }
  bool calc(){
    int cnt=0;
    FOR(i,26)cnt+=!next[i];
    //printf("%d %d\n",cnt,leaf_loses);
    if(cnt==26)return leaf_wins;
    bool res=false;
    FOR(i,26)if(next[i])res|=!next[i]->calc();
    //printf("%d %d\n",cnt,res);
    return res;
  }
} root;
int main(){
  scanf("%d %d",&n,&k);
  while(n--){
    scanf(" %s",buf);
    root.add(buf);
  }
  leaf_wins=false;
  bool leaf_loses_result=root.calc();
  leaf_wins=true;
  bool leaf_wins_result=root.calc();
//printf("%d %d\n",(int)leaf_loses_result,(int)leaf_wins_result);
  leaf_wins=false;
  if(!leaf_loses_result){
    leaf_wins=false;
  }else{
    --k;
    leaf_wins=true;
    if(k){
      if(leaf_wins_result){
        leaf_wins=true;
      }else{
        --k;
        leaf_wins=false;
        leaf_wins^=k%2;
      }
    }
  }
//  while(k--){
//    leaf_wins=!leaf_wins?leaf_loses_result:leaf_wins_result;
//  }
  printf("%s\n",leaf_wins?"First":"Second");
  return 0;
}