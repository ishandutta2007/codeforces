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

const int MAX = 1000000;

#define skill first
#define index second

pair<tint, int> v[MAX];
tint finalSkill[MAX];
tint cumSum[MAX];

int main() 
{
    ios_base::sync_with_stdio(false);
    #ifdef ACMTUYO
        if (!freopen("b.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    tint A,cf,cm,m;
    while (cin >> N >> A >> cf >> cm >> m)
    {
        tint totalMissing = 0;
        forn(i,N)
        {
            cin >> v[i].skill;
            v[i].index = i;
            totalMissing += A - v[i].skill;
        }
        sort(v, v+N);
        tint res;
        if (m >= totalMissing)
        {
            res = A * cm + N * cf;
            forn(i,N) finalSkill[i] = A;
        }
        else
        {
            res = -1;
            tint prevSum = 0;
            cumSum[0] = 0;
            forsn(i,1,N+1) cumSum[i] = v[i-1].skill + cumSum[i-1];
            int bestFirstFull = 0;
            int bestMinSkill = 0;
            int bestB = 0;
            dforn(firstFull, N+1)
            {
                const tint totalFull = N - firstFull;
                if (firstFull < N)
                {
                    if (A - v[firstFull].skill > m) break;
                    m -= A - v[firstFull].skill;
                }
                
                tint minSkill;
                int a = 0, b = firstFull;
                while (b-a > 1)
                {
                    int c = (a+b)/2;
                    if (v[c].skill * c - cumSum[c] <= m)
                        a = c;
                    else
                        b = c;
                }
                minSkill = (m + cumSum[b]) / b;
                tint newRes = cf * totalFull + cm * minSkill;
                if (newRes > res)
                {
                    res = newRes;
                    bestFirstFull = firstFull;
                    bestMinSkill = minSkill;
                    bestB = b;
                }
                prevSum += minSkill;
            }
            forsn(i, bestFirstFull, N)
                v[i].skill = A;
            forn(i, bestB)
                v[i].skill = bestMinSkill;
            forn(i,N) finalSkill[v[i].index] = v[i].skill;
        }
        cout << res << endl;
        forn(i,N)
        {
            if (i) cout << " ";
            cout << finalSkill[i];
        }
        cout << endl;
    }
    if (_sc) return 0;
    return 0;
}