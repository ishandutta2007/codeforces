#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 N, K, B;
  cin >> N >> K >> B;
  vector< pair< int64, int > > beet(N - 1);
  for(int i = 0; i < N - 1; i++) {
    cin >> beet[i].first;
    beet[i].second = i + 1;
  }
  int64 aa;
  cin >> aa;
  sort(beet.rbegin(), beet.rend());

  int64 sum = 0;
  for(int i = 0; i < K - 1; i++) {
    sum += beet[i].first;
  }

  int64 ret = N;
  for(int i = 0; i < N - 1; i++) {
    int64 curr = beet[max< int >(K - 1, i)].first;
    if(B - sum < curr && ret > beet[i].second) {
      ret = beet[i].second;
    }
  }

  cout << ret << endl;
}