//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const long long BASE = 181;
const long long MOD = 1000000009;

vector<int> g[1 + MAXN];
vector<pair<int, int> > edges;
queue<int> Queue;
map<pair<int, int>,int> number;
vector<long long> add[1 + MAXN], subtract[1 + MAXN];
long long code[2 * MAXN], value[2 * MAXN];
int nodes[2 * MAXN];
int degree[1 + MAXN];
long long power[10 * MAXN];
int answer[1 + MAXN];

struct Son {
    long long code;
    int nodes;
    int index;

    bool operator < (const Son &other) const {
        return code < other.code;
    }
};

unordered_map<long long, int> seen;

void Initialize(int node, int father) {
    int i = 0;
    for (auto &son : g[node]) {
        if (son != father) {
            seen[add[node][i]]++;
            Initialize(son, node);
        }
        i++;
    }
}

void DFS(int node, int father) {
    answer[node] = seen.size();
    int i = 0;
    for (auto &son : g[node]) {
        if (son != father) {
            seen[add[node][i]]--;
            if (seen[add[node][i]] == 0)
                seen.erase(add[node][i]);
            seen[subtract[node][i]]++;
            DFS(son, node);
            seen[subtract[node][i]]--;
            if (seen[subtract[node][i]] == 0)
                seen.erase(subtract[node][i]);
            seen[add[node][i]]++;
        }
        i++;
    }
}

int main() {
    power[0] = 1;
    for (int i = 1; i < 10 * MAXN; i++)
        power[i] = (power[i - 1] * BASE) % MOD;
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(make_pair(a, b));
        edges.push_back(make_pair(b, a));
    }
    for (int i = 0; i < 2 * (n - 1); i++)
        number[edges[i]] = i;
    memset(code, -1, sizeof(code));
    memset(value, -1, sizeof(value));
    memset(nodes, -1, sizeof(nodes));
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            Queue.push(number[make_pair(g[i][0], i)]);
            nodes[number[make_pair(g[i][0], i)]] = 1;
            value[number[make_pair(g[i][0], i)]] = (73 * BASE + 97) % MOD;
        }
    while (!Queue.empty()) {
        int edge = Queue.front();
        Queue.pop();
        if (code[edge] != -1)
            continue;
        int node = edges[edge].first;
        degree[node]++;
        code[edge] = value[edge];
        if (degree[node] == g[node].size() - 1) {
            int dad;
            vector<Son> sons;
            int j = 0;
            for (auto &son : g[node]) {
                if (code[number[make_pair(node, son)]] == -1)
                    dad = son;
                else
                    sons.push_back({code[number[make_pair(node, son)]], nodes[number[make_pair(node, son)]], j});
                j++;
            }
            sort(sons.begin(), sons.end());
            int current = number[make_pair(dad, node)];
            value[current] = 73;
            nodes[current] = 1;
            for (auto &son : sons) {
                value[current] = (value[current] * power[2 * son.nodes]) % MOD;
                value[current] = (value[current] + son.code) % MOD;
                nodes[current] += son.nodes;
            }
            value[current] = (value[current] * BASE + 97) % MOD;
            Queue.push(current);
        }
        else
            if (degree[node] == g[node].size()) {
                vector<Son> sons;
                int j = 0;
                for (auto &son : g[node]) {
                    sons.push_back({code[number[make_pair(node, son)]], nodes[number[make_pair(node, son)]], j});
                    j++;
                }
                sort(sons.begin(), sons.end());
                vector<long long> preffix(sons.size() + 1, 0);
                preffix[0] = 73;
                preffix[1] = (73 * BASE + sons[0].code) % MOD;
                for (int i = 1; i <= sons.size(); i++)
                    preffix[i] = (preffix[i - 1] * power[2 * sons[i - 1].nodes] + sons[i - 1].code) % MOD;
                preffix.push_back((preffix.back() * BASE + 97) % MOD);
                vector<long long> suffix(sons.size() + 2, 0);
                vector<int> suffixSize(sons.size() + 2, 0);
                suffix.back() = 97;
                for (int i = sons.size(); i > 0; i--) {
                    suffix[i] = (suffix[i + 1] + sons[i - 1].code * power[2 * suffixSize[i + 1] + 1]) % MOD;
                    suffixSize[i] = suffixSize[i + 1] + sons[i - 1].nodes;
                }
                suffix[0] = (suffix[1] + 73 * power[2 * suffixSize[1] + 1]) % MOD;
                suffixSize[0] = suffixSize[1];
                for (int i = 0; i < sons.size(); i++) {
                    int son = g[node][sons[i].index];
                    if (value[number[make_pair(son, node)]] == -1) {
                        nodes[number[make_pair(son, node)]] = n - nodes[number[make_pair(node, son)]];
                        value[number[make_pair(son, node)]] = (preffix[i] * power[2 * suffixSize[i + 2] + 1] + suffix[i + 2]) % MOD;
                        Queue.push(number[make_pair(son, node)]);
                    }
                }
            }
    }
    for (int i = 1; i <= n; i++)
        for (auto &son : g[i]) {
            add[i].push_back(code[number[make_pair(i, son)]]);
            subtract[i].push_back(code[number[make_pair(son, i)]]);
        }
    Initialize(1, 0);
    DFS(1, 0);
    int best = 0;
    for (int i = 1; i <= n; i++)
        if (answer[i] > answer[best])
            best = i;
    cout << best << "\n";
    return 0;
}