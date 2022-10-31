#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

lint get(lint i) {
    return (i + 1) * i / 2;
}

int main() {
    int n; lint k;
    scanf("%d %lld", &n, &k);
    if (get(n-1) < k) printf("Impossible\n");
    else {
        int out = 0;
        lint x = get(n-1), siz = n-1;
        while (x - k >= siz && siz > 0 && x - k > 0) {
            out++;
            x -= siz;
            siz--;
        }


        for (int i = 0; i < out; i++) printf("()");
        if (x - k == 0) {
            for (int i = 0; i < n - out; i++) printf("(");
            for (int i = 0; i < n - out; i++) printf(")");
        }
        else {
            for (int i = 0; i < n - out - 1 - (x - k); i++) printf("(");
            printf("()");
            for (int i = 0; i < x - k; i++) printf("(");
            for (int i = 0; i < n - out - 1; i++) printf(")");
        }

        printf("\n");
    }
    return 0;
}