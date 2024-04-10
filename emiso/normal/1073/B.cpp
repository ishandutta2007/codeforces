#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int n, a[MN], b[MN], pos[MN], last;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < n; i++) {
        int nxt = pos[b[i]];
        if(nxt < last) printf("0 ");
        else {
            printf("%d ", nxt - last + 1);
            last = nxt + 1;
        }
    }
    return 0;
}