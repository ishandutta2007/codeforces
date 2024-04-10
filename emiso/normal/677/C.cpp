#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

long long toint(char a) {
    if(isdigit(a))
        return a - '0';

    if(isalpha(a)) {
        if(isupper(a))
            return a - 'A' + 10;
        return a - 'a' + 36;
    }

    if(a == '-')
        return 62;

    return 63;
}

long long mypow(long long a, long long b) {
    long long ans = 1;
    while(b--) ans *= a;
    return ans;
}

int main() {
    long long ans = 1;

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++) {
        ans *= mypow(3,6-__builtin_popcount(toint(s[i])));
        ans %= MOD;
    }

    printf("%lld\n",ans);

    return 0;
}