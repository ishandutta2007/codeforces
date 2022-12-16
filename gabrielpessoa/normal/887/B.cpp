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

int n;
int arr[5][10];
bool barr[3];

bool searchN(int x) {
    if(!x) {
        return true;
    }
    for(int i = 0; i < n; i++) {
        if(barr[i]) {
            continue;
        }
        for(int j = 0; j < 6; j++) {
            if(arr[i][j] == x % 10) {
                barr[i] = true;
                if(searchN(x/10)) {
                    return true;
                }             
                barr[i] = false;
                break;
            }
        }
    }
    return false;
}
bool possible(int x) {
    if((x >= 10 && n < 2) || (x >= 100 && n < 3) || x >= 1000) {
        return false;
    }
    memset(barr, 0, sizeof(barr));
    return searchN(x);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= 1000; i++) {
        if(!possible(i)) {
            printf("%d\n", i-1);
            return 0;
        }
    }
    return 0;
}