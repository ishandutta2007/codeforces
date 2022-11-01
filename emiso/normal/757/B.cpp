#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, s[MN];
int divs[MN];
bitset <MN> isp;
vector <int> primes;

void crivo() {
    isp.set();
    isp[0] = isp[1] = 0;

    for(int i=2; i*i <= MN;i++)
        if(isp[i]) for(int j=i*i; j <= MN; j += i)
            isp[j] = 0;

    for(int i=2;i<=MN;i++) if(isp[i]) primes.push_back(i);
}

void divisors(int n) {
    int id = 0, p = primes[id];

    while(p * p <= n) {
        if(n % p == 0) {
            divs[p]++;
            while(n % p == 0) n /= p;
        }
        p = primes[++id];
    }

    if(n > 1) divs[n]++;
}

int main() {
    scanf("%d",&n);
    crivo();

    for(int i=0; i<n; i++) {
        scanf("%d",&s[i]);
        divisors(s[i]);
    }

    int ans = 1;
    for(int i=2;i<MN;i++) {
        ans = max(ans, divs[i]);
    }

    printf("%d\n",ans);
    return 0;
}