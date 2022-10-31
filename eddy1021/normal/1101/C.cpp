#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
#define L first
#define R second
int n;
pair<int, int> a[N];
void init(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d%d", &a[i].L, &a[i].R);
}
int at[N], id[N];
void solve(){
  for(int i=0; i<n; i++) id[i]=i;
  sort(id, id+n,
       [&](int id1, int id2){
        return a[id1]<a[id2];
       });
  int ptr=0, pt=0;
  while(ptr<n){
    at[id[ptr]]=pt;
    int li=a[id[ptr]].L, ri=a[id[ptr]].R;
    ptr++;
    while(ptr < n and max(li, a[id[ptr]].L) <= min(ri, a[id[ptr]].R)){
      at[id[ptr]]=pt;
      ri=max(ri, a[id[ptr]].R);
      ptr++;
    }
    pt++;
  }
  if(pt <= 1){
    puts("-1");
    return;
  }
  for(int i=0; i<n; i++)
    printf("%d%c", (at[i]%2)+1, " \n"[i+1==n]);
}
int main(){
  int _; scanf("%d", &_); while(_ --){
    init();
    solve();
  }
}