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
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

bool apareceu[SIZE];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int atual = 0;
    int contador = 1;
    while(!apareceu[a]) {
        if(a * 10 / b == c) {
            printf("%d\n", contador);
            return 0;
        }
        apareceu[a] = true;
        contador++;
        a = (a * 10) % b;
    }
    printf("%d\n", -1);
    return 0;
}