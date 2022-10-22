#include<bits/stdc++.h>
using namespace std;


int t;
long long n, k, cnt;

int main()
{
    scanf("%d", &t);

    while(t--) {
        scanf("%lld %lld", &n, &k);

        cnt = 0;
        while(n) {
            if(n%k == 0) n /= k, cnt++;
            else cnt += n%k, n = (n/k) * k;
        }

        printf("%lld\n", cnt);
    }
}