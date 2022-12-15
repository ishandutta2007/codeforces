#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

#define PB push_back
#define MP make_pair

const LL mod = 1000000007;

LL numq[66];
LL q,a,b;

LL pos(LL val)
{
    LL t = 2, h = 0;
    while (t <= val) t *= 2, h++;
    return h;
}
void round(LL h, LL m)
{
    numq[h] = numq[h]+(m%(1LL<<h)+(1LL<<h));
    numq[h] %= (1LL<<h);
}
void roundfull(LL h, LL m)
{
    FOR(i,h,66)
        round(i,m), m *= 2;
}
void get(LL v)
{
    LL H = pos(v);
    while (v != 1)
    {
        cout << v<<" ";
        LL pos = (v-(1LL<<H)+numq[H])%(1LL<<H);
        pos /= 2; H--;
        LL nv = (2*(1LL<<H)+pos-numq[H])%(1LL<<H)+(1LL<<H);
        v = nv;
    }
    cout << "1\n";
}

int main()
{
    cin >> q;
    FOR (i,0,q)
    {
        int type;
        cin >> type;
        if (type == 1) cin >>a>>b, round(pos(a),b);
        if (type == 2) cin >>a>>b, roundfull(pos(a),b);
        if (type == 3) cin >> a, get(a);
    }
}