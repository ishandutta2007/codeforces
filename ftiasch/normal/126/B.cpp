// Codeforces Beta Round #93
// Problem B -- Password
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1111111;

char str[N];
int fail[N];

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    fail[0] = fail[1] = 0;
    for (int i = 1; i < len; ++ i) {
        fail[i + 1] = 0;
        int tmp = i;
        while (tmp) {
            tmp = fail[tmp];
            if (str[tmp + 1] == str[i + 1]) {
                fail[i + 1] = tmp + 1;
                break;
            }
        }
    }
    //for (int i = 1; i <= len; ++ i) {
    //    printf("%4d", fail[i]);
    //}
    //printf("\n");
    int middle = 0;
    for (int i = 2; i <= len - 1; ++ i) {
        middle = max(middle, fail[i]);
    }    
    int result = 0;
    for (int i = len; i > 1; i = fail[i]) {
        if (fail[i] <= middle) {
            result = fail[i];
            break;
        }
    }
    if (result) {
        for (int i = 1; i <= result; ++ i) {
            printf("%c", str[i]);
        }
        printf("\n");
    } else {
        printf("Just a legend\n");
    }
    return 0;
}