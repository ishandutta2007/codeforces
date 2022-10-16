    #include <algorithm>
    #include <cassert>
    #include <iostream>
    #include <memory>
    #include <numeric>
     
    #include <array>
    #include <deque>
    #include <map>
    #include <set>
    #include <tuple>
    #include <unordered_map>
    #include <unordered_set>
    #include <vector>
     
    #include <cstring>
    #include <ostream>
    #include <type_traits>
    #include <utility>
    #include <chrono>
    #include <random>
     
    #ifdef ONLINE_JUDGE
    #pragma GCC optimize ("O2")
    #pragma GCC target ("avx,avx2")
    #endif
     
    using namespace std;
     
    using uint64 = uint64_t;
    using int64 = int64_t;
    using uint32 = uint32_t;
    using vi = vector<int>;
     
    #define seq(i,a,b) for (int i = (a); i < (b); ++i)
    #define rev(i,a,b) for (int i = (b)-1; i >= (a); --i)
    #define sz(x) ((int)x.size())
    #define all(x) x.begin(), x.end()
    #define dbg(x) {cerr << #x << ": " << x << endl;}
     
    int main(int argc, char *argv[])
    {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
     
      int n,m; cin >> n >> m;
      vi A(n);
      for (auto &x : A) cin >> x;
      vi B(m);
      for (auto &x : B) cin >> x;
      
      vector<vi> cands;
      for (auto x : A) cands.push_back(B);
     
      int res = 0;
      rev(bs,0,11) {
        bool can = true;
        seq(i,0,n) {
          int a = A[i];
          if ((a & (1<<bs)) && all_of(all(cands[i]), [&](int x) { return x & (1<<bs); })) {
            can = false;
            break;
          }
        }
        if (!can) {
          res |= 1<<bs;
          continue;
        }
        seq(i,0,n) {
          int a = A[i];
          if (a & (1<<bs)) {
            // Must pick zero
            cands[i].erase(remove_if(all(cands[i]), [&](int x) { return x & (1<<bs); }), cands[i].end());
          } else {
            // Do whatever
          }
        }
      }
      cout << res << endl;
    }