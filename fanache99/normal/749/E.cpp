#include <cstdio>
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int v[1 + MAXN], n;
long long fenwick[1 + MAXN];

void Update(int x, long long value) {
    for (x; x <= n; x += (x & -x))
        fenwick[x] += value;
}

long long Query(int x) {
    long long answer = 0;
    for (x; x > 0; x -= (x & -x))
        answer += fenwick[x];
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    long long inversions = 0;
    for (int i = n; i >= 1; i--) {
        inversions += Query(v[i]);
        Update(v[i], 1);
    }
    double answer = inversions;
    double add = 0, subtract = 0, multiply = 1.0 / n / (n + 1);
    memset(fenwick, 0, sizeof(fenwick));
    for (int i = n; i >= 1; i--) {
        add += (Query(n) - Query(v[i] - 1)) * multiply * i;
        subtract += Query(v[i]) * multiply * i;
        Update(v[i], n - i + 1);
    }
    answer += add;
    answer -= subtract;
    printf("%.15f\n", answer);
    return 0;
}