#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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


template< typename T, int MAX_LOG >
struct BinaryTrie {
  BinaryTrie *nxt[2];
  T lazy;
  int exist;
  vector< int > accept;

  BinaryTrie() : exist(0), lazy(0), nxt{nullptr, nullptr} {}

  void add(const T &bit, int bit_index, int id) {
    propagate(bit_index);
    if(bit_index == -1) {
      ++exist;
      accept.push_back(id);
    } else {
      auto &to = nxt[(bit >> bit_index) & 1];
      if(!to) to = new BinaryTrie();
      to->add(bit, bit_index - 1, id);
      ++exist;
    }
  }

  void add(const T &bit, int id) {
    add(bit, MAX_LOG, id);
  }

  void add(const T &bit) {
    add(bit, exist);
  }

  void del(const T &bit, int bit_index) {
    propagate(bit_index);
    if(bit_index == -1) {
      exist--;
    } else {
      nxt[(bit >> bit_index) & 1]->del(bit, bit_index - 1);
      exist--;
    }
  }

  void del(const T &bit) {
    del(bit, MAX_LOG);
  }


  pair< T, BinaryTrie * > max_element(int bit_index) {
    propagate(bit_index);
    if(bit_index == -1) return {0, this};
    if(nxt[1] && nxt[1]->count()) {
      auto ret = nxt[1]->max_element(bit_index - 1);
      ret.first |= T(1) << bit_index;
      return ret;
    } else {
      return nxt[0]->max_element(bit_index - 1);
    }
  }

  pair< T, BinaryTrie * > min_element(int bit_index) {
    propagate(bit_index);
    if(bit_index == -1) return {0, this};
    if(nxt[0] && nxt[0]->count()) {
      return nxt[0]->min_element(bit_index - 1);
    } else {
      auto ret = nxt[1]->min_element(bit_index - 1);
      ret.first |= T(1) << bit_index;
      return ret;
    }
  }

  T mex_query(int bit_index) { // distinct-values
    propagate(bit_index);
    if(bit_index == -1 || !nxt[0]) return 0;
    if(nxt[0]->count() == (T(1) << bit_index)) {
      T ret = T(1) << bit_index;
      if(nxt[1]) ret |= nxt[1]->mex_query(bit_index - 1);
      return ret;
    } else {
      return nxt[0]->mex_query(bit_index - 1);
    }
  }

  int64_t count_less(const T &bit, int bit_index) {
    propagate(bit_index);
    if(bit_index == -1) return 0;
    int64_t ret = 0;
    if((bit >> bit_index) & 1) {
      if(nxt[0]) ret += nxt[0]->size();
      if(nxt[1]) ret += nxt[1]->count_less(bit, bit_index - 1);
    } else {
      if(nxt[0]) ret += nxt[0]->count_less(bit, bit_index - 1);
    }
    return ret;
  }

  pair< T, BinaryTrie * > get_kth(int64_t k, int bit_index) {
    propagate(bit_index);
    if(bit_index == -1) return {0, this};
    if((nxt[0] ? nxt[0]->size() : 0) < k) {
      auto ret = nxt[1]->get_kth(k - (nxt[0] ? nxt[0]->size() : 0), bit_index - 1);
      ret.first |= T(1) << bit_index;
      return ret;
    } else {
      return nxt[0]->get_kth(k, bit_index - 1);
    }
  }

  pair< T, BinaryTrie * > max_element() {
    assert(exist);
    return max_element(MAX_LOG);
  }

  pair< T, BinaryTrie * > min_element() {
    assert(exist);
    return min_element(MAX_LOG);
  }

  T mex_query() {
    return mex_query(MAX_LOG);
  }

  int size() const {
    return exist;
  }

  void xorpush(const T &bit) {
    lazy ^= bit;
  }

  int64_t count_less(const T &bit) {
    return count_less(bit, MAX_LOG);
  }

  pair< T, BinaryTrie * > get_kth(int64_t k) {
    assert(0 < k && k <= size());
    return get_kth(k, MAX_LOG);
  }

  void propagate(int bit_index) {
    if((lazy >> bit_index) & 1) swap(nxt[0], nxt[1]);
    if(nxt[0]) nxt[0]->lazy ^= lazy;
    if(nxt[1]) nxt[1]->lazy ^= lazy;
    lazy = 0;
  }
};


int main() {
  int N, K;
  cin >> N >> K;
  BinaryTrie< int, 30 > bit;
  bit.add(0);
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    bit.xorpush(x);
    ret += (i + 1) - bit.count_less(K);
    bit.add(0);
  }
  cout << ret << endl;
}