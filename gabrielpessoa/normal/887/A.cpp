#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;

const int SIZE = 505;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

/* int find_set(int a) {
    if(a != ds[a]) {
        ds[a] = find_set(ds[a]);
    }
    return ds[a];
}

void union_set(int a, int b) {
    ds[find_set(a)] = find_set(b);
} */

int main() {
    string s;
    cin >> s;
    bool achadoum = false;
    int c = 0;
    for(int i = 0; i < s.length(); i++) {
        if(!achadoum && s[i] == '1') {
            achadoum = true;
        } else if(achadoum && s[i] == '0') {
            if(++c >= 6) {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}