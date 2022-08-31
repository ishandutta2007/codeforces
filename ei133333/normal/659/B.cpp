#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;

int main()
{
  int N, M;
  cin >> N >> M;
  vector< pair< int, string > > regions[100000];
  for(int i = 0; i < N; i++) {
    string S;
    cin >> S;
    int x, y;
    cin >> x >> y;
    regions[--x].push_back({y, S});
  }
  for(int i = 0; i < M; i++) {
    sort(regions[i].rbegin(), regions[i].rend());
    if(regions[i].size() == 2) {
      cout << regions[i][0].second << " " << regions[i][1].second << endl;
    } else {
      if(regions[i][1].first == regions[i][2].first) {
        cout << "?" << endl;
      } else {
        cout << regions[i][0].second << " " << regions[i][1].second << endl;
      }
    }
  }
}