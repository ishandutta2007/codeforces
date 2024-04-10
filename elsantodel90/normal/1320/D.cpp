#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const int PCOUNT = 3;
const tint PRIME[PCOUNT] = {1615220161, 403880413, 1000000007};

const int MAXN = 500000;

tint primepot[PCOUNT][MAXN];
const tint BASE = 3LL;

struct Hash
{
    tint value1, value2, value3;
    Hash()
    {
        value1 = 0;
        value2 = 0;
        value3 = 0;
    }
    void sub(const Hash &other)
    {
        value1 = (PRIME[0] + value1  - other.value1) % PRIME[0];
        value2 = (PRIME[1] + value2  - other.value2) % PRIME[1];
        value3 = (PRIME[2] + value3  - other.value3) % PRIME[2];
    }
    void put(tint x)
    {
        assert(0 <= x && x < BASE);
        value1 = (BASE*value1 + x) % PRIME[0];
        value2 = (BASE*value2 + x) % PRIME[1];
        value3 = (BASE*value3 + x) % PRIME[2];
    }
    void mulpot(tint i)
    {
        value1 = (value1 * primepot[0][i]) % PRIME[0];
        value2 = (value2 * primepot[1][i]) % PRIME[1];
        value3 = (value3 * primepot[2][i]) % PRIME[2];
    }
    bool operator==(const Hash &o) const
    {
        return value1 == o.value1 &&
               value2 == o.value2 &&
               value3 == o.value3;
    }
};

Hash hashes[2][MAXN];
int zeroCount[MAXN];

Hash gethash(int index, int i, int j)
{
    Hash ret = hashes[index][j];
    Hash aux = hashes[index][i];
    aux.mulpot(j-i);
    ret.sub(aux);
    return ret;
}

int nextZero[MAXN];
//int zeroNum[MAXN]; EQUALS zeroCount

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    forn(p,PCOUNT)
    {
        primepot[p][0] = 1;
        forsn(i,1, MAXN)
            primepot[p][i] = (primepot[p][i-1] * BASE) % PRIME[p];
    }
    int N;
    string cad;
    cin >> N >> cad;
    zeroCount[0] = 0;
    forn(i,N)
        zeroCount[i+1] = zeroCount[i] + (cad[i] == '0');
    int lastZero = N;
    dforn(i,N)
    {
        if (cad[i] == '0')
            lastZero = i;
        nextZero[i] = lastZero;
    }
    
    
    int zeroParity = 0;
    Hash h[2] = {Hash(), Hash()};
    hashes[0][0] = hashes[1][0] = Hash();
    int zccc = 0;
    forn(i,N)
    {
        if (cad[i] == '0')
        {
            h[0].put(1+zeroParity);
            h[1].put(1+(1-zeroParity));
            assert(zccc == zeroCount[i]);
            zccc++;
            hashes[0][zccc] = h[0];
            hashes[1][zccc] = h[1];
        }
        zeroParity = (zeroParity + (cad[i] == '1'))%2;
    }
    int Q; cin >> Q;
    forn(query, Q)
    {
        int l1,l2, len;
        cin >> l1 >> l2 >> len;
        int i1 = l1-1;
        int j1 = l1-1 + len;
        int i2 = l2-1;
        int j2 = l2-1 + len;
        bool ok = true;
        int zc = zeroCount[j1] - zeroCount[i1];
        int zc2 = zeroCount[j2] - zeroCount[i2];
        if (zc != zc2)
            ok = false;
        else if (zc > 0)
        {
            int p1 = (nextZero[i1] - i1) % 2;
            int p2 = (nextZero[i2] - i2) % 2;
            Hash h1 = gethash((p1 != ((nextZero[i1]-zeroCount[i1])%2)), zeroCount[i1], zeroCount[j1]);
            Hash h2 = gethash((p2 != ((nextZero[i2]-zeroCount[i2])%2)), zeroCount[i2], zeroCount[j2]);
            if (!(h1 == h2))
                ok = false;
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}