// Codeforces Round #104
// Problem B -- Lucky Number 2
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2222222;

int a_1, a_2, a_3, a_4, length, digit[N], count[N];

int main() {
    scanf("%d%d%d%d", &a_1, &a_2, &a_3, &a_4);
    bool found = false;
    memset(count, 0, sizeof(count));
    if (a_3 == a_4 + 1) { // 47
        if (a_1 < a_3 || a_2 < a_3) {
            puts("-1");
        } else {
            found = true;
            for (int i = 0; i < a_3; ++ i) {
                count[2 * i] = count[2 * i + 1] = 1;
                digit[2 * i] = 4; 
                digit[2 * i + 1] = 7;
            }
            a_1 -= a_3;
            a_2 -= a_3;
            length = a_3 * 2;
        }
    } else if (a_3 + 1 == a_4) { // 74
        if (a_1 < a_4 || a_2 < a_4) {
            puts("-1");
        } else {
            found = true;
            for (int i = 0; i < a_4; ++ i) {
                count[2 * i] = count[2 * i + 1] = 1;
                digit[2 * i] = 7;
                digit[2 * i + 1] = 4;
            }
            a_1 -= a_4;
            a_2 -= a_4;
            length = a_4 * 2;
        }
    } else if (a_3 == a_4) { // 474, 747
        if (a_1 >= a_3 + 1 && a_2 >= a_3) {
            found = true;
            for (int i = 0; i < a_3; ++ i) {
                count[2 * i] = count[2 * i + 1] = 1;
                digit[2 * i] = 4;
                digit[2 * i + 1] = 7;
            }
            count[2 * a_3] = 1;
            digit[2 * a_3] = 4;
            a_1 -= a_3 + 1;
            a_2 -= a_3;
            length = a_3 * 2 + 1;
        } else if (a_1 >= a_3 && a_2 >= a_3 + 1) {
            found = true;
            for (int i = 0; i < a_3; ++ i) {
                count[2 * i] = count[2 * i + 1] = 1;
                digit[2 * i] = 7;
                digit[2 * i + 1] = 4;
            }
            count[2 * a_3] = 1;
            digit[2 * a_3] = 7;
            a_1 -= a_3;
            a_2 -= a_3 + 1;
            length = a_3 * 2 + 1;
        } else {
            puts("-1");
        }
    } else {
        puts("-1");
    }
    if (found) {
        if (a_1 > 0) {
            for (int i = 0; i < length; ++ i) {
                if (digit[i] == 4) {
                    count[i] += a_1;
                    break;
                }
            }
        }
        if (a_2 > 0) {
            for (int i = length - 1; i >= 0; -- i) {
                if (digit[i] == 7) {
                    count[i] += a_2;
                    break;
                }
            }
        }
        for (int i = 0; i < length; ++ i) {
            for (int j = 0; j < count[i]; ++ j) {
                putchar('0' + digit[i]);
            }
        }
        puts("");
    }
    return 0;
}