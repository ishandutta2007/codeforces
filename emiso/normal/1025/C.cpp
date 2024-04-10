#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans = 1, sz;
char s[MN]; string str;

int main() {
    scanf("%s", s);
    str = s;
    sz = str.size();
    str += str;

    char last = str[0];
    int streak = 1;
    for(int i = 1; i < str.size(); i++) {
        if(last == str[i]) {
            streak = 1;
        } else {
            last = str[i];
            streak++;
            ans = max(ans, streak);
        }
    }

    printf("%d\n", min(ans, sz));
    return 0;
}