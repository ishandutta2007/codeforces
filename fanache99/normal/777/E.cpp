//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

struct Circle {
    int a;
    int b;
    int h;

    bool operator < (const Circle &other) const {
        if (b != other.b)
            return b > other.b;
        return a > other.a;
    }
};

Circle v[1 + MAXN];
pair<int, int> normal[1 +2 * MAXN];
long long fenwick[1 + 2 * MAXN];

void Update(int x, long long value, int n) {
    for (x; x <= n; x += (x & -x))
        fenwick[x] = max(fenwick[x], value);
}

long long Query(int x) {
    long long answer = 0;
    for (x; x > 0; x -= (x & -x))
        answer = max(answer, fenwick[x]);
    return answer;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].h;
        normal[2 * i - 1] = make_pair(v[i].a, i);
        normal[2 * i] = make_pair(v[i].b, -i);
    }
    sort(normal + 1, normal + 2 * n + 1);
    int number = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (normal[i].first != normal[i - 1].first)
            number++;
        if (normal[i].second > 0)
            v[normal[i].second].a = number;
        else
            v[-normal[i].second].b = number;
    }
    sort(v + 1, v + n + 1);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        long long now = v[i].h + Query(v[i].b - 1);
        answer = max(answer, now);
        Update(v[i].a, now, 2 * n);
    }
    cout << answer << "\n";
    return 0;
}