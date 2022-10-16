#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000000000000LL
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

const int m = 1000000007;
const int mod = m;
int n, k;
long long r[110000];
char s[110000];

int main() {
    r[1] = 1; for (int i=2; i<110000; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    if (k == 0) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans*10 + s[i]-'0') % mod;
        }
        printf("%d\n", (int)ans);
        return 0;
        
    }

    long long fc = 1;
    for (int i = 0; i < k-1; i++) {
        fc = (fc * (n-2-i)) % mod;
    }
    for (int i = 2; i <= (k-1); i++) {
        fc = (fc * r[i]) % mod;
    }

    long long la = 1;
    for (int i = 0; i < k; i++) {
        la = (la * (n-1-i)) % mod;
    }
    for (int i = 2; i <= k; i++) {
        la = (la * r[i]) % mod;
    }

    long long pot = 1;
    long long ans = 0;
    long long ps = 0;

    for (int i = n-1; i >= 0; i--) {
        ans = (ans + ps * (s[i]-'0')) % mod;
        ans = (ans + pot * la * (s[i]-'0')) % mod;
        
        int rind = i;
        la = (la * r[rind]) % mod;
        la = (la * (rind-k)) % mod;

        ps = (ps + pot * fc) % mod;
        fc = (fc * r[rind-1]) % mod; 
        fc = (fc * (rind-k)) % mod;
        pot = (pot * 10) % mod;
    }

    printf("%d\n", (int) ans);
}