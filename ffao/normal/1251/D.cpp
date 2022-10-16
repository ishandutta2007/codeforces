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
 
 
int t;
int n;
long long s;
 
long long l[212345];
long long r[212345];
 
bool check(long long md) {
    long long sum = 0;
    vector<long long> canS;
    for (int i = 0; i < n; i++) {
        if (r[i] >= md) canS.push_back(l[i]);
        else sum += l[i];
    }
 
    sort(canS.begin(), canS.end());
    int tgt = (n+1)/2;
    int has = canS.size();
    if (has < tgt) return false;
 
    for (int i = 0; i < canS.size(); i++) {
        if (i < has-tgt) sum += canS[i];
        else sum += max(md, canS[i]);
    }
 
    return sum <= s;
}
 
void solve()
{
    for (scanf("%d", &t); t; t--) {
        scanf("%d %lld", &n, &s);
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &l[i], &r[i]);
        }
 
        long long st = 0, ed = 1000000000000000LL;
        while (st < ed) {
            long long md = (st+ed+1)/2;
 
            if (check(md)) st = md;
            else ed = md-1;
        }
        printf("%lld\n", st);
    }
}
 
 
#include <fstream>
 
 
int main() {
 
 
    solve();
}