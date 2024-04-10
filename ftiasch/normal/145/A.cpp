// Codeforces Round #104
// Problem A -- Lucky Conversion
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111111;

char a[N], b[N];

int main() {
    scanf("%s%s", a, b);
    int length = strlen(a);
    int count_47 = 0;
    int count_74 = 0;
    for (int i = 0; i < length; ++ i) {
        if (a[i] != b[i]) {
            if (a[i] == '4') {
                count_47 ++;
            } else {
                count_74 ++;
            }
        }
    }
    printf("%d\n", max(count_47, count_74));
    return 0;
}