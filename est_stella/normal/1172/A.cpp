#include<bits/stdc++.h>
using namespace std;

int n, m = 0;
int a[200001];
int b[200001];

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++ ) {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 0; i<n; i++) {
        if(b[n-1] == 0) break;
        if(b[i] != 0 && b[i] < b[n-1] + i + 2 && n - 1 - i > b[n-1]) break;
        if( n - 1 - i <= b[n-1] && b[i] - i != b[n-1] - n + 1) break;

        if(i == n-1) {
            printf("%d", n - b[n-1]);
            return 0;
        }
    }

    for(int i=0; i<n; i++) {
        if(b[i]) m = max(m, 2 + i - b[i]);
    }

    printf("%d", m + n);
}