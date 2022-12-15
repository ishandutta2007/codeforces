#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int melhor[SIZE];
int bit[SIZE];
int n;

void update(int idx) {
    while(idx <= n) {
        bit[idx]++;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int r = 0;
    while(idx > 0) {
        r += bit[idx];
        idx -= idx & -idx;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    int maior = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x > maior) {
            maior = x;
            melhor[maior]--;
        } else {
            if(query(x) == i - 1) {
                melhor[maior]++;
            }
        }
        update(x);
    }
    int resposta = 1;
    for(int i = 1; i <= n; i++) {
        if(melhor[i] > melhor[resposta]) {
            resposta = i;
        }
    }
    printf("%d\n", resposta);
    return 0;
}