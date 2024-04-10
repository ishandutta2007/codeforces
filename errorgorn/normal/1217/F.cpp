#include <cstdio>
#include <vector>
#include <utility>
#include <unordered_set>
#include <chrono>
using namespace std;
typedef pair<int,int> ii;
struct custom_hash {
    typedef long long ll;
    typedef unsigned long long ull;
    const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return splitmix64((((ll)i.first)^(((ll)i.second)<<32))+FIXED_RANDOM);
    }
};

struct ufds{
    int p[200005];
    int r[200005];
    
    init(){
        for (int x=0;x<200005;x++){
            p[x]=x;
            r[x]=0;
        }
    }
    
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            p[i]=j;
        }
        else{
            p[j]=i;
            if (r[i]==r[j]) r[i]++;
        }
    }
};

struct Q{
    int t;
    int a,b;
    Q(int i,int j,int k){
        t=i,a=j,b=k;
    }
};

inline ii F(int i,int j){
    if (i<j) return ii(i,j);
    else return ii(j,i);
}
const int bucket_size=2000;

int n,q;
unordered_set<ii,custom_hash> curr,cache;
vector<Q> queries;
ufds DSU=*new ufds();

int dfs_time=0;
unordered_set<int,custom_hash> al[200005];
int visited[200005];

void dfs(int i){
    visited[i]=dfs_time;
    for (auto &it:al[i]){
        if (visited[it]!=dfs_time) dfs(it);
    }
}

int lastans=0;
int main(){
      scanf("%d%d",&n,&q);
      
      int a,b,c;
      while (q){
          for (int x=0;x<200005;x++) al[x].clear();
          for (int x=0;x<min(q,bucket_size);x++){
              scanf("%d%d%d",&a,&b,&c);
              b--,c--; ///make this 0-indexed
              queries.push_back(*new Q(a,b,c));
              if (a==1){
                  if (curr.count(F(b,c))){
                      cache.insert(F(b,c));
                      curr.erase(F(b,c));
                  }
                  b=(b+1)%n,c=(c+1)%n;
                  if (curr.count(F(b,c))){
                      cache.insert(F(b,c));
                      curr.erase(F(b,c));
                  }
              }
          }
          DSU.init();
          
          for (auto &it:curr){
              DSU.unions(it.first,it.second);
          }
          for (auto &it:cache){
              al[DSU.parent(it.first)].insert(DSU.parent(it.second));
              al[DSU.parent(it.second)].insert(DSU.parent(it.first));
          }
          
          for (auto &it:queries){
              if (it.t==1){
                  a=(it.a+lastans)%n,b=(it.b+lastans)%n;
                  if (cache.count(F(a,b))){
                      cache.erase(F(a,b));
                      al[DSU.parent(a)].erase(DSU.parent(b));
                      al[DSU.parent(b)].erase(DSU.parent(a));
                  }
                  else{
                      cache.insert(F(a,b));
                      al[DSU.parent(a)].insert(DSU.parent(b));
                      al[DSU.parent(b)].insert(DSU.parent(a));
                  }
              }
              else{
                  a=(it.a+lastans)%n,b=(it.b+lastans)%n;
                  dfs_time++;
                  dfs(DSU.parent(a));
                  if (visited[DSU.parent(b)]==dfs_time) lastans=1;
                  else lastans=0;
                  printf("%d",lastans);
              }
          }
          
          for (auto &it:cache){
              curr.insert(it);
          }
          cache.clear();
          queries.clear();
          q=max(0,q-bucket_size);
      }
}