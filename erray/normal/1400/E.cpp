//stolen from ecnerwala for testing y_combinator
#include<bits/stdc++.h>
 
namespace std {
 
template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
int main() {
  using namespace std;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
  int N; cin >> N;
  vector<int64_t> A(N); for (auto& a : A) cin >> a;
 
  function<int64_t(int, int, int64_t)> f = [&](int l, int r, int64_t h) -> int64_t {
    if (l == r) return 0;
 
    int64_t vert_cost = (r-l);
 
    int m = int(min_element(A.begin()+l, A.begin()+r) - A.begin());
    assert(A[m] >= h);
    int64_t horiz_cost = f(l, m, A[m]) + f(m+1, r, A[m]) + (A[m] - h);
 
    return min(vert_cost, horiz_cost);
  };
 
  cout << f(0, N, 0) << '\n';
 
  return 0;
}