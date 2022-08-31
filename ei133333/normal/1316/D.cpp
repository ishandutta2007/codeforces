#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

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

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

void fail() {
  cout << "INVALID\n";
  exit(0);
}

const string VS = "UDLRX";
const int vy[] = {-1, 1, 0, 0, 0};
const int vx[] = {0, 0, -1, 1, 0};

int main() {
  int N;
  cin >> N;
  auto Y = make_v< int >(N, N);
  auto X = make_v< int >(N, N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> Y[i][j] >> X[i][j];
      if(~Y[i][j]) --Y[i][j];
      if(~X[i][j]) --X[i][j];
    }
  }


  vector< vector< vector< pair< int, int > > > > goal(N, vector< vector< pair< int, int > > >(N));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(~Y[i][j]) goal[Y[i][j]][X[i][j]].emplace_back(i, j);
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(goal[i][j].size()) if(Y[i][j] != i || X[i][j] != j) fail();
    }
  }


  auto used = make_v< int >(N, N);
  fill_v(used, -1);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(goal[i][j].size()) {
        queue< pair< int, int > > que;
        que.emplace(i, j);
        used[i][j] = 4;
        int add = 0;
        while(que.size()) {
          auto y = que.front().first;
          auto x = que.front().second;
          que.pop();
          ++add;
          for(int k = 0; k < 4; k++) {
            int ny = y + vy[k];
            int nx = x + vx[k];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if(used[ny][nx] != -1) continue;
            if(Y[ny][nx] == i && X[ny][nx] == j) {
              que.emplace(ny, nx);
              used[ny][nx] = k ^ 1;
            }
          }
        }
        if(add != goal[i][j].size()) fail();
      }
    }
  }


  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(used[i][j] == -1) {
        bool flag = false;
        for(int k = 0; k < 4; k++) {
          int ny = i + vy[k];
          int nx = j + vx[k];
          if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
          if(Y[ny][nx] == -1) {
            used[i][j] = k;
            flag = true;
            break;
          }
        }
        if(!flag) fail();
        queue< pair< int, int > > que;
        que.emplace(i, j);
        while(que.size()) {
          auto y = que.front().first;
          auto x = que.front().second;
          que.pop();
          for(int k = 0; k < 4; k++) {
            int ny = y + vy[k];
            int nx = x + vx[k];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if(used[ny][nx] != -1) continue;
            if(Y[ny][nx] == -1 && X[ny][nx] == -1) {
              que.emplace(ny, nx);
              used[ny][nx] = k ^ 1;
            }
          }
        }
      }
    }
  }

  cout << "VALID\n";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << VS[used[i][j]];
    }
    cout << "\n";
  }
}