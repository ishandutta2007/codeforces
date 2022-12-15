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
const ll fat = 1E9+7;

int n;

vll matMul(vll a, vll b) {
    vll m(n);
    for(int i = 0; i < n; i++) {
        m[i] = 0;
        for(int j = 0; j <= i; j++) {
            m[i] += a[i-j] * b[j];
            m[i] %= fat;
        }
    }
    return m;
};

vll matPow(vll resposta, int p) {
    vll base(n);
    for(int i = 0; i < n; i++) {
        base[i] = 1;
    }
    while(p) {
        if(p & 1) resposta = matMul(resposta, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return resposta;
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    vll resposta(n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        resposta[i] = x;
    }
    resposta = matPow(resposta, k);
    for(int i = 0; i < n; i++) {
        printf("%lld ", resposta[i]);
    }
    return 0;
}