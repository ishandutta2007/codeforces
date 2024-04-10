#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int v[N];
vector<int> a[2];
int main(){
  int n, x; scanf("%d", &n);
  while(n --){
    scanf("%d", &x);
    v[x]++;
  }
  for(int i=0; i<N; i++){
    if(v[i] > 2){
      puts("NO");
      exit(0);
    }
    if(v[i] > 0) a[0].push_back(i);
    if(v[i] > 1) a[1].push_back(i);
  }
  reverse(a[1].begin(), a[1].end());
  puts("YES");
  printf("%d\n", (int)a[0].size());
  for(size_t i=0; i<a[0].size(); i++)
    printf("%d%c", a[0][i], " \n"[i+1==a[0].size()]);
  printf("%d\n", (int)a[1].size());
  for(size_t i=0; i<a[1].size(); i++)
    printf("%d%c", a[1][i], " \n"[i+1==a[1].size()]);
}