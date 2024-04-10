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

const int SIZE  = 30;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

bool letra[SIZE];
string s[SIZE];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if(k > (n * n + 1) / 2) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!k || ((i + j) & 1)) {
                printf("S");
            } else {
                printf("L");
                k--;
            }
        }
        printf("\n");
    }
    return 0;
}