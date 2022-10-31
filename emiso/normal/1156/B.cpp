#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, f[26];
char s[MN]; string str;

int main() {
    scanf("%lld", &n);
    while(n--) {
        scanf("%s", s); str = s;

        memset(f, 0, sizeof f);
        for(char c : str) f[c-'a']++;

        int f1 = 1, f2 = 1;
        string t1, t2;

        for(int i = 0; i < 26; i += 2) for(int j = 0; j < f[i]; j++) t1 += 'a' + i;
        for(int i = 1; i < 26; i += 2) for(int j = 0; j < f[i]; j++) t1 += 'a' + i;
        for(int i = 1; i < str.size(); i++) if(abs(t1[i] - t1[i-1]) == 1) f1 = 0;
        if(f1) {
            printf("%s\n", t1.c_str());
            continue;
        }

        for(int i = 1; i < 26; i += 2) for(int j = 0; j < f[i]; j++) t2 += 'a' + i;
        for(int i = 0; i < 26; i += 2) for(int j = 0; j < f[i]; j++) t2 += 'a' + i;
        for(int i = 1; i < str.size(); i++) if(abs(t2[i] - t2[i-1]) == 1) f2 = 0;

        if(f2) {
            printf("%s\n", t2.c_str());
            continue;
        }
        printf("No answer\n");
    }
    return 0;
}