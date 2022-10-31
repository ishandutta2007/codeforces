#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct change { int x; int y; int p; int q; };

int main()
{
    int a, b, k, primes[1000001];
    for (int i=2; i<1000001; i++) primes[i] = 1;
    primes[1] = 0;
    for (int i=2; i*i<1000001; i++) {
        if (primes[i]) {
            for (int j=i*i; j<1000001; j += i) primes[j] = 0;
        }
    }
    cin >> a >> b >> k;
    int i=a, l=1, now = 0;
    if (primes[a] == 1) now = 1;
    while (i+l-1<b && l!= -1) {
        while (now >= k) {
            if (i+l>b) break;
            i++;
            if (primes[i-1] == 1) now--;
            if (primes[i+l-1] == 1) now++;
        }
        while (now < k) {
            l++;
            if (i+l-1>b) {
                if (i==a) l=-1;
                break;
            }
            if (primes[i+l-1] == 1) now++;
        }
    }
    if (i==a && now < k) l = -1;
    cout << l;
    return 0;
}