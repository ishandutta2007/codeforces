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

int ultVis[SIZE];

int main() {
    int n;
    scanf("%d", &n);
    memset(ultVis, 63, sizeof(ultVis));
    int maior = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ultVis[x] = i;
        maior = max(maior, x);
    }
    int menor = INF;
    int menorPos = -1;
    for(int i = 0; i <= maior; i++) {
        if(ultVis[i] < menor) {
            menor = ultVis[i];
            menorPos = i;
        }
    }
    printf("%d\n", menorPos);
    return 0;
}