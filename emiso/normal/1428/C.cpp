#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%s", &s);
    str = s;

    vector<char> ss;
    for(int i = 0; i < str.size(); i++) {
        if(ss.empty()) ss.push_back(s[i]);
        else if(ss.back() == 'A' && s[i] == 'B') ss.pop_back();
        else ss.push_back(s[i]);
    }

    ans = ss.size();
    for(int i = 0; i + 1 < ss.size(); i++) {
        if(ss[i] == 'B' && ss[i+1] == 'B') {
            ans -= 2;
            i++;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}