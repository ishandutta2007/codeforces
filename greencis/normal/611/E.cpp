#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a,b,c,ans,z[9],u[9],t[200105];
multiset<int> sr;

inline int fdel(int x) {
    multiset<int>::iterator it = sr.lower_bound(-x);
    if (it == sr.end()) return -1;
    int cur = -*it;
    sr.erase(sr.find(-cur));
    return cur;
}

int main()
{
    scanf("%d%d%d%d",&n,&z[0],&z[1],&z[2]);
    sort(z, z + 3);
    a = z[0];
    b = z[1];
    c = z[2];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&t[i]);
        sr.insert(-t[i]);
    }
    sort(t,t+n);
    if (t[n-1] > a+b+c) { cout << -1; return 0; }
    for (; sr.size(); ) {
        ++ans;
        int cur = -*sr.begin();
        if (cur > a+b && cur > a+c && cur > b+c) {
            fdel(cur);
            continue;
        }
        if (cur > a && cur > b && cur > c) {
            if (cur > a+b && cur > a+c) {
                fdel(cur);
                fdel(a);
            } else if (cur > a+b) {
                fdel(cur);
                fdel(b);
            } else {
                fdel(cur);
                fdel(c);
            }
        } else {
            fdel(c);
            int qqq1 = fdel(a);
            int qqq2 = fdel(b);
            if (qqq1 == -1 || qqq2 == -1) {
                if (qqq1 != -1) sr.insert(-qqq1);
                if (qqq2 != -1) sr.insert(-qqq2);
                fdel(a + b);
            }
        }
    }
    cout << ans;

    return 0;
}