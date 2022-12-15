#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 1005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

int a[SIZE], b[SIZE];

int main() {
    double a, b;
    int n;
    double x, y, v;
    cin >> a >> b >> n;
    double best = 1E15;
    while(n--) {
        cin >> x >> y >> v;
        best = min(best, sqrt((x-a) * (x-a) + (y-b) * (y-b))/v);
    }
    printf("%.11f\n", best);
    return 0;
}