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

const int MAXN = 3 * 100007;

int delta[MAXN * 4],
    first[MAXN * 4], second[MAXN * 4],
    nfirst[MAXN * 4], nsecond[MAXN * 4];

void build(int left, int right, int x)
{
    delta[x] = 0;
    first[x] = 0;
    second[x] = 0x7f7f7f7f;
    nfirst[x] = right - left + 1;
    nsecond[x] = 0;

    if (left < right)
    {
        int mid = (left + right) >> 1;
        build(left, mid, x*2);
        build(mid+1, right, x*2+1);
    }
}

void down(int x)
{
    if (!delta[x]) return;

    first[x*2] += delta[x];
    second[x*2] += delta[x];
    delta[x*2] += delta[x];

    first[x*2+1] += delta[x];
    second[x*2+1] += delta[x];
    delta[x*2+1] += delta[x];

    delta[x] = 0;
}

void up(int x)
{
    int u = x*2, v = x*2+1;
    if (first[u] > first[v])
        swap(u, v);
    first[x] = first[u];
    nfirst[x] = nfirst[u];
    if (first[v] == first[u])
        nfirst[x] += nfirst[v];

    if (first[v] != first[u])
    {
        if (first[v] <= second[u])
        {
            second[x] = first[v];
            nsecond[x] = nfirst[v];

            if (first[v] == second[u])
                nsecond[x] += nsecond[u];
        }
        else
        {
            second[x] = second[u];
            nsecond[x] = nsecond[u];
        }
    }
    else
    {
        if (second[u] > second[v])
            swap(u, v);

        second[x] = second[u];
        nsecond[x] = nsecond[u];

        if (second[u] == second[v])
            nsecond[x] += nsecond[v];
    }
}

struct Minimun
{
    int f, s, nf, ns;
    Minimun() {}
    Minimun(int f, int nf, int s, int ns)
    {
        this->f = f;
        this->s = s;
        this->nf = nf;
        this->ns = ns;
    }
};

Minimun merge(Minimun u, Minimun v)
{
    //cout << "before1 " << u.f << " " << u.nf << " " << u.s << " " << u.ns << endl;
    //cout << "before2 " << v.f << " " << v.nf << " " << v.s << " " << v.ns << endl;
    Minimun ret;
    if (u.f > v.f)
        swap(u, v);
    ret.f = u.f;
    ret.nf = u.nf;
    if (u.f == v.f)
        ret.nf += v.nf;

    if (u.f != v.f)
    {
        if (v.f <= u.s)
        {
            ret.s = v.f;
            ret.ns = v.nf;

            if (v.f == u.s)
                ret.ns += u.ns;
        }
        else
        {
            ret.s = u.s;
            ret.ns = u.ns;
        }
    }
    else
    {
        if (u.s > v.s)
            swap(u, v);
        ret.s = u.s;
        ret.ns = u.ns;

        if (u.s == v.s)
            ret.ns += v.ns;
    }
   // cout << "after " << ret.f << " " << ret.nf << " " << ret.s << " " << ret.ns << endl;
    return ret;
}

void addInterval(int left, int right, int l, int r, int x, int d)
{
    if (l <= left && r >= right)
    {
        first[x] += d;
        second[x] += d;
        delta[x] += d;
        return;
    }

    int mid = (left + right) >> 1;
    down(x);
    if (l <= mid) addInterval(left, mid, l, r, x*2, d);
    if (r > mid) addInterval(mid+1, right, l, r, x*2+1, d);
    up(x);
}

Minimun intervalMinimun(int left, int right, int l, int r, int x)
{
    if (l <= left && r >= right)
    {
      //  cout << "out " << first[x] << " " << nfirst[x] << " " << second[x] << " " << nsecond[x] << endl;
        return Minimun(first[x], nfirst[x], second[x], nsecond[x]);
    }
    int mid = (left + right) >> 1;
    down(x);
    Minimun ret(0x7f7f7f7f, 0, 0x7f7f7f7f, 0);
    if (l <= mid) ret = intervalMinimun(left, mid, l, r, x*2);
    if (r > mid) ret = merge(ret, intervalMinimun(mid+1, right, l, r, x*2+1));
  //  up(x);
    return ret;
}

void printTree(int left, int right, int x)
{
    //cout << "printTree(" << left << "," << right << ") " << first[x] << " " << nfirst[x] << " " << second[x] << " " << nsecond[x] << "\n";
    if (left == right) return;
    int mid = (left + right) >> 1;
    down(x);
    printTree(left, mid, x*2);
    printTree(mid+1, right, x*2+1);
}

int num[MAXN], place[MAXN];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n)
    {
        cin >> num[i];
        place[--num[i]] = i;
    }

    long long ans = 0;
    build(0, n-1, 1);

    REP(i, n)
    {
        int u = -1, v = -1;
        if (place[i])
            u = num[place[i]-1];
        if (place[i] + 1 < n)
            v = num[place[i]+1];

        if (u > i) u = -1;
        if (v > i) v = -1;

        if (u < v) swap(u, v);

     //   cout << "u = " << u << " v = " << v << endl;

        if (u == -1 && v == -1)
        {
            addInterval(0, n-1, 0, i, 1, 1);
        }
        else
        {
            //cout << "here";
            addInterval(0, n-1, u+1, i, 1, 1);
            if (v != -1)
                addInterval(0, n-1, 0, v, 1, -1);
        }

        Minimun m = intervalMinimun(0, n-1, 0, i, 1);

       // cout << first[1] << " " << nfirst[1] << " " << second[1] << " " << nsecond[1] << endl;
    //   printTree(0, n-1, 1);
     //  cout << m.f << " " << m.nf << " " << m.s << " " << m.ns << endl;

   //    cout << endl;

        if (m.f <= 2)
            ans += m.nf;
        if (m.s <= 2)
            ans += m.ns;
    }
    cout << ans-n << endl;

	return 0;
}