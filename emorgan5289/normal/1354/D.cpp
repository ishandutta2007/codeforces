#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() { return s; }

    void insert(int x) {
        for (x++; x <= N; x += x & -x)
            tree[x]++;
        s++;
    }

    void remove(int x) {
        for (x++; x <= N; x += x & -x)
            tree[x]--;
        s--;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

fenwick_multiset<1000005> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, q, a, k; rd(n); rd(q);
    for (int i = 0; i < n; i++) {
        rd(a); f.insert(a);
    }
    while (q--) {
        rd(k);
        if (k > 0)
            f.insert(k);
        else
            f.remove(f.get(-1-k));
    }
    cout << (f.size() ? f.get(0) : 0) << "\n";
}