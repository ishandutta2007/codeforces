#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  int arr[2] = {0, 0};
  for(int i = 0; i < n; i++) {
    int greater = arr[1] > arr[0];
    if(s[i] == ')') {
      arr[greater]--;
      cout << greater;
    } else {
      arr[!greater]++;
      cout << !greater;
    }
  }
  cout << endl;
}