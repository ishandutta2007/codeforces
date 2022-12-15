#include <bits/stdc++.h>
using namespace std;


char s[10005];
char sarr[10][10005];
int n;


int main() {
    int k;
    int best = 0x3f3f3f, bestpos = -1;
    scanf("%d %d %s", &n, &k, s);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            sarr[j][i] = s[i];
        }
    }
    for(char i = '0'; i <= '9'; i++) {
        int cur = 0;
        int curK = 0;
        int mod = -1;
        int pos = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == i) {
                curK++;
            }
        }
        int j = 0;
        while(curK < k) {
            if(s[j] + mod == i) {
                cur += abs(mod);
                sarr[i-'0'][j] = i;
                curK++;
            }
            if(mod < 0) {
                if(++j == n) {
                    mod = mod * -1;
                    j--;
                }
            } else {
                if(j-- == 0) {
                    j++;
                    mod = mod * -1 - 1;
                }
            }
        }
        if(cur < best || (cur == best && strcmp(sarr[bestpos], sarr[i-'0']) > 0)) {
            best = cur;
            bestpos = i - '0';
        }
    }
    printf("%d\n%s", best, sarr[bestpos]);
    return 0;
}