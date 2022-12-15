#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[1005];
    int k, pos = 0, amount[130], len;
    bool exist = true;
    scanf("%d %s", &k, &s);
    memset(amount, 0, sizeof(amount));
    len = strlen(s);
    for(int i = 0; i < len; i++) {
        amount[s[i]]++;
    }
    for(int i = 'a'; i <= 'z'; i++) {
        if(amount[i] % k == 0) {
            for(int j = 0; j < amount[i] / k; j++) {
                s[pos++] = i;
            }
        } else {
            exist = false;
            break;
        }
    }
    if(exist) {
        s[pos] = '\0';
        for(int i = 0; i < k; i++) {
            printf("%s", s);
        }
    } else {
        printf("-1");
    }
    return 0;
}