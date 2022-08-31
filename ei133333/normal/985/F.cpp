#include<bits/stdc++.h>

using namespace std;

class SuffixArray {
  void create_begin_bucket(vector< int > &v, vector< int > &bucket) {
    fill(bucket.begin(), bucket.end(), 0);
    for(int i = 0; i < v.size(); i++)bucket[v[i]]++;
    int sum = 0;
    for(int i = 0; i < bucket.size(); i++) {
      bucket[i] += sum;
      swap(sum, bucket[i]);
    }
  }

  void create_end_bucket(vector< int > &v, vector< int > &bucket) {
    fill(bucket.begin(), bucket.end(), 0);
    for(int i = 0; i < v.size(); i++)bucket[v[i]]++;
    for(int i = 1; i < bucket.size(); i++)bucket[i] += bucket[i - 1];
  }

  void induced_sort(vector< int > &v, vector< int > &sa, int mv, vector< int > &bucket, vector< int > &is_l) {
    create_begin_bucket(v, bucket);
    for(int i = 0; i < v.size(); i++)if(sa[i] > 0 && is_l[sa[i] - 1])sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }

  void invert_induced_sort(vector< int > &v, vector< int > &sa, int mv, vector< int > &bucket, vector< int > &is_l) {
    create_end_bucket(v, bucket);
    for(int i = v.size() - 1; i >= 0; i--)if(sa[i] > 0 && !is_l[sa[i] - 1])sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }

  vector< int > sa_is(vector< int > v, int mv) {
    if(v.size() == 1)return vector< int >(1, 0);

    vector< int > is_l(v.size());
    vector< int > bucket(mv + 1);
    vector< int > sa(v.size(), -1);
    auto is_lms = [&](int x) -> bool { return x > 0 && is_l[x - 1] && !is_l[x]; };

    is_l[v.size() - 1] = 0;
    for(int i = v.size() - 2; i >= 0; i--)is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    create_end_bucket(v, bucket);
    for(int i = 0; i < v.size(); i++)if(is_lms(i))sa[--bucket[v[i]]] = i;
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);

    int cur = 0;
    vector< int > order(v.size());
    for(int i = 0; i < v.size(); i++)if(is_lms(i))order[i] = cur++;

    vector< int > next_v(cur);
    cur = -1;
    int prev = -1;
    for(int i = 0; i < v.size(); i++) {
      if(!is_lms(sa[i]))continue;
      bool diff = false;
      for(int d = 0; d < v.size(); d++) {
        if(prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
          diff = true;
          break;
        } else if(d > 0 && is_lms(sa[i] + d))break;
      }
      if(diff) {
        cur++;
        prev = sa[i];
      }
      next_v[order[sa[i]]] = cur;
    }

