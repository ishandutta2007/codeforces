#include <bits/stdc++.h>

#define MN 5005
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll ans, p1[MN], p2[MN], p3[MN];
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;
    str = "**" + str;

    for(int i = 2; i <= str.size(); i++) {
        if(i < str.size()) p1[i] = (str[i] == 'a');
        p1[i] += p1[i-1];

        if(i < str.size()) p2[i] = (str[i] == 'b');
        p2[i] += p2[i-1];
    }

    for(int i = 1; i <= str.size(); i++) {
        for(int j = i; j <= str.size(); j++) {
            ll x = p1[i] + (p1[str.size()] - p1[j]) + (p2[j] - p2[i]);
            ans = max(ans, x);
        }
    }

    printf("%lld\n", ans);
    return 0;
}