#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int ms = 1e5+5;

int a[ms+ms];
pair<int, int> arr[ms+ms];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i+n].first;
    arr[i].second = i;
    arr[i+n].second = i+n;
  }
  sort(arr, arr + n + n);
  for(int i = 0; i < n; i++) {
    a[arr[i].second] = 1;
  }
  for(int i = 0; i < n; i++) {
    cout << (a[i] | (int) (i < n/2));
  }
  cout << endl;
  for(int i = n; i < n + n; i++) {
    cout << (a[i] | (int) (i < n+n/2));
  }
  cout << endl;
}