    vector< int > re_order(next_v.size());
    for(int i = 0; i < v.size(); i++)if(is_lms(i))re_order[order[i]] = i;
    vector< int > next_sa = sa_is(next_v, cur);
    create_end_bucket(v, bucket);
    for(int i = 0; i < sa.size(); i++)sa[i] = -1;
    for(int i = next_sa.size() - 1; i >= 0; i--)sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    return sa;
  }

  void sa_is(string &s) {
    vector< int > v(s.size() + 1);
    for(int i = 0; i < s.size(); i++)v[i] = s[i];
    sa = sa_is(v, *max_element(v.begin(), v.end()));
  }

  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for(int i = 0; i <= n; i++)rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0; i < n; i++) {
      int j = sa[rank[i] - 1];

      if(h > 0)h--;
      for(; j + h < n && i + h < n; h++) {
        if(s[j + h] != s[i + h])break;
      }
      lcp[rank[i] - 1] = h;
    }
  }

  struct segtree {
    int N;
    vector< int > dat;

    void init(vector< int > &v) {
      for(N = 1; N < v.size(); N <<= 1);
      dat.resize(N * 2, 1001001001);
      for(int i = 0; i < v.size(); i++)dat[i + N - 1] = v[i];
      for(int i = N - 2; i >= 0; i--)dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    int get_min(int a, int b, int k, int l, int r) {
      if(r <= a || b <= l)return 1001001001;
      if(a <= l && r <= b)return dat[k];
      return min(get_min(a, b, k * 2 + 1, l, (l + r) / 2), get_min(a, b, k * 2 + 2, (l + r) / 2, r));
    }

    int get_min(int a, int b) { return get_min(a, b, 0, 0, N); }
  };

  /*
  class sparse_table {
    vector< vector< int > > st;
  public:
    void init(vector< int > vec) {
      int b;
      for(b = 0; (1 << b) <= vec.size(); b++);
      st.assign(b, vector< int >(1 << b));
      for(int i = 0; i < vec.size(); i++)st[0][i] = vec[i];

      for(int i = 1; i < b; i++) {
        for(int j = 0; j + (1 << i) <= (1 << b); j++) {
          st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
    }

    int get_min(int l, int r) {
      assert(l < r);
      int b = 32 - __builtin_clz(r - l) - 1;
      return min(st[b][l], st[b][r - (1 << b)]);
    }

    sparse_table() {}

    sparse_table(vector< int > vec) { init(vec); }
  };
   */

  using Monoid = int;

  struct SegmentTree {
    int sz;
    vector< Monoid > seg;

    const Monoid M1 = 1 << 30;

    void init(vector< int > & vs)  {
      sz = 1;
      while(sz < vs.size()) sz <<= 1;
      seg.assign(2 * sz, M1);
      for(int i = 0; i < vs.size(); i++) {
        seg[i + sz] = vs[i];
      }
      for(int k = sz - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k + 0], seg[2 * k + 1]);
      }
    }
    Monoid query(int a, int b) {
      Monoid L = M1, R = M1;
      for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
        if(a & 1) L = min(L, seg[a++]);
        if(b & 1) R = min(seg[--b], R);
      }
      return min(L, R);
    }

    Monoid operator[](const int &k) const {
      return seg[k + sz];
    }
  };

public:
  SegmentTree st;
  string s;
  vector< int > sa, lcp, rank;

  void init(string &t) {
    s = t;
    sa_is(s);
    construct_lcp();
    st.init(lcp);
  }

  SuffixArray(string &t) { init(t); }

  SuffixArray() {}

  bool contain(string &t) {
    int lb = 0, ub = s.size();
    while(ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if(s.compare(sa[mid], t.size(), t) < 0)lb = mid;
      else ub = mid;
    }
    return s.compare(sa[ub], t.size(), t) == 0;
  }

  int get_lcp(int i, int j) {
    assert(i != j);
    if(rank[i] > rank[j])swap(i, j);
    return st.query(rank[i], rank[j]);
  }

  int operator[](const int idx) const {
    return sa[idx];
  }
};


vector< int > near[200000];
const int INF = 1 << 30;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;

  vector< int > buf(26, INF);
  for(int i = N - 1; i >= 0; i--) {
    buf[S[i] - 'a'] = i;
    near[i] = buf;
  }

  string x;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < S.size(); j++) {
      if(S[j] == i + 'a') x += '1';
      else x += '0';
    }
  }
  SuffixArray sa;
  sa.init(x);

  while(M--) {
    int x, y, len;
    cin >> x >> y >> len;
    if(x == y) {
      cout << "YES" << endl;
      continue;
    }
    --x, --y;
    bool table[26] = {};
    for(int i = 0; i < 26; i++) {
      if(near[x][i] >= x + len) {
        continue;
      }
      auto cc = S[y + near[x][i] - x] - 'a';

      if(table[cc]) {
        cout << "NO" << endl;
        goto end;
      }
      table[cc] = true;
      if(sa.get_lcp(i * N + x, cc * N + y) < len) {
        cout << "NO" << endl;
        goto end;
      }
    }
    cout << "YES" << endl;
    end:;
  }
}