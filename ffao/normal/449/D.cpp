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

int mod = 1000000007;
int cnt[1100000];
int cnt2[1100000];
int pot[1100000];
int n,a;

int main() {
    pot[0] = 1;
    for (int i = 1; i <= 1050000; i++) pot[i] = (pot[i-1] * 2) % mod;

    int l = 20;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }

    for (int i = 1000000; i > 0; i--) {
        int lb = i & -i;
        cnt2[lb] += cnt[i];
        cnt[i-lb] += cnt[i];

        int ni = i-lb;
        for(int i2 = ni; i2 > 0; i2 = (i2-1) & ni)
        {
            cnt2[i2+lb] += cnt[i];
        }
    }

    long long ans = 0;
    for (int i=1; i < (1<<l); i++) {
        if (__builtin_popcount(i) % 2 == 1) ans = (ans + pot[cnt2[i]]) % mod;
        else ans = (((ans - pot[cnt2[i]]) % mod) + mod) % mod;
    }

    printf("%d\n", (((pot[n] - ans) % mod) + mod) % mod);

}