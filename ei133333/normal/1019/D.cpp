#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a, b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it, s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long ll;
typedef pair< ll, ll > pt;
typedef pair< pt, pt > slope;

ll mod = 1000000007;

pt getSlope(const slope &a) {
  return make_pair(a.Y.X - a.X.X, a.Y.Y - a.X.Y);
}

bool cmp(const slope &a, const slope &b) {
  pt s1 = getSlope(a), s2 = getSlope(b);
  return s1.Y * s2.X < s2.Y * s1.X;
}

ll area(const pt &a, const pt &b, const pt &c) {
  ll ans = a.X * b.Y - b.X * a.Y;
  ans += b.X * c.Y - c.X * b.Y;
  ans += c.X * a.Y - c.Y * a.X;
  return ans;
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  k *= 2;
  vector< pt > v(n);
  rep(i, n) {
    cin >> v[i].X >> v[i].Y;
  }
  vector< slope > slopes;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < i; ++j) {
      slopes.push_back(make_pair(v[i], v[j]));
      pt &x = slopes.back().X, &y = slopes.back().Y;
      if(x.X == y.X) {
        if(y.Y < x.Y) swap(x, y);
      } else if(y.X < x.X) swap(x, y);
    }
  }

  sort(slopes.begin(), slopes.end(), cmp);
  sort(v.begin(), v.end());
  map< pt, int > mp;
  for(int i = 0; i < n; ++i) {
    mp[v[i]] = i;
  }
  ll ans = 0;
  for(const slope &s : slopes) {
    pt a = s.X, b = s.Y;
    int &id1 = mp[a];
    int &id2 = mp[b];

    int idx1 = id1, idx2 = id2;
    if(idx1 > idx2) {
      swap(idx1, idx2);
    }
    int lo = min(idx2 + 1, n - 1);
    int hi = n - 1, mid = 0;
    while(hi - lo > 1) {
      mid = (lo + hi) / 2;
      if(mid < 0 || mid >= n) break;
      if(area(a, b, v[mid]) > k) hi = mid - 1;
      else lo = mid;
    }
    if(hi > lo && hi >= 0 && hi < n && area(a, b, v[hi]) <= k) mid = hi;
    else mid = lo;
    ll ar = (mid < n && mid >= 0 ? area(a, b, v[mid]) : 0);

    if(ar == k) {
      cout << "Yes" << endl;
      cout << a.X << " " << a.Y << endl;
      cout << b.X << " " << b.Y << endl;
      cout << v[mid].X << " " << v[mid].Y << endl;
      return 0;
    }

    lo = 0, hi = max(idx1 - 1, 0);
    while(hi - lo > 1) {
      mid = (lo + hi) / 2;
      if(mid < 0 || mid >= n) break;
      if(-area(a, b, v[mid]) * 2 > k) lo = mid + 1;
      else hi = mid;
    }
    if(hi > lo && lo >= 0 && lo < n && -area(a, b, v[lo]) <= k) mid = lo;
    else mid = hi;
    ar = (0 <= mid && mid < n ? -area(a, b, v[mid]) : 0);

    if(ar == k) {
      cout << "Yes" << endl;
      cout << a.X << " " << a.Y << endl;
      cout << b.X << " " << b.Y << endl;
      cout << v[mid].X << " " << v[mid].Y << endl;
      return 0;
    }

    swap(v[id1], v[id2]);
    swap(id1, id2);
  }
  cout << "No" << endl;
  return 0;
}