#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN], gt[1 + MAXN];
char answer[1 + MAXN];
int inDegree[1 + MAXN];
bool seenFront[1 + MAXN], seenBack[1 + MAXN];

void frontDFS(int node) {
    seenFront[node] = true;
    for (auto it : g[node])
        if (!seenFront[it])
            frontDFS(it);
}

void backDFS(int node) {
    seenBack[node] = true;
    for (auto it : gt[node])
        if (!seenBack[it])
            backDFS(it);
}

bool cycle(int n) {
    queue<int> q;
    int visited = 0;
    for (int i = 1; i <= n; i++)
        if (!inDegree[i])
            q.push(i);
    while (!q.empty()) {
        visited++;
        int node = q.front();
        q.pop();
        for (auto it : g[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    return visited != n;
}

int main(){
    //ifstream cin("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].emplace_back(a);
        inDegree[a]++;
        gt[a].emplace_back(b);
    }
    if (cycle(n)) {
        cout << "-1\n";
        return 0;
    }
    int universals = 0;
    for (int i = 1; i <= n; i++) {
        if (!seenFront[i] && !seenBack[i]) {
            universals++;
            answer[i] = 'A';
        } else
            answer[i] = 'E';
        frontDFS(i);
        backDFS(i);
    }
    cout << universals << "\n" << answer + 1 << "\n";
    return 0;
}