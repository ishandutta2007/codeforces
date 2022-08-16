#include<bits/stdc++.h>

using namespace std;

int N, Y[50000], Table[50000][30];

bool check(int val, bool output = false)
{
  set< int > used;
  for(int i = 0; i < N; i++) {
    int pos = 29;
    while(pos >= 0 && (Table[i][pos] > val || used.count(Table[i][pos]))) --pos;
    if(Table[i][pos] == 0) return (false);
    if(used.count(Table[i][pos])) return (false);
    used.insert(Table[i][pos]);
    if(output) cout << Table[i][pos] << " ";
  }
  return (true);
}

int main()
{
  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> Y[i];
    Table[i][29] = Y[i];
    for(int j = 28; j >= 0; j--) {
      Table[i][j] = Table[i][j + 1] >> 1;
    }
  }

  int low = 0, high = 1 << 30;
  while(high - low > 0) {
    int mid = (low + high) >> 1;
    if(check(mid)) high = mid;
    else low = mid + 1;
  }
  check(low, true);
}