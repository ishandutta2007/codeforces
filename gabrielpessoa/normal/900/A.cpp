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

const int SIZE  = 400;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    int p = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x > 0) p++;
        else neg++;
    }
    if(p <= 1 || neg <= 1) puts("Yes");
    else puts("No");
    return 0;
}