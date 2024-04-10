//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <class D>
struct SimplexSolution {
  D value;
  vector<D> solution;
  bool infeasible;
  bool unbounded;
};

//  TODO: shuffle variables
//  Ax <= b, cx -> max, x >= 0
template <class D>
SimplexSolution<D> simplex(vector<vector<D>> A, vector<D> b, vector<D> c) {
  static D const EPS = 1e-9;
  int n = int(b.size());
  int m = int(c.size());
  assert(int(A.size()) == n);

  auto initC = c;

  for (int r = 0; r < n; ++r) {
    assert(int(A[r].size()) == m);
    A[r].resize(n + m);
    A[r][m + r] = 1;
  }
  c.resize(n + m);

  vector<int> basis(n);
  iota(basis.begin(), basis.end(), m);
  vector<int> zeros(m);
  iota(zeros.begin(), zeros.end(), 0);

  auto pivot = [&](int col, int row) {
    int idRow = row;
    int idCol = zeros[col];
    auto coef = A[idRow][idCol];
    auto norm = 1 / coef;
    vector<int> nz;
    for (int i = 0; i < int(A[idRow].size()); ++i) {
      A[idRow][i] *= norm;
      if (fabs(A[idRow][i]) > EPS) {
        nz.push_back(i);
      }
    }
    b[idRow] *= norm;
    for (int i = 0; i < int(A.size()); ++i) {
      if (i == idRow) {
        continue;
      }
      auto kf = A[i][idCol];
      for (int j : nz) {
        A[i][j] -= A[idRow][j] * kf;
      }
      b[i] -= b[idRow] * kf;
    }
    swap(basis[row], zeros[col]);
    auto curC = c[idCol];
    if (fabs(curC) > EPS) {
      for (int i = 0; i < int(c.size()); ++i) {
        c[i] -= curC * A[idRow][i];
      }
    }
  };
  bool unbounded;
  auto runSimplex = [&] {
    unbounded = false;
    while (true) {
      int wi = -1;
      D val = -1;
      for (int i = 0; i < int(zeros.size()); ++i) {
        if (c[zeros[i]] < EPS) {
          continue;
        }
        if (wi < 0 || c[zeros[i]] > val) {
          wi = i;
          val = c[zeros[i]];
        }
      }
      if (wi < 0) {
        break;
      }
      D mval = -1;
      int mrow = -1;
      for (int j = 0; j < int(A.size()); ++j) {
        if (A[j][zeros[wi]] > EPS) {
          auto cval = b[j] / A[j][zeros[wi]];
          if (mrow < 0 || cval < mval) {
            mval = cval;
            mrow = j;
          }
        }
      }
      if (mrow < 0) {
        unbounded = true;
        return;
      }
      pivot(wi, mrow); 
    }
  };
  auto calcSolution = [&] {
    vector<D> solution(m);
    D ans = 0;
    for (int i = 0; i < int(basis.size()); ++i) {
      if (basis[i] < m) {
        solution[basis[i]] = b[i];
        ans += initC[basis[i]] * b[i];
      }
    }
    return make_pair(ans, solution);
  };
  auto fixNegativeB = [&] {
    int id = -1;
    D val = 0;
    for (int r = 0; r < n; ++r) {
      if (b[r] < -EPS && (id < 0 || b[r] < val)) {
        id = r;
        val = b[r];
      }
    }
    if (id < 0) {
      return true;
    }
    //  Ax - t = b, -t -> max
    for (auto& row : A) {
      row.push_back(-1);
    }
    zeros.push_back(n + m);
    
    auto oldC = c;
    c.push_back(-1);
    fill_n(c.begin(), n + m, 0);

    pivot(m, id);

    runSimplex();
    if (unbounded) {
      return false;
    }

    for (int i = 0; i < int(basis.size()); ++i) {
      if (basis[i] == n + m) {
        if (b[i] > EPS) {
          return false;
        }

        bool ok = false;
        for (int j = 0; j < int(zeros.size()); ++j) {
          if (fabs(A[i][zeros[j]]) > EPS) {
            pivot(j, i);
            ok = true;
            break;
          }
        }
        if (!ok) {
          return false;
        }
        break;
      }
    }

    c = oldC;

    for (auto& row : A) {
      row.pop_back();
    }
    auto it = find(zeros.begin(), zeros.end(), n + m);
    assert(it != zeros.end());
    zeros.erase(it);

    //  norm c
    for (int i = 0; i < int(basis.size()); ++i) {
      auto curC = c[basis[i]];
      if (fabs(curC) > EPS) {
        for (int j = 0; j < int(c.size()); ++j) {
          c[j] -= curC * A[i][j];
        }
      }
    }

    return true;
  };

  if (!fixNegativeB()) {
    //  infeasible
    return SimplexSolution<D>{0, vector<D>{}, true, false};
  }

  runSimplex();
  auto[ans, solution] = calcSolution();
  return SimplexSolution<D>{ans, solution, false, unbounded};
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  ll X;
  cin >> n >> X;
  vector<int> color(n);
  for (int& x : color) cin >> x;

  vector<vector<pair<int, ll>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  vector good(n, vector<bool>(n));

  for (int root = 0; root < n; ++root) {
    auto dfs = [&](auto&& self, int v, int p = -1, ll d = 0) -> void {
      good[root][v] = true;
      for (auto[u, w] : graph[v]) {
        if (u == p || d + w > X) {
          continue;
        }
        self(self, u, v, d + w);
      }
    };
    dfs(dfs, root);
  }
  vector a(2 * n + 2, vector<double>(n));
  vector<double> b(2 * n + 2);
  vector<double> c(n, -1);
  for (int v = 0; v < n; ++v) {
    b[v] = -1;
    for (int u = 0; u < n; ++u) {
      if (good[v][u]) {
        //  color[u] = 1 => want 0
        //  color[u] = 0 => want 1
        if (color[u] == 0) {
          a[v][u] = -1;
        } else {
          a[v][u] = 1;
          b[v]++;
        }
      }
    }
  }

  for (int v = 0; v < n; ++v) {
    a[n + v][v] = 1;
    b[n + v] = 1;
  }

  for (int v = 0; v < n; ++v) {
    a[2 * n][v] = 1 - 2 * color[v];
    a[2 * n + 1][v] = 2 * color[v] - 1;
  }
  auto res = simplex(a, b, c);
  if (res.infeasible) {
    cout << -1 << '\n';
  } else {
    cout << ((int) round(-res.value)) / 2 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}