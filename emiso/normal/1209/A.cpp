#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
vector<int> c;
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        int ja = 0;
        for(int x : c) if(a[i] % x == 0) ja = 1;
        if(ja == 0) c.push_back(a[i]);
    }

    printf("%d\n", (int)c.size());
    return 0;
}