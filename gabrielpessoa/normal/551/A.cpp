#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, rat[2005], pos[2005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &rat[i]);
        pos[i] = 1;
        for(int j = 0; j < i; j++) {
            if(rat[i] > rat[j]) {
                pos[j]++;
            } else if(rat[j] > rat[i]) {
                pos[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != 0) {
            printf(" ");
        }
        printf("%d", pos[i]);
    }
    return 0;
}