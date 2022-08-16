#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Node {
  int idx;
  char t;
  bool val;
  Node *l, *r, *p;
  int dp;
};

bool dfs(Node *ptr) {
  if(ptr->t == 'B') {
    ptr->dp = ptr->val;
    return ptr->val;
  } else if(ptr->t == '!') {
    auto r = !dfs(ptr->r);
    ptr->dp = r;
    return r;
  } else {
    auto l = dfs(ptr->l);
    auto r = dfs(ptr->r);
    bool val = 0;
    if(ptr->t == '&') {
      val = l & r;
    } else if(ptr->t == '|') {
      val = l | r;
    } else {
      val = l ^ r;
    }
    ptr->dp = val;
    return val;
  }
}

int dp[1000000][2][2];

int dfs2(Node *ptr, Node *child, bool flag) {
  if(ptr == nullptr) {
    return flag;
  }
  int &t = dp[ptr->idx][flag][child == ptr->r];
  if(~t) {
    return t;
  } else if(ptr->t == '!') {
    return t = dfs2(ptr->p, ptr, flag ^ 1);
  } else if(ptr->t == '&') {
    if(child == ptr->l) return t = dfs2(ptr->p, ptr, flag & (ptr->r->dp));
    else return t = dfs2(ptr->p, ptr, flag & (ptr->l->dp));
  } else if(ptr->t == '|') {
    if(child == ptr->l) return t = dfs2(ptr->p, ptr, flag | (ptr->r->dp));
    else return t = dfs2(ptr->p, ptr, flag | (ptr->l->dp));
  } else if(ptr->t == '^') {
    if(child == ptr->l) return t = dfs2(ptr->p, ptr, flag ^ (ptr->r->dp));
    else return t = dfs2(ptr->p, ptr, flag ^ (ptr->l->dp));
  }
}

Node *beet[1000000];

int main() {
  int N;
  char buf[5];

  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    beet[i] = new Node();
    beet[i]->idx = i;
    beet[i]->p = nullptr;
  }

  for(int i = 0; i < N; i++) {
    scanf(" %s", buf);
    if(buf[0] == 'I') {
      int x;
      scanf("%d", &x);
      beet[i]->t = 'B';
      beet[i]->val = x;
    } else if(buf[0] == 'N') {
      int x;
      scanf("%d", &x);
      --x;
      beet[i]->t = '!';
      beet[i]->r = beet[x];
      beet[i]->r->p = beet[i];
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      --x, --y;
      beet[i]->l = beet[x];
      beet[i]->r = beet[y];
      beet[i]->l->p = beet[i];
      beet[i]->r->p = beet[i];
      if(buf[0] == 'A') {
        beet[i]->t = '&';
      } else if(buf[0] == 'O') {
        beet[i]->t = '|';
      } else {
        beet[i]->t = '^';
      }
    }
  }
  dfs(beet[0]);
  string x;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; i++) {
    if(beet[i]->t == 'B') {
      auto ret = dfs2(beet[i]->p, beet[i], !beet[i]->val);
      x += ret ? '1' : '0';
    }
  }
  cout << x << endl;
}