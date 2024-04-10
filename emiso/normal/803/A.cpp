#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, c;
bool um[110][110];

void descasca() {
    for(int i=c; i<n; i++) {
        um[i][c] = true;
        um[c][i] = true;
    }
    c++;
}

void borda() {
    int i = c;
    while(um[c][i] == 1) i++;

    um[i][c] = true;
    um[c][i] = true;
}

int main() {
    scanf("%d %d", &n, &k);

    if(k > n * n) {
        printf("-1\n");
        return 0;
    }

    int casca = n + n - 1;
    while(k >= casca && casca > 0) {
        descasca();
        k -= casca;
        casca -= 2;
    }

    if(k) {
        um[c][c] = 1;
        k--;
    }
    while(k) {
        if(k % 2) {
            um[c+1][c+1] = 1;
            k--;
        }

        else {
            borda();
            k -= 2;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++)
            printf("%d ", um[i][j]);
        puts("");
    }

    return 0;
}