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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int k, n;
int c[1100];
int tot[1100];
int pd[1100][1100];
long long fac[1100];
long long r[1100];

const int mod = 1000000007;
int m = mod;

int rec(int put, int av) {
    if (put == n) return 1;

    int &ret = pd[put][av];
    if (ret == -1) {
        ret = 0;

        if (av != k) ret = (ret + rec(put+1, av+1)) % mod;

        if (av != 0) {
            int can_put = tot[k-av] - put;
            if (can_put > 0) {
                int th = (rec(put+1, av) * 1ll * can_put) % mod;
                ret = (ret + th) % mod;
            }
        }
    }

    //printf("%d %d %d\n", put, av, ret);
    return ret;
}

int main() {
    memset(pd,-1,sizeof(pd));
    scanf("%d", &k);

    r[1] = 1; 
    for (int i=2; i<1100; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;
    
    fac[0] = 1;
    for (int i = 1; i < 1100; i++) fac[i] = (fac[i-1] * r[i]) % m;
    
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        n += c[i];
    }   

    for (int i = k-1; i >= 0; i--) {
        tot[i] = tot[i+1] + c[i];
    }

    long long ans = rec(0, 0);
    for (int i = 0; i < k; i++) ans = (ans * fac[c[i] - 1]) % m;

    printf("%lld\n", ans);
}