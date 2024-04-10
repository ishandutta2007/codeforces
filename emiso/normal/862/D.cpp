#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, q;

int q0(int l, int r) {
    string s = "";
    for(int i = 0; i < l; i++) {
        s += '1';
    }
    for(int i = l; i <= r; i++) {
        s += '0';
    }
    for(int i = r + 1; i < n; i++) {
        s += '1';
    }

    printf("? %s\n", s.c_str());
    fflush(stdout);

    assert(++q <= 15);

    int ret;
    scanf("%d", &ret);
    return ret;
}

int q1(int l, int r) {
    string s = "";
    for(int i = 0; i < l; i++) {
        s += '0';
    }
    for(int i = l; i <= r; i++) {
        s += '1';
    }
    for(int i = r + 1; i < n; i++) {
        s += '0';
    }

    printf("? %s\n", s.c_str());
    fflush(stdout);

    assert(++q <= 15);

    int ret;
    scanf("%d", &ret);
    return ret;
}

int main() {
    scanf("%d", &n);

    int p0 = -1, p1 = -1;

    int l = 0, r = n-1, old = q0(0, n - 1), neu, dif;
    while(l < r && (p0 == -1 || p1 == -1)) {
        int m = (l + r) / 2;
        int len = m - l + 1;
        neu = q1(l, m);

        //cerr << l << " " << m << " " << r << " " << old << " " << neu << endl;

        int dif = neu - old;
        if(dif == len) {
            p0 = m;
            l = m + 1;
        }
        else if(dif == -len) {
            p1 = m;
            l = m + 1;
        }
        else {
            r = m;
        }
    }

    if(p0 == -1) p0 = l;
    else if(p1 == -1) p1 = l;

    printf("! %d %d\n", p0 + 1, p1 + 1);
    fflush(stdout);
    return 0;
}