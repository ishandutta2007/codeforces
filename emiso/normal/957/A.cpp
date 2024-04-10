#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, f = 0;
char s[110]; string str;

int main() {
    scanf("%d %s", &n, s); str = s;
    str = "$" + str + "$";
    for(int i = 1; i + 1 < str.size(); i++) {
        if(str[i] == '?' && str[i-1] == '$') f = 1;
        if(str[i] == '?' && str[i+1] == '$') f = 1;
        if(str[i] == '?' && str[i-1] == str[i+1]) f = 1;
        if(str[i] == '?' && str[i-1] == '?') f = 1;

        if(str[i] != '?' && str[i] == str[i-1]) {
            f = 0;
            break;
        }
    }

    printf("%s\n", f ? "Yes" : "No");
    return 0;
}