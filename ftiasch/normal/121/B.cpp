#include <cstdio>
#include <cstring>

using namespace std;

const int N = 111111;

int n, k;
char s[N];

int main () {
    scanf("%d%d%s", &n, &k, s);
    int ind = 0;
    while (k && ind + 1 < n) {
        while (ind + 1 < n 
                && (s[ind] != '4' || s[ind + 1] != '7')) {
            ind ++;
        }
        if (ind + 1 == n) {
            break;
        }
        if (ind && s[ind - 1] == '4' && (ind & 1)) {
            if (k & 1) {
                s[ind] = '7';
            }
            break;
        } else if (ind + 2 < n && s[ind + 2] == '7' && !(ind & 1)) {
            if (k & 1) {
                s[ind + 1] = '4';
            }
            break;
        } else {
            if (ind & 1) {
                s[ind] = s[ind + 1] = '7';
            } else {
                s[ind] = s[ind + 1] = '4';
            }
        }
        k --;
    }
    printf("%s\n", s);
    return 0;
}