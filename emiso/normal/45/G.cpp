#include <bits/stdc++.h>

#define MN 18003000

using namespace std;

bitset <MN> primo;
vector <int> ans(6060);

void crivo() {
    primo.flip();
    primo[1] = 0;

    for(int i=2; i*i < MN;i++) {
        if(primo[i]) {
            for(int j = i*i; j < MN; j += i)
                primo[j] = 0;
        }
    }
}

int main() {
    int n, total;
    scanf("%d",&n);

    total = n*(n+1)/2;
    crivo();

    if(primo[total]);

    else if(total & 1) {
        if(primo[total - 2])
            ans[2] = 1;

        else {
            ans[3] = 2;
            total -= 3;
        }
    }

    if(total % 2 == 0) {
        int k;
        for(int i=2; i<= total / 2; i++) {
            if(primo[i] && primo[total - i]) {
                k = i;
                break;
            }
        }

        int sum = 0;
        for(int i=1; i<= total; i++) {
            if(ans[i]) continue;

            ans[i] = 1;
            sum += i;

            if(sum >= k) {
                if(sum - k == 3 && ans[3] == 2) {
                    ans[1] = 0;
                    ans[2] = 0;
                }
                else ans[sum - k] = 0;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++) printf("%d%c",ans[i]+1,(n-i)?' ':'\n');

    return 0;
}