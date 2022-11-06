#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;


struct Merger {
  ii operator()(ii a, ii b) { return make_pair(min(a.first, b.first), max(a.second, b.second)); }
};

template <class T, class Merger>
class SparseTable {
 public:
  void init(vector<T> a) {
     table.clear(); get.clear();
    int e = 0;
    int n = a.size();
    while((1 << e) / 2 < a.size()) {
      e++;
    }
    table.resize(e, vector<T>(n));
    get.assign(n + 1, -1);
    for(int i = 0; i < n; i++) {
      table[0][i] = a[i];
      get[i + 1] = get[(i + 1) / 2] + 1;
    }
    for(int i = 0; i + 1 < e; i++) {
      for(int j = 0; j + (1 << i) < n; j++) {
        table[i + 1][j] = merge(table[i][j], table[i][j + (1 << i)]);
      }
    }
  }

  T qry(int l, int r) {
    int e = get[r - l];
   //  if(l == 4) cout << l << " e " << r << " vai dar " << table[e][l] << " e " <<  table[e][r - (1 << e)] << " = " << merge(table[e][l], table[e][r - (1 << e)]) << endl;
    return merge(table[e][l], table[e][r - (1 << e)]);
  }

 private:
  vector<vector<T>> table;
  vector<int> get;
  Merger merge;
};





SparseTable<ii, Merger> st;
vector<int> a;
vector<ii> hlp;
struct Merger2 {
  int operator()(int x, int y) { return ii(a[x], x) > ii(a[y], y) ? x : y; }
};
SparseTable<int, Merger2> aux;

bool magic(int l, int r) {
   if(r <= l) return true;
   // cout << l << " " << r << endl;
   int mi = aux.qry(l, r);
   // cout << l << " " << r << " " << mi << endl;
   if(mi > l && st.qry(l, mi).first < hlp[mi].first) {
      // cout << "fail " << st.qry(l, mi).first << endl;
      return false;
   }
   if(r > mi+1 && st.qry(mi+1, r).second > hlp[mi].second) {
      // cout << mi+1 << " e "<< r << endl;
      // cout << hlp[mi+1].second << " f " << endl;
      // cout << "fail2 " << hlp[mi].second << " e " << st.qry(mi+1, r).second << endl;
      return false;
   }
   return magic(l, mi) && magic(mi+1, r);
}

void solve() {
   int n;
   cin >> n;
   a.resize(n); hlp.resize(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      hlp[i].second = a[i];
      if(i) hlp[i].second += hlp[i-1].second;
   }
   for(int i = 0; i < n; i++) {
      if(i) hlp[i].first = hlp[i-1].second;
      else hlp[i].first = 0;
      // cout << hlp[i].first << " " << hlp[i].second << endl;
   }
   st.init(hlp);
   vector<int> mia;
   for(int i = 0; i < n; i++) mia.emplace_back(i);
   aux.init(mia);
   if(magic(0, n)) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}