// Example program
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
const int INF = 2000000001;

pair<int, int> v[1 + MAXN];

bool Out(int n, int x) {
    int before = -INF, delta = -INF;
    for (int i = 1; i <= n; i++) {
        if (i == x)
            continue;
        if (before != -INF) {
            int current = v[i].first - before;
            if (delta != -INF && delta != current)
                return false;
            delta = current;
        }
        before = v[i].first;
    }
    return true;
}

int d[1 + MAXN];

int Solve(int n) {
    int delta = v[2].first - v[1].first, smallest = INF, biggest = -INF;
    for (int i = 3; i <= n; i++) {
        int current = v[i].first - v[i - 1].first;
        if (current != delta) {
            smallest = min(smallest, i);
            biggest = max(biggest, i);
        }
        d[i] = current;
    }
    if (biggest - smallest > 1)
        return -1;
    if (smallest >= n)
        return -1;
    if (d[smallest] + d[smallest + 1] == delta)
        return v[smallest].second;
    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    if (Out(n, 1)) {
        cout << v[1].second << "\n";
        return 0;
    }
    if (Out(n, 2)) {
        cout << v[2].second << "\n";
        return 0;
    }
    if (Out(n, n)) {
        cout << v[n].second << "\n";
        return 0;
    }
    cout << Solve(n) << "\n";
    return 0;
}