#include<bits/stdc++.h>  
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

int main(){
  int n, p, q;
  bool flag[101] = {};
  cin >> n;
  for(int q = 0; q < 2; q++){
    cin >> p;
    bool judge = false;
    for(int i = 0; i < p; i++){
      int hoge;
      cin >> hoge;
      flag[hoge]++;
    }
  }
  bool judge = true;
  for(int i = 1; i <= n; i++){
    if(!flag[i]) judge = false;
  }
  puts(judge ? "I become the guy." : "Oh, my keyboard!");
}