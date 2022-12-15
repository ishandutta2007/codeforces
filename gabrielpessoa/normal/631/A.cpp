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
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", b + i);
    }
        int accA = 0, accB = 0;
    for(int i = 0; i < n; i++) {
        accA |= a[i];
        accB |= b[i];
    }
    printf("%d\n", accA + accB);
    return 0;
}