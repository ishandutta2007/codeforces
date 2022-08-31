#include<bits/stdc++.h>
using namespace std;
int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};
const string T = "LRUD";
typedef pair< int, int > Pi;

int main()
{
  int n, p;
  cin >> n;

  int dp[100001] = {};
  for(int i = 0; i < n; i++) {
    int p;
    cin >> p;
    dp[p] = dp[p - 1] + 1;
  }
  cout << n - *max_element(dp, dp + n + 1) << endl;
}