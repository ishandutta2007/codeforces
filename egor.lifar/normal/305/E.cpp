#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


const int MAXN = 5555;
char s[MAXN];
int grundy[MAXN], mex[MAXN], n, totalXor;
 

int main() {
        gets(s);
        for (int i = 1; i < MAXN; i++) {
                memset(mex, 0, sizeof(mex));
                for (int j = 0; j < i; j++) {
                        int left = max(0, j - 1);
                        int right = max(0, i - j - 2);
                        int tXor = grundy[left] ^ grundy[right];
                        if (tXor < MAXN) {
                                mex[tXor]++;
                        }
                }
                for (int j = 0; ; j++) {
                        if (!mex[j]) {
                                grundy[i] = j;
                                break;
                        }
                }
        }
        n = strlen(s);
        for (int i = 1; i < n - 1; i++) {
                if (s[i - 1] == s[i + 1]) {
                        int j = i;
                        while (j + 2 < n && s[j] == s[j + 2]) {
                                j++;
                        }
                        totalXor ^= grundy[j - i + 1];
                        i = j + 1;
                }
        }
        if (totalXor != 0) {
                puts("First");
                for (int i = 1; i < n - 1; i++) {
                        if (s[i - 1] == s[i + 1]) {
                                int j = i;
                                while (j + 2 < n && s[j] == s[j + 2]) {
                                        j++;
                                }
                                int len = j - i + 1;
                                int nowXor = totalXor ^ grundy[len];
                                for (int k = 0; k < len; k++) {
                                        int left = max(0, k - 1);
                                        int right = max(0, len - k - 2);
                                        int resXor = nowXor ^ grundy[left] ^ grundy[right];
                                        if (resXor == 0) {
                                                printf("%d\n", i + k + 1);
                                                return 0;
                                        }
                                }
                                i = j + 1;
                        }
                }
                return 0;
        }
        puts("Second");
        return 0;
}