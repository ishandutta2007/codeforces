#include <bits/stdc++.h>

using namespace std;

struct Rect
{
  int x1, y1, x2, y2;
};

int N;
map< tuple< int, int, int, int >, int > dp;

int check(int x1, int y1, int x2, int y2)
{
  if(dp.count(tie(x1, y1, x2, y2))) return (dp[tie(x1, y1, x2, y2)]);
  cout << "?" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  int k;
  cin >> k;
  return (dp[tie(x1, y1, x2, y2)] = k);
}

Rect getRect(int x1, int y1, int x2, int y2)
{
  Rect rect;
  int left = x1, right = x2;
  while(right - left > 0) {
    int mid = (left + right) / 2;
    if(check(x1, y1, mid, y2) == 0) left = mid + 1;
    else right = mid;
  }
  rect.x2 = left;
  left = y1, right = y2;
  while(right - left > 0) {
    int mid = (left + right) / 2;
    if(check(x1, y1, x2, mid) == 0) left = mid + 1;
    else right = mid;
  }
  rect.y2 = left;
  left = x1, right = x2;
  while(right - left > 0) {
    int mid = (left + right + 1) / 2;
    if(check(mid, y1, x2, y2) == 0) right = mid - 1;
    else left = mid;
  }
  rect.x1 = left;
  left = y1, right = y2;
  while(right - left > 0) {
    int mid = (left + right + 1) / 2;
    if(check(x1, mid, x2, y2) == 0) right = mid - 1;
    else left = mid;
  }
  rect.y1 = left;
  return (rect);
}

int main()
{
  Rect r1, r2;

  cin >> N;

  int left = 1, right = N;
  while(right - left > 0) {
    int mid = (left + right) / 2;
    if(check(1, 1, mid, N) == 0) left = mid + 1;
    else right = mid;
  }
  if(check(1, 1, left, N) == 1 && check(left + 1, 1, N, N) == 1) {
    r1 = getRect(1, 1, left, N);
    r2 = getRect(left + 1, 1, N, N);
  } else {
    left = 1, right = N;
    while(right - left > 0) {
      int mid = (left + right) / 2;
      if(check(1, 1, N, mid) == 0) left = mid + 1;
      else right = mid;
    }
    r1 = getRect(1, 1, N, left);
    r2 = getRect(1, left + 1, N, N);
  }

  cout << "! " << r1.x1 << " " << r1.y1 << " " << r1.x2 << " " << r1.y2 << " "
       << r2.x1 << " " << r2.y1 << " " << r2.x2 << " " << r2.y2 << endl;
}