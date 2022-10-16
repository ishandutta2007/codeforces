#include <cstdio>
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN];
vector<int> warm;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, negative = 0, length = 0;
    bool first = true;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] < 0) {
            negative++;
            if (v[i - 1] >= 0)
                if (first) {
                    first = false;
                    length = 0;
                }
                else {
                    warm.push_back(length);
                    length = 0;
                }
        }
        else
            length++;
    }
    int last = length;
    if (negative > k) {
        printf("-1\n");
        return 0;
    }
    if (negative == 0) {
        printf("0\n");
        return 0;
    }
    k -= negative;
    int total = 1 + 2 * warm.size();
    if (last)
        total++;
    sort(warm.begin(), warm.end());
    int current = total, free = k;
    for (int i = 0; i < warm.size() && warm[i] <= free; i++) {
        free -= warm[i];
        current -= 2;
    }
    int answer = current;
    if (last && last <= k) {
        current = total - 1;
        free = k - last;
        for (int i = 0; i < warm.size() && warm[i] <= free; i++) {
            free -= warm[i];
            current -= 2;
        }
        answer = min(answer, current);
    }
    printf("%d\n", answer);
    return 0;
}