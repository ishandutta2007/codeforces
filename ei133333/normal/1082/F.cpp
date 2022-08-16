#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

struct Node {
  int weight, dep;
  vector< int > ch;

  Node(int dep) : weight(0), dep(dep), ch(10, -1) {}
};

vector< Node > nodes;
int dp1[501][11][501];

void chmax(int &a, int b) { a = max(a, b); }

int rec(int idx, int rest, int k) { // k: 
  if(rest == 0) return 0;
  if(~dp1[idx][rest][k]) return dp1[idx][rest][k];

  vector< int > child;
  for(auto &to : nodes[idx].ch) {
    if(~to) child.push_back(to);
  }


  int ret = 0;
  vector< int > dp2(rest + 1);
  for(auto &to : child) {
    vector< int > dp3(rest + 1);
    for(int j = 0; j <= rest; j++) {
      for(int l = 0; j + l <= rest; l++) {
        chmax(dp3[j + l], dp2[j] + rec(to, l, k));
      }
    }
    dp2.swap(dp3);
  }
  chmax(ret, dp2[rest]);

  dp2.assign(rest + 1, 0);
  for(auto &to : child) {
    vector< int > dp3(rest + 1);
    for(int j = 0; j <= rest; j++) {
      for(int l = 0; j + l <= rest; l++) {
        chmax(dp3[j + l], dp2[j] + rec(to, l, idx));
      }
    }
    dp2.swap(dp3);
  }

  chmax(ret, dp2[rest - 1] + (nodes[idx].dep - nodes[k].dep) * nodes[idx].weight);

  return dp1[idx][rest][k] = ret;
}


int main() {
  int N, K;
  cin >> N >> K;
  nodes.emplace_back(Node(0));
  int all = 0;
  for(int i = 0; i < N; i++) {
    string s;
    int m;
    cin >> s >> m;
    all += s.size() * m;
    int curr = 0, dep = 1;
    for(auto &c : s) {
      int &nxt = nodes[curr].ch[c - '0'];
      if(nxt < 0) {
        nxt = (int) nodes.size();
        nodes.emplace_back(Node(dep));
      }
      curr = nxt;
      nodes[curr].weight += m;
      ++dep;
    }
  }
  memset(dp1, -1, sizeof(dp1));
  cout << all - rec(0, K, 0) << endl;
}