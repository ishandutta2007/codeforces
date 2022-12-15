#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1e5+5;

int pd[ms];
int arr[ms];
int pos[ms];

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  pd[n] = 0;
  for(int i = n-1; i > 0; i--) {
    pd[i] = 0;
    for(int j = i; j < n; j += i) {
      if(pos[i] - j > 0 && arr[pos[i]-j] > i) pd[i] = pd[i] || !pd[arr[pos[i]-j]];
      if(pos[i] + j <= n && arr[pos[i]+j] > i) pd[i] = pd[i] || !pd[arr[pos[i]+j]];
    }
  }
  //cout << pd[8] << endl;
  for(int i = 1; i <= n; i++) {
    if(pd[arr[i]]) cout << "A";
    else cout << "B";
  }
  cout << endl;
}