#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200100
#define ALP_SIZ 256

char s[MAX_N]; string str;
int N, m, SA[MAX_N], LCP[MAX_N];
int x[MAX_N], y[MAX_N], w[MAX_N], c[MAX_N];

inline bool cmp(const int a, const int b, const int l) {
  return (y[a] == y[b] && y[a + l] == y[b + l]);
}

void Sort() {
  for (int i = 0; i < m; i++) w[i] = 0;
    for (int i = 0; i < N; i++) ++w[x[y[i]]];
      for (int i = 0; i < m - 1; i++) w[i + 1] += w[i];
        for (int i = N - 1; i >= 0; i--) SA[--w[x[y[i]]]] = y[i];
}

void DA() {
  ++N;
  for (int i = 0; i < N; i++) x[i] = str[i], y[i] = i;
    Sort();

  for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
    for (p = 0, i = N - j; i < N; i++) y[p++] = i;
      for (int k = 0; k < N; k++)
        if (SA[k] >= j)
          y[p++] = SA[k] - j;

    Sort();
    for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
      x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
  }

  for (int i = 1; i < N; i++) SA[i - 1] = SA[i];
  --N;
}

int forbid[MAX_N];
long long ans;

void kasaiLCP() {
  for (int i = 0; i < N; i++) c[SA[i]] = i;
  LCP[0] = 0;
  for (int i = 0, h = 0; i < N; i++) {
    if (c[i] == N-1) {
      LCP[c[i]] = h = 0;
      continue;
    }

    int j = SA[c[i] + 1];
    while (i + h < N && j + h < N && str[i + h] == str[j + h]) ++h;
    LCP[c[i]] = h;
    if (h > 0) --h;
  }
}

void SuffixArray() {
  m = ALP_SIZ;
  N = str.size();
  DA();
  kasaiLCP();
}

long long histogram(vector<int> &v) {
    vector<pair<int, int>> st;
    long long ans = 0;

    for(int i = 0; i < v.size(); i++) {
        while(!st.empty() && st.back().first >= v[i]) {
            long long h = st.back().first, L, R = i-1;
            st.pop_back();
            L = st.empty() ? -1 : st.back().second;
            ans = max(ans, h * (R - L + 1));
        }
        st.emplace_back(v[i], i);
    }
    while(!st.empty()) {
        long long h = st.back().first, L, R = v.size()-1;
        st.pop_back();
        L = st.empty() ? -1 : st.back().second;
        ans = max(ans, h * (R - L + 1));
    }

    return ans;
}

int main() {
    scanf("%d %s", &N, s); str = s;
    reverse(str.begin(), str.end());
    SuffixArray();

    for(int i = N-1; i >= 0; i--) {
        scanf("%1d", &forbid[i]);
        if(!forbid[i]) ans = N - i;
    }

    vector<int> bars;
    for(int i = 0; i < N; i++) {
        while(i < N && forbid[SA[i]]) i++;
        if(i == N) break;

        int h = LCP[i];
        while(i + 1 < N && forbid[SA[i+1]]) {
            i++;
            h = min(h, LCP[i]);
        }
        if(i + 1 < N) bars.push_back(h);
    }

    ans = max(ans, histogram(bars));
    printf("%lld\n", ans);
}