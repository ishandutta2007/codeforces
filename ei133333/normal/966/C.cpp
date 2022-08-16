#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T >
struct BinaryTrieNode {
  int nxt[2];
  int exist; // 
  BinaryTrieNode() : exist(0) {
    nxt[0] = nxt[1] = -1;
  }
};

template< typename T, int MAX_LOG >
struct BinaryTrie {

  using Node = BinaryTrieNode< T >;
  vector< Node > nodes;
  int root;

  BinaryTrie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    ++nodes[node].exist;
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const T &bit, int bit_index, int node_index, int id) {
    if(bit_index == -1) {
      update_direct(node_index, id);
    } else {
      const int c = (bit >> bit_index) & 1;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(bit, bit_index - 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const T &bit, int id) {
    add(bit, MAX_LOG, 0, id);
  }

  void add(const T &bit) {
    add(bit, nodes[0].exist);
  }


  T query(T bit, int bit_index, int node_index, bool okflag = false, T bitmask = 0) {
    if(bit_index == -1) {
      --nodes[node_index].exist;
      return bitmask;
    }
    // propagate(bit_index, node_index);
    const int c = (bit >> bit_index) & 1;
    if(okflag) {
      if(~nodes[node_index].nxt[0] && nodes[nodes[node_index].nxt[0]].exist) {
        int64 get = query(bit, bit_index - 1, nodes[node_index].nxt[0], true, bitmask);
        if(~get) {
          --nodes[node_index].exist;
          return get;
        }
      }
      if(~nodes[node_index].nxt[1] && nodes[nodes[node_index].nxt[1]].exist) {
        int64 get = query(bit, bit_index - 1, nodes[node_index].nxt[1], true, bitmask | (1LL << bit_index));
        if(~get) {
          --nodes[node_index].exist;
          return get;
        }
      }
      return -1;
    }
    if(c == 1) {
      if(~nodes[node_index].nxt[0] && nodes[nodes[node_index].nxt[0]].exist) {
        int64 get = query(bit, bit_index - 1, nodes[node_index].nxt[0], okflag, bitmask);
        if(~get) {
          --nodes[node_index].exist;
          return get;
        }
      }
      return -1;
    } else {
      if(~nodes[node_index].nxt[0] && nodes[nodes[node_index].nxt[0]].exist) {
        int64 get = query(bit, bit_index - 1, nodes[node_index].nxt[0], okflag, bitmask);
        if(~get) {
          --nodes[node_index].exist;
          return get;
        }
      }
      if(~nodes[node_index].nxt[1] && nodes[nodes[node_index].nxt[1]].exist) {
        int64 get =  query(bit, bit_index - 1, nodes[node_index].nxt[1], true, bitmask | (1LL << bit_index));
        if(~get) {
          --nodes[node_index].exist;
          return get;
        }
      }
      return -1;
    }
  }
};


int main() {
  int N;
  scanf("%d", &N);
  BinaryTrie< int64, 61 > x;
  for(int i = 0; i < N; i++) {
    int64 X;
    scanf("%lld", &X);
    x.add(X);
  }

  vector< int64 > acc;
  int64 curr = 0;

  for(int i = 0; i < N; i++) {
    auto v = x.query(curr, 61, 0);
    if(v == -1) {
      cout << "No" << endl;
      return 0;
    }
    curr ^= v;
    acc.emplace_back(v);
  }

  cout << "Yes" << endl;
  for(auto &c : acc) cout << c << " ";
  cout << endl;
}