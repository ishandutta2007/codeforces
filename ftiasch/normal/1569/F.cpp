#include <bits/stdc++.h>

namespace {

using State = std::vector<int8_t>;

int n, m, k;
std::vector<State> states;
std::vector<std::vector<std::vector<int>>> trans;
std::map<State, int> state_id;

int get_state_id(const State &s) {
  auto iterator = state_id.find(s);
  if (iterator == state_id.end()) {
    iterator = state_id.emplace(s, states.size()).first;
    states.push_back(s);
  }
  return iterator->second;
}

const int N = 12;
const int S1 = 140152;

std::vector<int> graph[N];
bool dp[S1][N][N];

std::vector<bool> ok;

void dfs(const State &s) {
  int old_count = states.size();
  int sid = get_state_id(s);
  if (sid == old_count) {
    ok.push_back(false);
  }
  if (!ok[sid]) {
    ok[sid] = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == i) {
        for (int j = i + 1; j < n; ++j) {
          if (s[j] == j) {
            State t(s);
            for (int k = 0; k < n; ++k) {
              if (t[k] == j) {
                t[k] = i;
              }
            }
            dfs(t);
          }
        }
      }
    }
  }
}

} // namespace

int main() {
  auto t0 = std::chrono::high_resolution_clock::now();
  scanf("%d%d%d", &n, &m, &k);
  get_state_id(State(n, -1));
  for (int sid = 0; sid < static_cast<int>(states.size()); ++sid) {
    State s = states[sid];
    trans.push_back(std::vector<std::vector<int>>(n, std::vector<int>(n, -1)));
    for (int i = 0; i < n; ++i) {
      if (s[i] == -1) {
        for (int j = i + 1; j < n; ++j) {
          if (s[j] == -1) {
            State t(s);
            t[i] = t[j] = i;
            trans[sid][i][j] = get_state_id(t);
          }
        }
      }
    }
  }
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (a > b) {
      std::swap(a, b);
    }
    graph[a].push_back(b);
    graph[b].push_back(a);
    dp[trans[0][a][b]][a][b] = true;
  }
  for (int sid = 0; sid < static_cast<int>(states.size()); ++sid) {
    const State &state = states[sid];
    for (int i = 0; i < n; ++i) {
      if (~state[i]) {
        for (int j = i + 1; j < n; ++j) {
          // if (state[j] == -1) {
          //   dump(state) << "->";
          //   dump(states[trans[sid][i][j]]) << std::endl;
          // }
          if (dp[sid][i][j]) {
            for (int u : graph[i]) {
              if (state[u] == -1) {
                for (int v : graph[j]) {
                  if (state[v] == -1 && u != v) {
                    if (u < v) {
                      dp[trans[sid][u][v]][u][v] = true;
                    } else {
                      dp[trans[sid][v][u]][v][u] = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ok.resize(states.size());
  int s1 = states.size();
  for (int sid = 0; sid < s1; ++sid) {
    State state = states[sid];
    bool local_ok = false;
    if (std::find(state.begin(), state.end(), -1) == state.end()) {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (dp[sid][i][j]) {
            local_ok = true;
          }
        }
      }
      if (local_ok) {
        dfs(state);
      }
    }
  }
  std::vector<long long> count(n / 2 + 1);
  count[0] = 1;
  for (int i = 0; i < n / 2; ++i) {
    count[i + 1] = count[i] * (k - i);
  }
  long long result = 0;
  for (int sid = 0; sid < static_cast<int>(states.size()); ++sid) {
    const State &state = states[sid];
    if (ok[sid]) {
      int comp = 0;
      for (int k = 0; k < n; ++k) {
        comp += state[k] == k;
      }
      result += count[comp];
    }
  }
  std::cout << result << std::endl;
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cerr
      << "Elapsed "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << " ms" << std::endl;
}