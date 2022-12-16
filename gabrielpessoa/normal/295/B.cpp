#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int SIZE = 505;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int order[SIZE];
int d[SIZE][SIZE];
ll total[SIZE];
bool na[SIZE];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    set<int> forb;
    for(int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
        forb.insert(order[i]);
    }
    for(int k = 1; k <= n; k++) {
        na[order[n-k]] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][order[n-k]] + d[order[n-k]][j]);                
                if(na[i] && na[j]) {
                    total[n-k] += d[i][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%I64d ", total[i]);
    }
    return 0;
}