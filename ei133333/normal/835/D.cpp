#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int INF = 1 << 30;

string S;
short isPalindromic[5000][5000];
short LCP[5000][5000];
int depth[5000][5000];
int64 ans[5002];


bool check1(int left, int right)
{
  if(left >= right) return (true);
  if(~isPalindromic[left][right]) return (isPalindromic[left][right]);
  if(S[left] != S[right]) return (isPalindromic[left][right] = false);
  return (isPalindromic[left][right] = check1(left + 1, right - 1));
}

int check2(int left, int right)
{
  if(left >= right) return (1);
  if(~depth[left][right]) return (depth[left][right]);
  int size = (right - left - 1) >> 1, ret;
  if(isPalindromic[left][right]) ret = 1;
  else ret = -INF;
  if(LCP[left][right-size] < size + 1) return (depth[left][right] = ret);
  return (depth[left][right] = max(ret, 1 + min(check2(left, left + size), check2(right - size, right))));
}

int main()
{
  memset(isPalindromic, -1, sizeof(isPalindromic));
  memset(depth, -1, sizeof(depth));

  cin >> S;
  for(int i = 0; i < S.size(); i++) {
    for(int j = i; j < S.size(); j++) {
      isPalindromic[i][j] = check1(i, j);
    }
  }
  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = S.size() - 1; j >= 0; j--) {
      LCP[i][j] = S[i] == S[j] ? LCP[i + 1][j + 1] + 1 : 0;
    }
  }

  for(int i = 0; i < S.size(); i++) {
    for(int j = i; j < S.size(); j++) {
      ans[0]++;
      ans[max(0, check2(i, j) + 1)]--;
    }
  }
  for(int i = 1; i <= S.size(); i++) {
    ans[i] += ans[i - 1];
  }
  for(int i = 1; i <= S.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}