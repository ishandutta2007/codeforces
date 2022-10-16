//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

int depth[1 + MAXN], seen[1 + MAXN], bigger[1 + MAXN], zero[1 + MAXN], toUse[1 + MAXN];

int main() {
    int n, root;
    cin >> n >> root;
    int add = 0, good = 0;
    for (int i = 1; i <= n; i++) {
        cin >> depth[i];
        if (i != root && !depth[i]) {
            add++;
            good++;
        }
        seen[depth[i]]++;
    }
    if (depth[root]) {
        add++;
        seen[depth[root]]--;
    }
    if (n == 1) {
        cout << add << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        zero[i] = zero[i - 1];
        if (!seen[i])
            zero[i]++;
        toUse[i] = toUse[i - 1];
        if (seen[i] > 1)
            toUse[i] += seen[i] - 1;
    }
    int answer = n;
    for (int i = n - 1; i >= 1; i--)
        bigger[i] = bigger[i + 1] + seen[i];
    for (int h = n - 1; h >= 1; h--) {
        int current = bigger[h + 1];
        int need = max(0, zero[h] - good - bigger[h + 1]);
        if (need <= toUse[h]) {
            current += need;
            answer = min(answer, current);
        }
    }
    answer += add;
    cout << answer << "\n";
    return  0;
}