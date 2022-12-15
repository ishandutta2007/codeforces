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
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

vi g[SIZE];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int melhor = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a <= melhor) {
            melhor = max(melhor, b);
        }
    }
    if(melhor == m) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}