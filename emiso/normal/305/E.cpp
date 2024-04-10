#include <bits/stdc++.h>

using namespace std;

string s;
int can[5050], grundy[5050], mark[5050], value, sz[5050];

void prep() {
    grundy[1] = grundy[2] = 1;
    for(int i = 3; i <= 5000; i++) {
        for(int j = 0; j < i; j++) {
            int k = i - j - 1;
            mark[(j ? grundy[j-1] : 0)^(k ? grundy[k-1] : 0)] = 1;
        }
        while(mark[grundy[i]]) grundy[i]++;
        memset(mark, 0, sizeof mark);
    }
}

int main() {
    prep();
    cin >> s;

    for(int i = 1; i + 1 < s.size(); i++) {
        if(s[i-1] == s[i+1]) can[i] = 1;
    }

    for(int i = 1; i + 1 < s.size(); i++) {
        if(can[i]) {
            int j = i;
            while(can[j]) j++;
            value ^= grundy[j-i];
            for(int k = i; k < j; k++) {
                sz[k] = j - i;
                can[k] = i;
            }
            i = j;
        }
    }

    if(value == 0) puts("Second");
    else {
        puts("First");
        for(int i = 1; i + 1 < s.size(); i++) {
            int lv = max(0, i - can[i] - 1);
            int rv = max(0, sz[i] - (i - can[i]) - 2);
            if(can[i] && (value
                            ^ grundy[sz[i]]
                            ^ grundy[lv]
                            ^ grundy[rv]) == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}