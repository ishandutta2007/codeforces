#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], mini = 256;
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;
    n = str.size();

    for(int i = 0; i < n; i++) {
        mini = min(mini, (ll)str[i]);
        if(mini == (ll)str[i]) puts("Mike");
        else puts("Ann");
    }

    return 0;
}