#include <cstdio>
//#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int v[1 + MAXN];
bool seen[1 + MAXN];
vector<long long> cycles;

long long Gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    long long answer = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        if (!seen[i]) {
            int node = i;
            long long length = 0;
            while (!seen[node]) {
                seen[node] = true;
                node = v[node];
                length++;
            }
            if (node != i) {
                printf("-1\n");
                return 0;
            }
            if (length != 1)
                cycles.push_back(length);
        }
    for (auto &it : cycles)
        if (it % 2)
            answer = answer * it / Gcd(answer, it);
        else
            answer = answer * (it / 2) / Gcd(answer, it / 2);
    printf("%I64d\n", answer);
    return 0;
}