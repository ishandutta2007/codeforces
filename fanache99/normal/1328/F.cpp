#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
const long long INF = 1000000000000000000LL;

int v[1 + MAXN];
long long sumLeft[1 + MAXN], sumRight[1 + MAXN + 1];

bool CanFind(int n, int k) {
    int length = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] != v[i - 1])
            length = 0;
        length++;
        best = max(best, length);
    }
    return best >= k;
}

long long Solve(int n, int k) {
    for (int i = 1; i <= n; i++)
        sumLeft[i] = sumLeft[i - 1] + 1LL * (i - 1) * (v[i] - v[i - 1]);
    for (int i = n; i >= 1; i--)
        sumRight[i] = sumRight[i + 1] + 1LL * (n - i) * (v[i + 1] - v[i]);
    long long answer = INF;
    int x = n - k + 1;
    while (x > 1 && v[x] == v[x - 1])
        x--;
    answer = min(answer, sumRight[x] - ((n - k + 1) - x));
    x = k;
    while (x < n && v[x] == v[x + 1])
        x++;
    answer = min(answer, sumLeft[x] - (x - k));
    for (int i = 1; i <= n; i++) {
        long long current = sumLeft[i] + sumRight[i] - (n - k);
        answer = min(answer, current);
        
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    if (CanFind(n, k))
        cout << "0\n";
    else
        cout << Solve(n, k);
    return 0;
}