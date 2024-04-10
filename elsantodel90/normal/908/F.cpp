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

using namespace std;

typedef long long tint;
typedef long double tdbl;

tint calcHueco(const vector<int> points, tint prev, tint next)
{
    if (points.empty()) return 0;
    
    tint best = max(tint(points.front()) - prev, next - tint(points.back()));
    forn(i, points.size()-1)
        best = max(best, tint(points[i+1]) - points[i]);
    return best;
}

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("f.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N)
    {
        int lastGreen = -1;
        vector<int> points[2];
        tint ret = 0;
        forn(i,N)
        {
            int pos; char col;
            cin >> pos >> col;
            assert(col == 'R' || col == 'B' || col == 'G');
            if (col == 'G')
            {
                if (lastGreen == -1)
                {
                    // Primer verde
                    forn(k,2)
                    if (!points[k].empty())
                        ret += pos - points[k].front();
                }
                else
                {
                    const tint T = pos - lastGreen;
                    tint hueco[2];
                    forn(k,2) hueco[k] = calcHueco(points[k], lastGreen, pos);
                        
                    if (points[0].empty() && points[1].empty())
                        ret += T;
                    else if (points[0].empty() || points[1].empty())
                        ret += 2*T - hueco[0] - hueco[1];
                    else
                        ret += min(3*T - hueco[0] - hueco[1], 2*T);
                }
                forn(k,2) points[k].clear();
                lastGreen = pos;
            }
            else if (col == 'B')
                points[0].push_back(pos);
            else
                points[1].push_back(pos);
        }
        if (lastGreen == -1)
        {
            // No hay verdes
            forn(k,2)
            if (!points[k].empty())
                ret += points[k].back() - points[k].front();
        }
        else
        {
            forn(k,2)
            if (!points[k].empty())
                ret += points[k].back() - lastGreen;
        }
        cout << ret << endl;
    }
    return 0;
}