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

const int MAXN = 2*100007;

int occ[MAXN*4], len[MAXN*4], L[MAXN*4], R[MAXN*4], maxi[MAXN*4], pos[MAXN*4];

void build(int left, int right, int x)
{
    occ[x] = 0;
    L[x] = R[x] = len[x] = right - left + 1;
    maxi[x] = -1;

    int mid = (left + right) >> 1;
    if (left < right)
    {
        build(left, mid, x*2);
        build(mid+1, right, x*2+1);
    }
}

void insert(int left, int right, int aim, int x, int delta)
{
    if (left == right)
    {
        occ[x] += delta;
        if (!occ[x])
            L[x] = R[x] = 1;
        else
            L[x] = R[x] = 0;

        return;
    }

    int mid = (left + right) >> 1;
    if (aim <= mid) insert(left, mid, aim, x*2, delta);
    else insert(mid+1, right, aim, x*2+1, delta);

    L[x] = L[x*2];
    if (L[x*2] == len[x*2]) L[x] += L[x*2+1];
    R[x] = R[x*2+1];
    if (R[x*2+1] == len[x*2+1]) R[x] += R[x*2];

    if (maxi[x*2] >= maxi[x*2+1])
    {
        maxi[x] = maxi[x*2];
        pos[x] = pos[x*2];
    }
    else
    {
        maxi[x] = maxi[x*2+1];
        pos[x] = pos[x*2+1];
    }

    if (R[x*2] != len[x*2] && L[x*2+1] != len[x*2+1])
    {
        int dis = (R[x*2] + L[x*2+1] + 1)>>1;
        int po;
        if (dis <= R[x*2])
            po = mid - (R[x*2]-dis);
        else po = mid + (dis-R[x*2]);

        if (dis > maxi[x] || (dis == maxi[x] && po <= pos[x]))
        {
            maxi[x] = dis;
            pos[x] = po;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> curr;
    map<int, int> where;

    build(0, n-1, 1);
    while (m--)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        if (1 == c1)
        {
            int first, last;
            if (!curr.size())
                first = last = n;
            else
            {
                first = *curr.begin();
                set<int>::iterator it = curr.end();
                last = n-1-*(--it);
            }

            int mid = maxi[1], mpos = pos[1];
        //    cout << first << " " << last << " " << mid << endl;
            int final;
            if (first >= last && first >= mid)
                final = 0;
            else if (mid >= last)
                final = mpos;
            else final = n-1;

            curr.insert(final);
            insert(0, n-1, final, 1, 1);
            where[c2] = final;
            printf("%d\n", final+1);
        }
        else
        {
            assert(where.find(c2) != where.end());
            int po = where[c2];
            curr.erase(curr.find(po));
            insert(0, n-1, po, 1, -1);
            where.erase(where.find(c2));
        }
    }
	return 0;
}