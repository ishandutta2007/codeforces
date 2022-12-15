#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 2E5+5;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll fact = 1E9+7;

bool vis[SIZE];

int main() {
    int n;
    scanf("%d", &n);
    int quantidade = 1;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if(!vis[x]) {
            vis[x] = true;
        } else {
            quantidade++;
        }
    }
    printf("%d\n", quantidade);
    return 0;
}