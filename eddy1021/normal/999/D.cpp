#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, m, a[N];
vector<int> c[N];
LL ans;
int main(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    c[a[i]%m].push_back(i);
  }
  int ptr=0;
  int goal=n/m;
  for(int i=0; i<m; i++){
    while((int)c[i].size() > goal){
      ptr=max(ptr, i);
      while((int)c[ptr % m].size() >= goal) ptr ++;
      int tk=min((int)c[i].size()-goal, goal-(int)c[ptr % m].size());
      int dlt=ptr-i;
      while(tk--){
        ans+=dlt;
        a[c[i].back()]+=dlt;
        c[ptr % m].push_back(c[i].back());
        c[i].pop_back();
      }
    }
  }
  printf("%lld\n", ans);
  for(int i=0; i<n; i++)
    printf("%d%c", a[i], " \n"[i+1==n]);
}