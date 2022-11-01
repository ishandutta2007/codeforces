#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans, a[MN], maxi = 0;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == maxi) maxi++;
        else if(a[i] > maxi) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    puts("-1");
    return 0;
}