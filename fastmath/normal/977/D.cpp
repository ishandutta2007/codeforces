#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXK = 107;
const int MAXN = 107;

vector <int> p[MAXK];

int getp(int x) {
    int res = 0;
    while (x % 3 == 0) {
        x /= 3;
        ++res;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[getp(x)].push_back(x);    
    }   
    
    for (int i = 0; i < MAXK; ++i) sort(p[i].begin(), p[i].end());

    for (int i = MAXK - 1; i >= 0; --i) {
        for (int elem : p[i]) cout << elem << ' ';
    }
    cout << '\n';

    return 0;
}