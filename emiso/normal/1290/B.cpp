#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, f[26][200020];
char s[MN]; string str;

int main() {
    scanf("%s", s);
    str = s;

    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; i && j < 26; j++)
            f[j][i] += f[j][i-1];
        f[str[i]-'a'][i]++;
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;

        if(l == r || str[l] != str[r]) puts("Yes");
        else {
            int dif = 0;
            for(int c = 0; c < 26; c++) {
                if((l == 0 && f[c][r]) || (l && (f[c][r] - f[c][l-1])))
                    dif++;
            }
            if(dif > 2) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}