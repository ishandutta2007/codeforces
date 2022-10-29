#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;
bool a[10];
int main(){
    int n;
    scanf("%d", &n);
    while (n --) {
        char c;
        scanf(" %c", &c);
        if (c == 'L') {
            for (int i = 0; i < 10; i ++)
                if (!a[i]) {
                    a[i] = 1;
                    break;
                }
        } else
            if (c == 'R') {
                for (int i = 9; i >= 0; i -- )
                    if (!a[i]) {
                        a[i] = 1;
                        break;
                    }
            } else
            {
                a[c - '0'] = 0;
            }
    }
    for (int i = 0; i < 10; i ++)
        printf("%d", (int)a[i]);
    return 0;
}