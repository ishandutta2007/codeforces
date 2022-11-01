#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

vector<ll> lucky;

void gao(int dep,long long now)
{
    if (now) lucky.PB(now);
    if (dep >= 18) return;
    gao(dep+1,now*10+4);
    gao(dep+1,now*10+7);
}

int n;
unsigned long long mini;
unsigned long long L[100007],R[100007],k;

struct BigInteger {
        static const int LEN = 2;
        static const long long MOD;
        long long a[LEN];

        explicit BigInteger(long long x) {
                fill(a + 1, a + LEN, 0LL);
                a[0] = x;
                for (int i = 0; a[i] >= MOD; ++i) {
                        a[i + 1] += a[i] / MOD;
                        a[i] %= MOD;
                }
        }

        BigInteger(const BigInteger& o) {
                copy(o.a, o.a + LEN, a);
        }

        void operator+=(const BigInteger& o) {
                for (int i = 0; i < LEN; ++i) {
                        a[i] += o.a[i];
                        while (a[i] >= MOD) {
                                ++a[i + 1];
                                a[i] -= MOD;
                        }
                }
        }

        void operator-=(const BigInteger& o) {
                for (int i = 0; i < LEN; ++i) {
                        a[i] -= o.a[i];
                        while (a[i] < 0) {
                                --a[i + 1];
                                a[i] += MOD;
                        }
                }
        }

        bool operator<=(const BigInteger& o) {
                for (int i = LEN - 1; i >= 0; --i) {
                        if (a[i] != o.a[i]) {
                                return a[i] < o.a[i];
                        }
                }
                return true;
        }

        void dump() const {
                for (int i = LEN - 1; i >= 0; --i) {
                        printf("%08lld,", a[i]);
                }
                puts("");
        }
};

bool gao(int len)
{
    long long last = lucky[0],last2 = lucky[len-1],now = 0,p1 = 0,p2 = 0;
    BigInteger cnt(0),ff(k);
   // long long cnt = 0,ff = k;
    while (p1 < n && L[p1] <= lucky[0]) ++p1;
    for (int i = p1;i < n;++i) cnt += BigInteger(L[i] - lucky[0]);
    while (p2 < n && R[p2] <= lucky[len-1]) ++p2;
    REP(i,p2) cnt += BigInteger(lucky[len-1] - R[i]);
    for (int i = 0;i+len-1 < lucky.size();++i)
    {
        long long p3 = p2;
        while (p1 < n && L[p1] <= lucky[i]) cnt -= BigInteger(L[p1]-last),++p1;
        while (p2 < n && R[p2] <= lucky[i+len-1]) cnt += BigInteger(lucky[i+len-1]-R[p2]),++p2;
        cnt -= BigInteger((lucky[i]-last)*(n-(long long)p1));
        cnt += BigInteger((lucky[i+len-1]-last2)*((long long)p3));
        last = lucky[i],last2 = lucky[i+len-1];
     //  cnt.dump();
   //  cout<<cnt<<endl;
        if (lucky[i+len-1]-lucky[i] <= mini && cnt <= ff) return true;
        if (p1 >= n && !(cnt<=ff)) return false;
    }
    return false;
}

const long long BigInteger::MOD = 100000000000000000LL;

int main()
{
    cin>>n>>k;
    REP(i,n) cin>>L[i]>>R[i];
    mini = R[0] - L[0];
    REP(i,n) mini = min(mini,R[i]-L[i]);
    sort(L,L+n);
    sort(R,R+n);
    gao(0,0);
    SORT(lucky);
    int l = 0,r = lucky.size();
    while (l < r)
    {
        int mid = ((l+r)>>1)+1;
        if (gao(mid))
            l = mid;
        else r= mid-1;
    }
    cout << l << endl;
    return 0;
}