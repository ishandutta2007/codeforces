#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define max 2222
typedef long long ll;
int A, B, C, p[2222];
vector<int> primes;
map<ll, int> g[500];

ll dp(int a, int b, int c, int p) {
    if (p==-1) return 1;
    ll t, l=ll(a*2001+b)*2001+c;
    if (t=g[p][l]) return t;
    ll ans=0, q=primes[p];
    for (int i=1, x=0; i<=a; x++, i*=q)
        for (int j=1, y=0; j<=b; y++, j*=q)
            for (int k=1, z=0; k<=c; z++, k*=q) ans+=dp(a/i, b/j, c/k, p-1)*(x+y+z+1);
    return g[p][l] = ans;
}

int main()
{
    cin >> A >> B >> C;
    for (int i=2; i<max; i++) if (!p[i]) {for (int j=i*i; j<max; j+=i) p[j]=1; primes.push_back(i); }
    ll ans=dp(A, B, C, primes.size()-1);
    while(ans<0) ans+=1<<30;
    cout << ans%(1<<30);
    return 0;
}