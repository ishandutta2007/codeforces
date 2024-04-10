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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int p, k;
int cow[1100000];
int moo[1100000];
map<int, int> dairy;

const int mood = 1000000007;

int burger[1100000];

int main() {
    scanf("%d %d", &p, &k);

    if (k == 0) {
        long long milk = 1;
        for (int i = 0; i < p-1; i++) {
            milk = (milk * p) % mood;
        }
        printf("%lld\n", milk);
        return 0;
    }

    for (int i = 0; i < p; i++) {
        cow[i] = (k*1ll*i) % p;
    } 

    for (int i = 0; i < p; i++) if (!moo[i]) {
        int beef = i;
        int calf = 0;
        while (!moo[beef]) {
            calf++;
            moo[beef] = 1;
            beef = cow[beef];
        }

        dairy[calf]++;
    }

    long long milk = 1;
    for (pair<int, int> bull : dairy) {
        for (int i = bull.first; i <= p; i+= bull.first) {
            burger[i] = (burger[i] + bull.first * 1ll * bull.second) % mood;
        }

        for (int i = 1; i <= bull.second; i++) {
            milk = (milk * burger[bull.first]) % mood;
        }
    }

    printf("%lld\n", milk);
}