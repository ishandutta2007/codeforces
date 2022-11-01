#include <bits/stdc++.h>

using namespace std;

#define MN 6000600

char s[MN];
string str, rev;

void z_function(string &str, int *z) {
    for(int i = 1, L = 0, R = 0, sz = str.size(); i < sz; i++) {
        if(i > R) {
            L = R = i;
            while(R < sz && str[R] == str[R - L]) R++;
            z[i] = R - L; R--;
        }
        else {
            if(z[i - L] < R - i + 1) z[i] = z[i - L];
            else {
                L = i;
                while(R < sz && str[R] == str[R - L]) R++;
                z[i] = R - L; R--;
            }
        }
    }
}
int z[2*MN], pal[2*MN];
long long ans;

int main() {
    scanf("%s", s);

    str = rev = s;
    reverse(rev.begin(), rev.end());
    str = str + '#' + rev;

    z_function(str, z);

    for(int i = 1, j = str.size()-1; i < j; i++, j--) {
        if(z[j] == i) pal[i] = 1 + pal[i/2];
        ans += pal[i];
    }

    printf("%lld\n", ans);
    return 0;
}