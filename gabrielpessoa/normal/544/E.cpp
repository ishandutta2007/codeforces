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

const int SIZE  = 25;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

string s[SIZE];
int custo[SIZE][SIZE];
int custoTotal[SIZE][SIZE];
int maskChar[SIZE][SIZE];
int pd[1 << 20];
int n, m;

int melhor(int mask) {
    if(~pd[mask]) return pd[mask];
    int first = -1;
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            first = i;
            break;
        }
    }
    if(first == -1) {
        return pd[mask] = 0;
    }
    int best = INF;
    for(int i = 0; i < m; i++) {
        best = min(best, custo[first][i] + melhor(mask | (1 << first)));
        best = min(best, custoTotal[first][i] + melhor(mask | maskChar[first][i]));
    }
    //printf("Custo em %d (corrigindo %d) eh %d\n", mask, first, best);
    return pd[mask] = best;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> custo[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int maior = 0;
            for(int k = 0; k < n; k++) {
                if(s[i][j] == s[k][j]) {
                    maior = max(maior, custo[k][j]);
                    custoTotal[i][j] += custo[k][j];
                    maskChar[i][j] |= 1 << k;
                }
            }
            custoTotal[i][j] -= maior;
        }
    }
    memset(pd, -1, sizeof(pd));
    cout << melhor(0) << endl;
    return 0;
}