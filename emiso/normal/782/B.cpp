#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], v[MN];
//char s[MN]; string str;
double ans;

double calc(double loc) {
    double ret = -1;
    for(int i=0;i<n;i++) {
        ret = max(ret, abs(loc - double(a[i])) / v[i]);
    }
    return ret;
}

int main() {
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }

    int it = 190;
    double l = 1, r = 1000000010, m, lt, rt;
    while(it--) {
        lt = (l + (r - l)/3);
        rt = (r - (r - l)/3);

        if(calc(lt) > calc(rt))
            l = lt;
        else r = rt;
    }

    ans = calc((l + r)/2);

    printf("%.6f\n", ans);
    return 0;
}