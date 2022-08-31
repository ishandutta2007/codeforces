#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

int64 cost[2002][2002];
int min_t[2002][2002], min_p[2002][2002];


vector< int > xs, A;
vector< int > belong[2002];
int64 dp1[2000], dp2[2000];
vector< int > ans;

int64 rec_diff(int idx);

int64 rec_same(int idx) {
  if(~dp1[idx]) return dp1[idx];
  int64 ret = infll;
  for(auto &t : belong[A[idx]]) {
    ret = min(ret, rec_diff(t) + cost[idx][t]);
  }
  return dp1[idx] = ret;
};

int64 rec_diff(int idx) {
  if(~dp2[idx]) return dp2[idx];
  if(A[idx] + 1 == xs.size()) return 0;
  int64 ret = infll;
  for(auto &t : belong[A[idx] + 1]) {
    chmin(ret, rec_same(t) + abs(idx - t));
  }
  return dp2[idx] = ret;
}

void rec_same_dump(int idx);

void rec_diff_dump(int idx) {
  int64 ret = dp2[idx];
  if(A[idx] + 1 == xs.size()) return;
  for(auto &t : belong[A[idx] + 1]) {
    if(rec_same(t) + abs(idx - t) == ret) {
      rec_same_dump(t);
      return;
    }
  }
}


void rec_same_dump(int idx) {
  int64 ret = dp1[idx];


  auto &vs = belong[A[idx]];

  for(auto &t : vs) {
    if(rec_diff(t) + cost[idx][t] == ret) {

      if(vs.size() == 1) {
        ans.emplace_back(idx);
      } else {

        vector< int > conv;
        for(int i = 0; i < vs.size(); i++) {
          if(vs[i] == idx || vs[i] == t) conv.emplace_back(i);
        }

        int a = conv[0], b = conv[1];
        vector< int > tap;
        tap.emplace_back(vs[a]);
        if(min_t[idx][t] == 1) {
          for(int i = min_p[idx][t]; i < b; i++) tap.emplace_back(vs[i]);
          for(int i = b + 1; i < vs.size(); i++) tap.emplace_back(vs[i]);
          for(int i = 0; i < min_p[idx][t]; i++) tap.emplace_back(vs[i]);
          tap.emplace_back(vs[b]);
        } else if(min_t[idx][t] == 2) {
          for(int i = min_p[idx][t] + 1; i < vs.size(); i++) tap.emplace_back(vs[i]);
          for(int i = 0; i < a; i++) tap.emplace_back(vs[i]);
          for(int i = a + 1; i < b; i++) tap.emplace_back(vs[i]);
          for(int i = min_p[idx][t]; i >= b; i--) tap.emplace_back(vs[i]);
        } else {
          for(int i = min_p[idx][t] - 1; i > a; i--) tap.emplace_back(vs[i]);
          for(int i = a - 1; i >= 0; i--) tap.emplace_back(vs[i]);
          for(int i = vs.size() - 1; i > b; i--) tap.emplace_back(vs[i]);
          for(int i = b - 1; i >= min_p[idx][t]; i--) tap.emplace_back(vs[i]);
          tap.emplace_back(vs[b]);
        }
        if(idx > t) reverse(begin(tap), end(tap));
        for(auto &v : tap) ans.emplace_back(v);
      }

      rec_diff_dump(t);
      return;
    }
  }

};


int main() {
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));


  int N, S;
  cin >> N >> S;
  --S;
  A.resize(N);
  cin >> A;
  xs = A;
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(begin(xs), end(xs), A[i]) - begin(xs);
  }
  for(int i = 0; i < N; i++) {
    belong[A[i]].emplace_back(i);
  }

  for(int i = 0; i < xs.size(); i++) {
    auto &vs = belong[i];
    if(belong[i].size() == 1) {
      continue;
    }

    int sz = vs.size();
    vs.emplace_back(vs[0] + N);

    int64 v = -infll, v_p = -1;

    for(int j = 0; j < sz; j++) {
      cost[vs[j]][vs[j]] = infll;

      if(j) {
        if(chmax(v, (vs[j] - vs[j - 1]) * 2)) {
          v_p = j;
        }
      }

      int64 v2 = -infll, v2_p = -1;


      for(int k = j + 1; k < sz; k++) {

        cost[vs[k]][vs[j]] = -infll;

        if(chmax(v2, (vs[k] - vs[k - 1]) * 2)) {
          v2_p = k;
        }

        if(chmax(cost[vs[k]][vs[j]], v + (vs[k] - vs[j]))) {
          min_t[vs[k]][vs[j]] = 1;
          min_p[vs[k]][vs[j]] = v_p;
        }
        if(chmax(cost[vs[k]][vs[j]], v2 + vs[j] + (N - vs[k]))) {
          min_t[vs[k]][vs[j]] = 3;
          min_p[vs[k]][vs[j]] = v2_p;
        }

        //for(int l = 1; l <= j; l++) chmax(latte, (vs[l] - vs[l - 1]) * 2 + (vs[k] - vs[j]));
        //for(int l = k; l < sz; l++) chmax(latte, (vs[l + 1] - vs[l]) * 2 + (vs[k] - vs[j]));
        //for(int l = j + 1; l <= k; l++) chmax(latte, (vs[l] - vs[l - 1]) * 2 + vs[j] + (N - vs[k]));
      }

      int64 v3 = -infll, v3_p = -1;


      for(int k = sz - 1; k > j; k--) {
        if(chmax(v3, (vs[k + 1] - vs[k]) * 2)) {
          v3_p = k;
        }

        if(chmax(cost[vs[k]][vs[j]], v3 + vs[k] - vs[j])) {
          min_t[vs[k]][vs[j]] = 2;
          min_p[vs[k]][vs[j]] = v3_p;
        }

        cost[vs[j]][vs[k]] = cost[vs[k]][vs[j]] = 2 * N - cost[vs[k]][vs[j]];
        min_t[vs[j]][vs[k]] = min_t[vs[k]][vs[j]];
        min_p[vs[j]][vs[k]] = min_p[vs[k]][vs[j]];

      }


    }
    vs.pop_back();
  }

  int64 ret = infll;
  for(auto &t : belong[0]) chmin(ret, rec_same(t) + abs(t - S));
  //cout << ret << endl;

  for(auto &t : belong[0]) {


    if(rec_same(t) + abs(t - S) == ret) {
      rec_same_dump(t);

      int pv = S;
      vector< int > uku;
      int64 add = 0;

      for(int i = 0; i < ans.size(); i++) {
        int u = pv, v = ans[i];
        bool f = false;
        if(u > v) swap(u, v), f = true;

        int g = 0;
        if((v - u) < u + (N - v)) {
          g = v - u;
        } else {
          g = u + (N - v);
          g *= -1;
        }
        if(f) g *= -1;
        uku.emplace_back(g);
        add += abs(g);
        pv = ans[i];
      }
      cout << add << endl;
      for(auto &g : uku) {
        if(g >= 0) cout << "+" << g << endl;
        else cout << "-" << -g << endl;
      }
      return 0;
    }
  }
}