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

int sumImpar[SIZE];
int sumPar[SIZE];
char s[SIZE];
ii pd[SIZE];
int n, m;

int valido(int p) {
    if(p+m > n) return -1;
    int pares = sumPar[p+m] - sumPar[p];
    int impar = sumImpar[p+m] - sumImpar[p];
    if(p % 2 && pares || !(p % 2) && impar) return -1;
    if(p % 2) return m - impar;
    return m - pares;
}

ii search(int pos = 0) {
    if(pos == n) return ii(1, 0);
    if(pd[pos].first) return pd[pos];
    pd[pos] = search(pos+1);
    int v = valido(pos);
    if(~v) {
        ii temp = search(pos+m);
        temp.first++;
        temp.second -= v;
        pd[pos] = max(pd[pos], temp);
    }
    //printf("A partir de %d eh %d %d\n", pos, pd[pos].first - 1, -pd[pos].second);
    return pd[pos];
}

int main() {
    scanf("%d %s %d", &n, s, &m);
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            sumPar[i+1] = sumPar[i] + (s[i] == 'b');
            sumImpar[i+1] = sumImpar[i] + (s[i] == 'a');
        } else {
            sumPar[i+1] = sumPar[i] + (s[i] == 'a');
            sumImpar[i+1] = sumImpar[i] + (s[i] == 'b');
        }
    }
    //for(int i = 0; i <= n; i++) {
    //    printf("%d: Par = %d, Impar = %d\n", i, sumPar[i], sumImpar[i]);
    //}
    //printf("Maior qntidade = %d\n", search().first - 1);
    printf("%d\n", -search().second);
    return 0;
}