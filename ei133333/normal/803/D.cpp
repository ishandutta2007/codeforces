#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector< int > tt;

bool check(int width)
{
  int beet = 1;

  int sum = 0;
  for(int i = 0; i < tt.size(); i++) {
    if(tt[i] > width) return (false);
    if(sum + tt[i] > width) {
      ++beet;
      sum = 0;
    }
    sum += tt[i];
  }
  return (beet <= N);
}

int main()
{
  cin >> N;
  cin.ignore();
  getline(cin, S);

  int tail = 0;

  for(int i = 0; i <= S.size(); i++) {
    if(i == S.size() || S[i] == ' ' || S[i] == '-') {
      tt.emplace_back(i - tail + 1);
      tail = i + 1;
    }
  }
  tt.back()--;
  int low = 0, high = 1 << 28;
  while(high - low > 0) {
    int mid = (low + high) >> 1;
    if(check(mid)) high = mid;
    else low = mid + 1;
  }
  cout << low << endl;

}