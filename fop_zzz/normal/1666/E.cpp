#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

const int maxn = 1e5 + 5;
int L, n;
int a[maxn];
int ql[maxn], qr[maxn];

bool check(int l, int r){
  ql[1] = qr[1] = 0;
  rep(i, 1, n){
    ql[i + 1] = ql[i] + l;
    qr[i + 1] = qr[i] + r;
    if(ql[i + 1] > a[i + 1]) return false;
    ql[i + 1] = max(ql[i + 1], a[i]);
    if(qr[i + 1] < a[i]) return false;
    qr[i + 1] = min(qr[i + 1], a[i + 1]);
  }
  if(qr[n + 1] == a[n + 1]) return true;
  else return false;
}

vector <int> ans;

void solve(int l, int r){
  int s = L;
  ans.push_back(L);
  per(i, n, 1){
    int pl = s - r;
    s = max(pl, ql[i]);
    ans.push_back(s);
  }
  for(int i = ans.size() - 1; i >= 1; -- i){
    printf("%d %d\n", ans[i], ans[i - 1]);
  }
}

int main(){
  rd(L), rd(n);
  rep(i, 1, n) rd(a[i]);
  a[n + 1] = L;
  int l = 0, r = L;
  while(r - l > 1){
    int mid = l + r >> 1;
    if(check(1, mid)) r = mid;
    else l = mid;
  }
  int M = r;
  l = 1, r = L;
  while(r - l >> 1){
    int mid = l + r >> 1;
    if(check(mid, M)) l = mid;
    else r = mid;
  }
  int m = l;
  check(m, M);
  solve(m, M);
  return 0;
}