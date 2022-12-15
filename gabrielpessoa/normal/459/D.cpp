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

map<int, int> prefixSum;
map<int, int> suffixSum;
int arr[SIZE];

int bit[SIZE];

int n;

void bitUpdate(int idx, int val) {
    while(idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int bitQuery(int idx) {
    int ret = 0;
    while(idx > 0) {
        //printf("Query no idx %d\n", idx);
        ret += bit[idx];
        idx -= idx & -idx;
        //printf("Idx = %d\n", idx);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        prefixSum[arr[i]]++;
    }
    ll resposta = 0;
    for(int i = n-1; i >= 0; i--) {
        //printf("Pegando I = %d\n", i);
        int f1i = prefixSum[arr[i]]--;
        int fjn = ++suffixSum[arr[i]];
        //printf("Chamando BitUpdate\n");
        //printf("Chamando BitQuery\n");
        resposta += bitQuery(f1i);
        bitUpdate(fjn + 1, 1);
        //printf("%lld\n", resposta);
    }
    cout << resposta << endl;
    return 0;
}