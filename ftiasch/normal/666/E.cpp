#include <bits/stdc++.h>

using Set = std::set<std::pair<int, int>>;

const int N = 500000;
const int C = 26;

struct State;
struct Node;

std::vector<State *> states;

struct State {
  State(int length) : length(length), parent(NULL) {
    states.push_back(this);
    memset(go, 0, sizeof(go));
    queries = new Set();
  }

  State *extend(State *start, int token) {
    State *p = this;
    State *np = new State(length + 1);
    while (p && !p->go[token]) {
      p->go[token] = np;
      p = p->parent;
    }
    if (!p) {
      np->parent = start;
    } else {
      State *q = p->go[token];
      if (p->length + 1 == q->length) {
        np->parent = q;
      } else {
        State *nq = new State(p->length + 1);
        memcpy(nq->go, q->go, sizeof(q->go));
        nq->parent = q->parent;
        np->parent = q->parent = nq;
        while (p && p->go[token] == q) {
          p->go[token] = nq;
          p = p->parent;
        }
      }
    }
    return np;
  }

  int length, id = -1;
  State *parent;
  State *go[C];
  std::vector<State *> children;
  Set *queries;
};

Node *null;

struct Node {
  Node(const std::pair<int, int> &maximum, Node *left, Node *right)
      : maximum(maximum), left(left), right(right) {}

  Node *insert(int l, int r, int k) {
    if (k < l || r < k) {
      return this;
    }
    if (l == r) {
      return new Node(std::make_pair(maximum.first + 1, -l), null, null);
    }
    int m = l + r >> 1;
    auto p = left->insert(l, m, k);
    auto q = right->insert(m + 1, r, k);
    return new Node(std::max(p->maximum, q->maximum), p, q);
  }

  std::pair<int, int> query(int l, int r, int a, int b) {
    if (b < l || r < a) {
      return {0, -1e9};
    }
    if (a <= l && r <= b) {
      return maximum;
    }
    int m = l + r >> 1;
    return std::max(left->query(l, m, a, b), right->query(m + 1, r, a, b));
  }

  std::pair<int, int> maximum;
  Node *left, *right;
};

Node *merge(Node *a, Node *b, int l, int r) {
  if (a == null) {
    return b;
  }
  if (b == null) {
    return a;
  }
  if (l == r) {
    return new Node(std::make_pair(a->maximum.first + b->maximum.first, -l),
                    null, null);
  }
  int m = l + r >> 1;
  auto p = merge(a->left, b->left, l, m);
  auto q = merge(a->right, b->right, m + 1, r);
  return new Node(std::max(p->maximum, q->maximum), p, q);
}

Set *merge(Set *p, Set *q) {
  if (p->size() < q->size()) {
    std::swap(p, q);
  }
  for (auto &&elem : *q) {
    p->insert(elem);
  }
  return p;
}

int n, query_l[N], query_r[N];
std::pair<int, int> answer[N];
char buf[N + 1];
State *end[N];

Node *dfs(State *s) {
  Node *result = null;
  auto &queries = s->queries;
  if (~s->id) {
    result = result->insert(1, n, s->id);
  }
  for (auto p : s->children) {
    result = merge(result, dfs(p), 1, n);
    queries = merge(queries, p->queries);
  }
  while (!queries->empty()) {
    auto q = queries->rbegin();
    if (q->first <= s->parent->length) {
      break;
    }
    int id = q->second;
    answer[id] = result->query(1, n, query_l[id], query_r[id]);
    queries->erase(*q);
  }
  return result;
}

int main() {
  null = new Node({0, -1e9}, NULL, NULL);
  null->left = null->right = null;
  scanf("%s", buf);
  auto start = new State(0);
  auto p = start;
  for (int i = 0; buf[i]; ++i) {
    p = p->extend(start, buf[i] - 'a');
    end[i] = p;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", buf);
    p = start;
    for (int j = 0; buf[j]; ++j) {
      p = p->extend(start, buf[j] - 'a');
      p->id = i;
    }
  }
  for (auto p : states) {
    if (p->parent != NULL) {
      p->parent->children.push_back(p);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d%d%d", query_l + i, query_r + i, &l, &r);
    end[r - 1]->queries->emplace(r - l + 1, i);
  }
  dfs(start);
  for (int i = 0; i < q; ++i) {
    if (answer[i].second == -1e9) {
      answer[i] = {0, -query_l[i]};
    }
    printf("%d %d\n", -answer[i].second, answer[i].first);
  }
}