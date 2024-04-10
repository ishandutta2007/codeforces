#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], freq[256], on, ze;
char s[MN]; string str;

int main() {
    scanf("%lld %s", &n, s);
    str = s;

    for(int i = 0; i < n; i++) {
        freq[str[i]]++;
        if(str[i] == 'n') on++;
        else if(str[i] == 'z') ze++;
    }

    for(int i = 0; i < on; i++) printf("1 ");
    for(int i = 0; i < ze; i++) printf("0 ");
    return 0;
}