#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

vector<string> rotate(vector<string> s) {
  int h = s.size(), w = s[0].size();
  vector<string> t(w, string(h, '?'));
  rep (i, h) {
    rep (j, w) {
      t[j][i] = s[i][j];
    }
  }
  return t;
}

ll best = INF;
int bestm = -1;
int besti = -1;

ll solve(vector<string> s, int m, string p1, string p2) {
  int h = s.size(), w = s[0].size();
  ll sum = 0;
  rep (i, h) {
    string p;
    if (i % 2 == 0) {
      p = p1;
    }
    else {
      p = p2;
    }
    int temp1 = 0, temp2 = 0;
    rep (j, w) {
      if (j % 2 == 0) {
        if (s[i][j] != p[0]) temp1++;
        if (s[i][j] != p[1]) temp2++;
      }
      else {
        if (s[i][j] != p[1]) temp1++;
        if (s[i][j] != p[0]) temp2++;
      }
    }
    sum += min(temp1, temp2);
  }
  return sum;
}

vector<string> solve2(vector<string> s, int m, string p1, string p2) {
  int h = s.size(), w = s[0].size();
  ll sum = 0;
  rep (i, h) {
    string p;
    if (i % 2 == 0) {
      p = p1;
    }
    else {
      p = p2;
    }
    int temp1 = 0, temp2 = 0;
    rep (j, w) {
      if (j % 2 == 0) {
        if (s[i][j] != p[0]) temp1++;
        if (s[i][j] != p[1]) temp2++;
      }
      else {
        if (s[i][j] != p[1]) temp1++;
        if (s[i][j] != p[0]) temp2++;
      }
    }
    if (temp1 < temp2) {
      rep (j, w) {
        if (j % 2 == 0) {
          s[i][j] = p[0];
        }
        else {
          s[i][j] = p[1];
        }
      }
    }
    else {
      rep (j, w) {
        if (j % 2 == 0) {
          s[i][j] = p[1];
        }
        else {
          s[i][j] = p[0];
        }
      }
    }      
  }
  return s;
}


int main() {
  fio();
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep (i, h) {
    cin >> s[i];
  }
  vector<string> i2s1 = {"AG", "AC", "AT", "GC", "GT", "CT"};
  vector<string> i2s2 = {"CT", "GT", "GC", "AT", "AC", "AG"};
  if (min(h, w) == 2) {
    bool flag = false;
    if (w < h) {
      swap(h, w);
      s = rotate(s);
      flag = true;
    }
    ll mi = INF;
    int idx = -1;
    rep (i, 6) {
      string p1 = i2s1[i], p2 = i2s2[i];
      ll sum = 0;
      rep (j, w) {
        ll temp1 = 0, temp2 = 0;
        if (j % 2 == 0) {
          if (s[0][j] != p1[0]) temp1++;
          if (s[1][j] != p1[1]) temp1++;
          if (s[0][j] != p1[1]) temp2++;
          if (s[1][j] != p1[0]) temp2++;
        }
        else {
          if (s[0][j] != p2[0]) temp1++;
          if (s[1][j] != p2[1]) temp1++;
          if (s[0][j] != p2[1]) temp2++;
          if (s[1][j] != p2[0]) temp2++;
        }
        sum += min(temp1, temp2);
      }
      if (sum < mi) {
        mi = sum;
        idx = i;
      }
    }
    string p1 = i2s1[idx], p2 = i2s2[idx];
    ll sum = 0;
    rep (j, w) {
      ll temp1 = 0, temp2 = 0;
      if (j % 2 == 0) {
        if (s[0][j] != p1[0]) temp1++;
        if (s[1][j] != p1[1]) temp1++;
        if (s[0][j] != p1[1]) temp2++;
        if (s[1][j] != p1[0]) temp2++;
        if (temp1 < temp2) {
          s[0][j] = p1[0];
          s[1][j] = p1[1];
        }
        else {
          s[0][j] = p1[1];
          s[1][j] = p1[0];
        }
      }
      else {
        if (s[0][j] != p2[0]) temp1++;
        if (s[1][j] != p2[1]) temp1++;
        if (s[0][j] != p2[1]) temp2++;
        if (s[1][j] != p2[0]) temp2++;
        if (temp1 < temp2) {
          s[0][j] = p2[0];
          s[1][j] = p2[1];
        }
        else {
          s[0][j] = p2[1];
          s[1][j] = p2[0];
        }
      }
    }
    if (flag) {
      s = rotate(s);
      swap(h, w);
    }
    rep (i, h) {
      cout << s[i] << endl;
    }
    return 0;
  }

  rep (i, 6) {
    string p1 = i2s1[i], p2 = i2s2[i];
    ll res = solve(s, 0, p1, p2);
    if (res < best) {
      best = res;
      bestm = 0;
      besti = i;
    }
  }
  s = rotate(s);
  rep (i, 6) {
    string p1 = i2s1[i], p2 = i2s2[i];
    ll res = solve(s, 1, p1, p2);
    if (res < best) {
      best = res;
      bestm = 1;
      besti = i;
    }
  }
  string p1 = i2s1[besti], p2 = i2s2[besti];
  if (bestm == 0) {
    s = rotate(s);
  }
  s = solve2(s, bestm, p1, p2);
  if (bestm == 1) {
    s = rotate(s);
  }
  rep (i, s.size()) {
    cout << s[i] << endl;
  }
}