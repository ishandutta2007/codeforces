#include <bits/stdc++.h>

using namespace std;

int n, a[1010], x[1010];

int fim() {
    printf("0\n");
    fflush(stdout);
    exit(0);
}

void cmon(int b) {
    vector<int> on;
    for(int i = 1; i < n; i++) {
        if(i % b != 0 && a[i] == 0) on.push_back(i), a[i] = 1;
    }

    if(on.size() < b) fim();

    printf("%d", on.size());
    for(int x : on) printf(" %d", x);
    puts("");
    fflush(stdout);

    int x;
    scanf("%d", &x);
    for(int i = 0; i < on.size(); i++) {
        a[x] = 0;
        x++;
        if(x > n) x = 1;
    }
}

int sim(int b) {
    memset(x, 0, sizeof x);
    int quant = 0;
    while(1) {
        int sz = 0;
        for(int i = 1; i < n; i++) {
            if(i % b != 0 && x[i] == 0) sz++, x[i] = 1, quant++;
        }

        if(sz < b) return quant - sz;

        for(int i = 1; i <= sz; i++) {
            if(x[i] == 1) {
                x[i] = 0;
                quant--;
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    int b = 2, v = sim(2);
    for(int i = 3; i <= n; i++) {
        int y = sim(i);
        if(y > v) {
            v = y;
            b = i;
        }
        //cerr << i << " - " << y << endl;
    }

    cerr << "best is " << b << endl;
    while(1) cmon(b);
    return 0;
}