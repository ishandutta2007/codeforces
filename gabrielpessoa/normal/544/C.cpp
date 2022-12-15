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

const int SIZE  = 501;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

ll mod;
ll pd[SIZE][SIZE];
int bugsLinha[SIZE];
int n;

int main() {
    int m, b;
    //memset(pd, -1, sizeof(pd));
    scanf("%d %d %d %lld", &n, &m, &b, &mod);
    for(int i = 0; i < n; i++) {
        scanf("%d", &bugsLinha[i]);
    }
    for(int i = 0; i <= b; i++) {
        pd[0][i] = 1;
    }
    for(int pessoa = 0; pessoa < n; pessoa++) {
        for(int linha = 1; linha <= m; linha++) {
            for(int bug = 0; bug <= b; bug++) {
                if(bugsLinha[pessoa] <= bug) {
                    pd[linha][bug] = (pd[linha][bug] + pd[linha - 1][bug-bugsLinha[pessoa]]) % mod;
                }
            }
        }
    }
    printf("%lld\n", pd[m][b]);
    return 0;
}