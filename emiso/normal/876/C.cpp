#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, x;
vector<int> ans;

int s(int x) {
    int ret = 0;
    while(x) {
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i=n; i > n - 2000 && i > 0; i--) {
        if(i + s(i) == n) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for(int v : ans) printf("%d\n", v);
    return 0;
}