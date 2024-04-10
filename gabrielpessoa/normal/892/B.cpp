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

const int SIZE = 1E6+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;

int claw[SIZE];
int morto[SIZE];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", claw + i);
    }
    int vivos = 0, quantosMatar = 0;
    for(int i = n -1; i >= 0; i--) {
        if(!quantosMatar) {
            vivos++;
        }
        quantosMatar = max(quantosMatar - 1, claw[i]);
    }
    printf("%d\n", vivos);
    return 0;
}