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

#define MAX 222222
int N,eA[MAX],eB[MAX];
vector<int> graph[MAX];

vector<int> paths[MAX];
int path_id[MAX], path_off[MAX], pathc;
int dfs_in[MAX], dfs_out[MAX], dfsc;
vector<int> trees[MAX];

bool is_anc(int a, int b) {
  return dfs_in[a] <= dfs_in[b] && dfs_out[b] <= dfs_out[a];
}

int dfs(int node, int par) {
  dfs_in[node] = dfsc++;
  int size = 1, best_size = 0, act_size;
  for (int i = 0; i < graph[node].size(); ++i) {
    int next = graph[node][i];
    if (next == par) continue;
    size += (act_size = dfs(next, node));

    int pid = path_id[next];
    if (best_size < act_size) {
      best_size = act_size;
      path_id[node] = pid;
      path_off[node] = paths[pid].size();
    }
    paths[pid].push_back(node);
  }
  dfs_out[node] = dfsc++;

  if (size == 1) {
    path_id[node] = pathc;
    path_off[node] = 0;
    paths[pathc].clear();
    paths[pathc].push_back(node);
    ++pathc;
  }
  return size;
}

void heavylight() {
  pathc = dfsc = 0;
  dfs(0, -1);
  paths[path_id[0]].push_back(0);
  for (int i = 0; i < pathc; ++i){
    REP(j,paths[i].size() + 2) trees[i].push_back(0); // create interval tree on (paths[i].begin(), paths[i].end()-1)
  }
}

void fadd(int p, int v, int val){
  while(v < trees[p].size()){
    trees[p][v] += val;
    v += v&-v;
  }
}

int fget(int p, int v){
  int sum = 0;
  while(v){
    sum += trees[p][v];
    v -= (v&-v);
  }
  return sum;
}


int query(int x, int y, bool add) {
  if (x == y)
    return 0; // query vertex x, in manipulating the vertices
  if (is_anc(x, y)) return query(y, x, add);
  int p = path_id[x], be = path_off[x], en = paths[p].size()-1;
  if (is_anc(paths[p][en], y)) {
    while (en-be > 1) {
      int m = (be+en)/2;
      if (is_anc(paths[p][m], y)) en = m;
      else be = m;
    }
    be = path_off[x];
  }
  if(add){
    //printf("adding: p:%d be:%d en:%d\n", p, be,en);
    fadd(p, be + 1, 1);
    fadd(p, en + 1, -1);
    query(paths[p][en], y, add);
  }
  else{
    //printf("getting: p:%d be:%d en:%d\n", p, be,en);
    int tmp = fget(p, be + 1);
    return tmp + query(paths[p][en], y, add);
  }
  return -1;
  // return: trees[p].query(be, en) JOIN query(paths[p][en], y)
}

void add(int a,int b){
  query(a, b, true);
}

int get(int a,int b){
  return query(a,b,false);
}

int main(int argc, char *argv[]){
  scanf("%d",&N);
  REP(i,N-1){
    scanf("%d%d",&(eA[i]),&(eB[i]));
    eA[i]--;
    eB[i]--;
    graph[eA[i]].push_back(eB[i]);
    graph[eB[i]].push_back(eA[i]);
  }
  heavylight();
  int K, a, b;
  scanf("%d",&K);
  REP(i,K){
    scanf("%d%d",&a,&b);
    a--; b--;
    add(a,b);
  }
  REP(i,N-1){
    if(i) printf(" ");
    printf("%d", get(eA[i], eB[i]));
  }
  printf("\n");
  return 0;
}