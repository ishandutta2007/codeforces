#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], from[12][2];
char op[MN];

void do_op(int &x, int id) {
    if(op[id] == '|') x |= a[id];
    if(op[id] == '^') x ^= a[id];
    if(op[id] == '&') x &= a[id];
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf(" %c %d", &op[i], &a[i]);
    }

    for(int i = 0; i < 10; i++) {
        int x = (1 << i);
        for(int o = 0; o < n; o++) {
            do_op(x, o);
        }
        from[i][1] = (((1 << i) & x) ? 1 : 0);

        x = 0;
        for(int o = 0; o < n; o++) {
            do_op(x, o);
        }
        from[i][0] = (((1 << i) & x) ? 1 : 0);
    }

    vector<int> op;

    int x = 0;
    for(int i = 0; i < 10; i++) {
        if(from[i][0] == 1 && from[i][1] == 0) x |= (1 << i);
    }
    op.push_back(x);

    x = 0;
    for(int i = 0; i < 10; i++) {
        if(from[i][0] == 0 && from[i][1] == 0);
        else x |= (1 << i);
    }
    op.push_back(x);

    x = 0;
    for(int i = 0; i < 10; i++) {
        if(from[i][0] == 1 && from[i][1] == 1) x |= (1 << i);
    }
    op.push_back(x);


    printf("3\n");
    printf("^ %d\n", op[0]);
    printf("& %d\n", op[1]);
    printf("| %d\n", op[2]);

    return 0;
}