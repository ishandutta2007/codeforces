#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

typedef long long tint;
typedef pair<int,int> pint;

struct Mat
{
    int n;
    vector<vector<double> > v;
    Mat(int nn) : n(nn), v(n, vector<double>(n, 0.0)) {}
    Mat operator *(const Mat &o) const
    {
        Mat res(n);
        forn(i,n)
        forn(j,n)
        forn(k,n)
            res.v[i][j] += v[i][k] * o.v[k][j];
        return res;
    }
    Mat pot(tint k) const
    {
        // res_posta = x^k * res
        Mat x(*this), res(n);
        forn(i,n) res.v[i][i] = 1.0;
        while (k)
        {
            if (k%2) res = res * x;
            x = x*x;
            k /= 2;
        }
        return res;
    }
};

int v[128], pos[128];

double total = 0.0, e = 0.0;

int n;

void back(int KK)
{
    if (KK == 0)
    {
        int cant = 0;
        forn(j,n)
        forn(i,j)
        if (v[i] > v[j])
            cant++;
        total += 1.0;
        e += cant;
        return;
    }
    forsn(j, 1, n+1)
    forn(i,j)
    {
        vector<int> vv;
        forsn(k, i, j)
            vv.push_back(v[k]);
        forsn(k, i, j)
            v[k] = vv[vv.size() - 1 - (k-i)];
        back(KK-1);
        forsn(k, i, j)
            v[k] = vv[k-i];
    }
}

int main()
{   
    tint K; cin >> n >> K;
    forn(i,n)
    {
        cin >> v[i];
        v[i]--;
        pos[v[i]] = i;
    }
    back(K);
    printf("%.15lf\n", e/total);
    return 0;
}