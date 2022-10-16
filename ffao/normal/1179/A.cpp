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


int n,q;
int a[110000];

vector<int> rg;
vector< pair<int, int> > pulled;

void solve()
{
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cur = a[0];
    for (int i = 0; i < n-1; i++) {
        pulled.push_back({cur, a[i+1]});

        if (cur < a[i+1]) swap(cur, a[i+1]);
        rg.push_back(a[i+1]);
    }

    for (int i = 0; i < q; i++) {
        long long pos;
        scanf("%lld", &pos);

        pos--;
        if (pos < n-1) {
            printf("%d %d\n", pulled[pos].first, pulled[pos].second);
        }
        else {
            pos %= (n-1);
            printf("%d %d\n", cur, rg[pos]);
        }
    }
}


#include <fstream>


int main() {


    solve();
}