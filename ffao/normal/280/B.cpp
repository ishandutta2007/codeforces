#include <stdio.h>
#include <set>

using namespace std;

int n, a;
int num[110000];
int right[110000];
int left[110000];

struct compara {
    bool operator()(int a, int b) {
        return num[a] < num[b];
    }
};

set<int, compara> active;


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        left[i] = i-1;
        right[i] = i+1;
        active.insert(i);
    }

    int best = 0;

    while (!active.empty()) {
        int cur = *active.begin();
        active.erase(active.begin());

        if (left[cur] != -1) {
            best = max(best, num[cur] ^ num[left[cur]]);
        }
        if (right[cur] != n) {
            best = max(best, num[cur] ^ num[right[cur]]);
        }

        if (left[cur] != -1) {
            right[left[cur]] = right[cur];
        }
        if (right[cur] != n) {
            left[right[cur]] = left[cur];
        }
    }

    printf("%d\n", best);
}