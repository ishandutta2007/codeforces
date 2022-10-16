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


int n,k;

int a[110000];

map< vector< pair<int,int> >, int > tot;
int p[110000];

void solve()
{
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 2; i <= 100000; i++) if (p[i] == 0) {
        for (int j = i+i; j <= 100000; j += i) if (p[j] == 0) p[j] = i;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector< pair<int, int> > fac;
        vector< pair<int, int> > comp;

        while (a[i] > 1) {
            int f = p[a[i]];
            if (f == 0) f = a[i];

            int cnt = 0;
            while (a[i] % f == 0) {
                a[i] /= f;
                cnt++;
            }

            cnt %= k;
            if (cnt != 0) {
                fac.push_back({f, cnt});
                comp.push_back({f, k-cnt});
            }
        }

        ans += tot[comp];
        tot[fac]++; 
    }

    printf("%lld\n",ans);
}


#include <fstream>


int main() {


    solve();
}