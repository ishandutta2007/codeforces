#include<bits/stdc++.h>

using namespace std;
typedef pair< int, int > Point;
enum : int {
  CREATEY, APPEARX, DELETEY
};

struct Event {
  int y, idx, type;

  bool operator<(const Event &e) const {
    if(y == e.y) return (type < e.type);
    return (y < e.y);
  }
};

struct BinaryIndexedTree {
  vector< int > data;

  BinaryIndexedTree(int sz) {
    data.assign(sz + 2, 0);
  }

  int query(int k) {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void update(int k, int x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

struct SegmentTree {
  vector< int > isnew;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    isnew.assign(2 * sz - 1, false);
  }

  inline void AddF(const int a, const int b, int k, int l, int r) {
    if(a >= r || b <= l) {
      return;
    } else if(a <= l && r <= b) {
      isnew[k] = true;
    } else {
      AddF(a, b, 2 * k + 1, l, (l + r) >> 1);
      AddF(a, b, 2 * k + 2, (l + r) >> 1, r);
    }
  }

  inline void DelF(const int a, const int b, int k, int l, int r) {
    if(a >= r || b <= l) {
      return;
    } else if(a <= l && r <= a + 1) {
      isnew[k] = false;
    } else {
      if(isnew[k]) {
        isnew[2 * k + 1] = true;
        isnew[2 * k + 2] = true;
        isnew[k] = false;
      }
      DelF(a, b, 2 * k + 1, l, (l + r) >> 1);
      DelF(a, b, 2 * k + 2, (l + r) >> 1, r);
    }
  }

  inline void AddF(int a, int b) {
    AddF(a, b, 0, 0, sz);
  }

  inline void DelF(const int x) {
    DelF(x, x + 1, 0, 0, sz);
  }

  inline bool CheckF(int k) {
    k += sz - 1;
    if(isnew[k]) return (true);
    while(k > 0) {
      k = (k - 1) >> 1;
      if(isnew[k]) return (true);
    }
    while(k > 0);
    return (false);
  }
};

struct UnionFind {
  vector< int > data;

  UnionFind() {};

  inline int Make() {
    data.push_back(-1);
    return (data.size() - 1);
  }

  inline bool Unite(int a, int b) {
    a = Find(a), b = Find(b);
    if(a == b) return (false);
    if(data[a] > data[b]) swap(a, b);
    data[a] += data[b];
    data[b] = a;
    return (true);
  }

  inline int Find(int k) {
    if(data[k] < 0) return (k);
    else return (data[k] = Find(data[k]));
  }
};

SegmentTree *tree;
UnionFind *uf;
BinaryIndexedTree *bit;
int decode[200020];


int Evaluate(int x) {
  if(tree->CheckF(x)) {
    tree->DelF(x);
    return (uf->Make());
  } else {
    return (decode[x]);
  }
}

int Press(int *A, int sz1, int *B, int sz2) {
  vector< int > nums;
  copy(A, A + sz1, back_inserter(nums));
  copy(B, B + sz2, back_inserter(nums));
  nums.push_back(-1);
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  transform(A, A + sz1, A, [&](int x) {
    return (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
  });
  transform(B, B + sz2, B, [&](int x) {
    return (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
  });
  return (nums.size());
}

int main() {
  int W = 1000000, H = 1000000, N, M;
  int A[200004], B[200004], C[200004], D[200004];
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d %d %d", &A[i], &B[i], &D[i]);
    C[i] = A[i];
  }
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", &B[i + N], &A[i + N], &C[i + N]);
    D[i + N] = B[i + N];
  }
  N += M;


  A[N] = 0;
  B[N] = 0;
  C[N] = W;
  D[N] = 0;
  ++N;
  A[N] = 0;
  B[N] = 0;
  C[N] = 0;
  D[N] = H;
  ++N;
  A[N] = W;
  B[N] = 0;
  C[N] = W;
  D[N] = H;
  ++N;
  A[N] = 0;
  B[N] = H;
  C[N] = W;
  D[N] = H;
  ++N;

  W = Press(A, N, C, N);

  vector< Event > Events;
  for(int i = 0; i < N; i++) {
    if(A[i] == C[i]) {
      Events.push_back((Event) {B[i], i, CREATEY});
      Events.push_back((Event) {D[i], i, DELETEY});
    } else {
      Events.push_back((Event) {B[i], i, APPEARX});
    }
  }
  sort(Events.begin(), Events.end());

  set< int > pool;
  uf = new UnionFind();
  tree = new SegmentTree(W);
  bit = new BinaryIndexedTree(W);
  pool.insert(0);
  decode[0] = uf->Make();
  long long int sz = 0;

  for(int i = 0; i < Events.size(); i++) {
    const Event &e = Events[i];
    const int &x = A[e.idx];
    if(e.type == CREATEY) {
      int L = *--pool.lower_bound(x);
      decode[x] = Evaluate(x);
      decode[L] = Evaluate(L);
      decode[x] = decode[L];
      pool.insert(x);
      bit->update(x, 1);
    } else if(e.type == DELETEY) {
      int L = *--pool.lower_bound(x);
      decode[x] = Evaluate(x);
      decode[L] = Evaluate(L);
      if(uf->Unite(decode[x], decode[L])) --sz;
      pool.erase(x);
      bit->update(x, -1);
    } else {
      int x2 = C[e.idx];
      int RSQ = bit->query(x2) - bit->query(x - 1) - 1;
      if(RSQ > 0) {
        sz += RSQ;
        tree->AddF(x, *--pool.upper_bound(x2));
      }
    }
  }
  cout << sz << "\n";
}