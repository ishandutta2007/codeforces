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

const long long MAXN = 100000;

long long v[1 + MAXN], n;
long long m;
vector<long long> w;

long long RaiseToPower(long long base, long long power) {
    long long answer = 1;
    while (power) {
        if (power % 2)
            answer = (answer * base) % m;
        base = (base * base) % m;
        power /= 2;
    }
    return answer;
}

bool Check(long long delta, long long &first) {
    long long y = v[1];
    long long answer = 0;
    auto it = lower_bound(w.begin(), w.end(), y);
    while (it != w.end() && *it == y) {
        y += delta;
        if (y >= m)
            y -= m;
        answer++;
        it = lower_bound(w.begin(), w.end(), y);
    }
    y = v[1];
    it = lower_bound(w.begin(), w.end(), y);
    while (it != w.end() && *it == y) {
        first = y;
        y -= delta;
        if (y < 0)
            y += m;
        answer++;
        it = lower_bound(w.begin(), w.end(), y);
    }
    if (answer == n + 1)
        return true;
    return false;
}

long long Count(long long delta) {
    long long answer = 0;
    for (long long i = 1; i <= n; i++)
        for (long long x = -delta; x <= delta; x += 2 * delta) {
            long long y = v[i] + x;
            if (y >= m)
                y -= m;
            if (y < 0)
                y += m;
            if (v[i] > y)
                continue;
            auto it = lower_bound(w.begin(), w.end(), y);
            if (it != w.end() && *it == y)
                answer++;
        }
    return answer;
}

pair<long long, long long> Solve() {
    if (n == 0)
        return make_pair(1, 1);
    if (n == 1)
        return make_pair(v[1], 1);
    sort(v + 1, v + n + 1);
    w.clear();
    for (int i = 1; i <= n; i++)
        w.push_back(v[i]);
    long long delta = v[2] - v[1];
    long long frequency = n - Count(delta);
    delta = (delta * RaiseToPower(frequency, m - 2)) % m;
    long long first;
    if (Check(delta, first))
        return make_pair(first, delta);
    else
        return make_pair(-1, -1);
}

int main() {
    cin >> m >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> v[i];
        w.push_back(v[i]);
    }
    if (n == 1) {
        cout << v[1] << " 1\n";
        return 0;
    }
    pair<long long, long long> answer = make_pair(-1, -1);
    bool change = false;
    if (2 * n >= m) {
        sort(w.begin(), w.end());
        long long pointer = 0;
        for (long long i = 0; i < m; i++) {
            auto it = lower_bound(w.begin(), w.end(), i);
            if (it == w.end() || *it != i) {
                pointer++;
                v[pointer] = i;
            }
        }
        n = m - n;
        change = true;
    }
    answer = Solve();
    if (change && answer.first > -1)
        answer.first = (answer.first + 1LL * n * answer.second) % m;
    if (answer.first == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << answer.first << " " << answer.second << "\n";
    return 0;
}