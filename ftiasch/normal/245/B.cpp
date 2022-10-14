#include <cstdio>
#include <cstring>
using namespace std;

const int N = 50;

char text[N + 1];

int main() {
    scanf("%s", text);
    int i = 0;
    if (text[0] == 'h') {
        i = 4;
        printf("http://");
    } else {
        i = 3;
        printf("ftp://");
    }
    int k = i + 1;
    while (text[k] != 'r' || text[k + 1] != 'u') {
        k ++;
    }
    for (int j = i; j < k; ++ j) {
        putchar(text[j]);
    }
    printf(".ru");
    if (text[k + 2]) {
        printf("/%s", text + (k + 2));
    }
    puts("");
    return 0;
}