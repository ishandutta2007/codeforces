#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    char ch;
    while (scanf("%d%d", &n, &m) == 2) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &ch);
                if (ch != 'G' && ch != 'B' && ch != 'W') {
                    flag = 1;
                }
            }
        }
        puts(flag ? "#Color" : "#Black&White");
    }
}