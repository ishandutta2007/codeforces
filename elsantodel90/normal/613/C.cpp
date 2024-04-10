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

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

char output[1000000];

int v[32];

int bag[32], mybag[32];

tint gcd(tint a,tint b) { return (b == 0) ? a : gcd(b, a % b); }

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("c.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        forn(i,n) _sc = scanf("%d", &v[i]);
        int L = 0;
        forn(i,n) L += v[i];
        output[L] = 0;
        
        int q = v[0];
        forn(i,n) q = gcd(q, v[i]);
        const int bagLength = L / q;
        forn(i,n) bag[i] = v[i] / q;
        int next = 0;
        forn(j,bagLength)
        {
            while (bag[next] == 0) next++;
            output[j] = 'a' + next;
            bag[next]--;
        }
        forsn(i,1,q)
        {
            if (i % 2 == 0)
                forn(j,bagLength)
                    output[bagLength*i + j] = output[j];
            else
                forn(j,bagLength)
                    output[bagLength*i + j] = output[bagLength-1-j];
        }
        
        int res;
        if (L % 2)
        {
            assert(bagLength % 2);
            int odd = 0;
            forn(i,n) if((v[i] / q) % 2) odd++;
            if (odd != 1)
            {
                res = 0;
            }
            else
            {
                forn(i,n)
                {
                    bag[i] = v[i] / q;
                    if (bag[i] % 2)
                        odd = i;
                    bag[i] /= 2;
                }
                next = 0;
                output[bagLength / 2] = 'a' + odd;
                forn(j,bagLength / 2)
                {
                    while (bag[next] == 0) next++;
                    output[j] = 'a' + next;
                    output[bagLength-1-j] = 'a' + next;
                    bag[next]--;
                }
                
                forsn(i,1,q)
                forn(j,bagLength)
                    output[bagLength*i + j] = output[j];
                
                res = q;
            }
        }
        else
        {
            if (q % 2)
                res = 0;
            else
            {
                res = 2 * ((L / 2) / bagLength);
                forsn(i, L/2, L)
                    output[i] = output[L/2-1-(i - L/2)];
            }
        }
        printf("%d\n%s\n", res, output);
    }
    if (_sc) return 0;
    return 0;
}