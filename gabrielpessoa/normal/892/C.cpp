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

const int SIZE = 2005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;

int arr[SIZE];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, menorDist = INF;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int contagemZero = 0;
    for(int i = 0; i < n; i++) {
        int gd = arr[i];
        if(arr[i] == 1) {
            contagemZero++;
        }
        for(int j = i + 1; j < n; j++) {
            gd = gcd(gd, arr[j]);
            if(gd == 1) {
                menorDist = min(menorDist, j - i);
                break;
            }
        }
    }
    if(contagemZero > 0) {
        printf("%d\n", n - contagemZero);
    } else if(menorDist == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", menorDist + n - 1);
    }
    return 0;
}