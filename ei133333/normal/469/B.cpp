#include<bits/stdc++.h>  
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

int main(){
  int p, q, l, r;
  bool aa[2005] = {}, bb[2005] = {};

  cin >> p >> q >> l >> r;
  for(int i = 0; i < p; i++){
    int a, b;
    cin >> a >> b;
    for(int j = a; j <= b; j++) aa[j] = true;
  }
  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    for(int j = a; j <= b; j++) bb[j] = true;
  }

  int cnt = 0;
  for(int i = l; i <= r; i++){ //Z
    bool flag = false;
    for(int k = 0; k < 1003; k++){
      if(aa[k + i] && bb[k]) flag = true;
    }
    cnt += flag;
  }
  cout << cnt << endl;
}