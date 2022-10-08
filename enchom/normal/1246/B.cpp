#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long ullong;
typedef long long llong;

ullong B1 = 127ULL;
ullong B2 = 47ULL;
ullong MOD = 1000000007ULL;
struct HASH
{
    ullong H1;
    ullong H2;

    HASH(): H1(0), H2(0) { }

    bool operator<(const HASH &other) const
    {
        return make_pair(H1, H2) < make_pair(other.H1, other.H2);
    }
};

vector<int> primes;
bool isPrime[100111];
const int MAXV = 100000;

vector< pair<int,int> > divMasks[100111];
HASH divHashes[100111];
HASH invHashes[100111];

inline void addDivisor(int num, int div)
{
    if (!divMasks[num].empty() && divMasks[num].back().first == div)
        divMasks[num].back().second++;
    else
        divMasks[num].push_back(make_pair(div, 1));
}

int n,k;

map<HASH, int> mymap;
map<HASH, int>::iterator myit;

int main()
{
    int i,j;

    for (i=2;i<=MAXV;i++)
    {
        isPrime[i] = true;
    }

    for (i=2;i<=MAXV;i++)
    {
        if (!isPrime[i])
            continue;
        primes.push_back(i);
        for (j=i+i;j<=MAXV;j+=i)
        {
            isPrime[j] = false;
        }
    }

    for (i=2;i<=MAXV;i++)
    {
        int v = i;
        for (j=0;j<primes.size();j++)
        {
            if (primes[j] * primes[j] > i)
                break;

            while(v % primes[j] == 0)
            {
                addDivisor(i, primes[j]);
                v /= primes[j];
            }
        }
        if (v > 1)
            addDivisor(i, v);
    }

    scanf("%d %d",&n,&k);

    for (i=1;i<=MAXV;i++)
    {
        for (j=0;j<divMasks[i].size();j++)
        {
            if (divMasks[i][j].second % k == 0)
                continue;

            divHashes[i].H1 *= B1;
            divHashes[i].H1 += (ullong)divMasks[i][j].first;
            divHashes[i].H1 *= B1;
            divHashes[i].H1 += (ullong)divMasks[i][j].second % k;

            divHashes[i].H2 *= B2;
            divHashes[i].H2 += (ullong)divMasks[i][j].first;
            divHashes[i].H2 %= MOD;

            divHashes[i].H2 *= B2;
            divHashes[i].H2 += (ullong)divMasks[i][j].second % k;
            divHashes[i].H2 %= MOD;

            ///

            invHashes[i].H1 *= B1;
            invHashes[i].H1 += (ullong)divMasks[i][j].first;
            invHashes[i].H1 *= B1;
            invHashes[i].H1 += k - ((ullong)divMasks[i][j].second % k);

            invHashes[i].H2 *= B2;
            invHashes[i].H2 += (ullong)divMasks[i][j].first;
            invHashes[i].H2 %= MOD;

            invHashes[i].H2 *= B2;
            invHashes[i].H2 += k - ((ullong)divMasks[i][j].second % k);
            invHashes[i].H2 %= MOD;
        }
    }

    llong ans = 0;
    for (i=1;i<=n;i++)
    {
        int a;

        scanf("%d",&a);

        myit = mymap.find(invHashes[a]);
        if (myit != mymap.end())
        {
            ans += (llong)((*myit).second);
        }

        myit = mymap.find(divHashes[a]);

        if (myit != mymap.end())
            (*myit).second += 1;
        else
            mymap.insert(make_pair(divHashes[a], 1));
    }

    printf("%lld\n",ans);

    return 0;
}