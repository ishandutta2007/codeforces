#include <string>
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

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);


using namespace std;


typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()


int n,m;

int block[110000];
int be[110000];
int pd[110000];

void solve()
{
    re(n,m);
    vi monst(n), spec(m);
    re(monst,spec);

    sort(all(monst));
    sort(all(spec));


    for (int i = 0; i < n; i++) {
        if (i == 0 || monst[i] != monst[i-1] + 1) block[i] = i;
        else block[i] = block[i-1];
        be[block[i]] = i;
    }

    int curs = 0;
    for (int md = 0; md < n; md++) if (block[md] == md) {
        int z = (md != 0 ? pd[block[md-1]] : 0);
        while (curs < m && spec[curs] <= monst[be[md]]) curs++;
        for (int take = 1; take <= curs; take++) {
            int need = max(0, monst[md] - spec[curs-take]);
            //printf("take %d need %d\n", take, need);
            if (md-need >= 0) {
                z = max(z, take + (block[md-need] ? pd[block[block[md-need]-1]] : 0));
            }
        }

        //printf("z=%d curs=%d\n",z,curs);
        pd[block[md]] = max(pd[block[md]], z);
        for (int takefrt = 1; takefrt <= m - curs; takefrt++) {
            int need = max(0, spec[curs+takefrt-1] - monst[be[md]]);
            int nxt = be[md]+need;
            if (nxt < n) {
                //printf("%d -> %d: %d\n", md, block[nxt],z+takefrt);
                pd[block[nxt]] = max(pd[block[nxt]], z + takefrt);
            }
        }

        //printf("md = %d pd %d\n", md, pd[md]);
    }

    printf("%d\n", pd[block[n-1]]);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }