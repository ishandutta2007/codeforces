#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 28;

string S;
int dp[100001][3][3];
tuple< int, int, int, int > nt[100001][3][3];

int rec(int idx, int mod, bool zero)
{
  if(idx == S.size()) return ((mod == 0 && zero) ? 0 : INF);
  if(~dp[idx][mod][zero]) return (dp[idx][mod][zero]);

  int ret = rec(idx + 1, mod, zero) + 1;
  nt[idx][mod][zero] = make_tuple(idx + 1, mod, zero, 0);

  if(S[idx] != '0' || zero) {
    auto get = rec(idx + 1, (mod + S[idx] - '0') % 3, true);
    if(ret > get) {
      ret = get;
      nt[idx][mod][zero] = make_tuple(idx + 1, (mod + S[idx]) % 3, true, 1);
    }
  }

  return(dp[idx][mod][zero] = ret);
}

int main()
{
  memset(dp, -1, sizeof(dp));


  cin >> S;
  int get = rec(0, 0, 0);

  if(get >= INF) {
    if(S.find('0') == string::npos) cout << -1 << endl;
    else cout << 0 << endl;
  } else {
    int a = 0, b = 0, c = 0;
    string T;
    while(a != S.size()) {
      int e, f, g, h;
      tie(e, f, g, h) = nt[a][b][c];
      if(h) T += S[a];
      a = e, b = f, c = g;
    }
    cout << T << endl;
  }
}