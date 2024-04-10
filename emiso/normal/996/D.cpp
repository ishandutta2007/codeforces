#include <bits/stdc++.h>

using namespace std;

int n, a[220], c;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < 2*n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 2*n; i += 2) {
        int pos = i + 1;
        while(a[pos] != a[i]) pos++;

        while(pos != i + 1) {
            swap(a[pos], a[pos-1]);
            pos--;
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}