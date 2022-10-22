#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[26];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i)
    ++cnt[s[i]-'a'];
  int pre = 0, best = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 0) continue;
    if (best == 0 || best > cnt[i]) {
      best = cnt[i];
      pre = i;
    }
  }
  if (best == n) {
    printf("%s\n", s);
    return;
  }
  if (best == 1) {
    for (int i = 0; i < n; ++i) {
      if (s[i] == char(pre + 'a')) {
        swap(s[i], s[0]);
        break;
      }
    }
    sort(s+1, s+n);
    printf("%s\n", s);
    return;
  }
  pre = 0;
  while (cnt[pre] == 0)
    ++pre;
  int now = 0;
  s[now++] = pre + 'a';
  --cnt[pre];
  if (cnt[pre] * 2 > n) {
    int nxt = pre + 1;
    while (cnt[nxt] == 0) ++nxt;
    s[now++] = nxt + 'a';
    --cnt[nxt];
    int other = nxt + 1;
    while (other < 26 && cnt[other] == 0) ++other;
    if (other < 26) {
      while (cnt[pre] > 0) {
        s[now++] = pre + 'a';
        --cnt[pre];
      }
      s[now++] = other + 'a';
      --cnt[other];
      while (pre < 26) {
        while (cnt[pre] > 0) {
          s[now++] = pre + 'a';
          --cnt[pre];
        }
        ++pre;
      }
    } else {
      while (cnt[nxt] > 0) {
        s[now++] = nxt + 'a';
        --cnt[nxt];
      }
      while (cnt[pre] > 0) {
        s[now++] = pre + 'a';
        --cnt[pre];
      }
    }
  } else {
    s[now++] = pre + 'a';
    --cnt[pre];
    bool used = true;
    int lower = 0, upper = 0;
    for (int i = 0; i < pre; ++i)
      lower += cnt[i];
    for (int i = pre + 1; i < 26; ++i)
      upper += cnt[i];
    if (cnt[pre] > upper) {
      int cur = 0;
      while (now < n) {
        int rest = n - now;
        rest -= cnt[pre];
        if (rest < cnt[pre]) {
          s[now++] = pre + 'a';
          --cnt[pre];
          assert(!used);
          used = true;
        } else {
          while (cur < 26 && (cnt[cur] <= 0 || pre == cur)) ++cur;
          s[now++] = cur + 'a';
          --cnt[cur];
          used = false;
        }
      }
    } else {
      int cur = 0;
      while (now < n) {
        while (cur < 26 && (cnt[cur] <= 0 || pre == cur)) ++cur;
        if (cur < 26 && (cur < pre || used || cnt[pre] == 0)) {
          s[now++] = cur + 'a';
          --cnt[cur];
          used = false;
        } else {
          s[now++] = pre + 'a';
          --cnt[pre];
          assert(!used);
          used = true;
        }
      }
    }
  }
  printf("%s\n", s);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}