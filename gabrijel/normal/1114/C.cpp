#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const long long int inf = 1e18 + 100;

long long int n, b;
long long int pb;

long long int trb, kolko;

long long int rj = inf;

vector <pair <long long int, long long int> > pf;
vector <long long int> kol;

vector <long long int> kasnije;

int main()
{
    cin >> n >> b;
    pb = b;
    REP(i, 2, int((long long)sqrtl(b)) + 1)
    {
        trb = (long long) i;
        kolko = 0;
        while(pb && pb % trb == 0)
        {
            pb = (long long) pb / (long long) trb;
            kolko++;
        }
        if(kolko)
        {
            pf.push_back(make_pair(trb, kolko));
            kasnije.push_back((long long) b / trb);
            if(pb / trb > (long long) 1) kasnije.push_back((long long) pb / trb);
        }
    }
    kasnije.push_back(b);
    REP(i, 0, (int)kasnije.size())
    {
        trb = kasnije[i];
        kolko = 0;
        while(pb && pb % trb == 0)
        {
            pb = (long long) pb / (long long) trb;
            kolko++;
        }
        if(kolko)
        {
            pf.push_back(make_pair(trb, kolko));
        }
    }
    if(pb != 1) pf.push_back(make_pair(pb, 1));
    /*REP(i, 0, (int)pf.size())
    {
        cout << pf[i].first << " " << pf[i].second << endl;
    }*/
    REP(i, 0, (int)pf.size())
    {
        trb = pf[i].first;
        kolko = 0;
        while(trb <= n)
        {
            kolko += (long long) n / (long long) trb;
            //if(trb > (long long) 1e9 + 100) break;
            //trb = (long long) trb * trb;
            if(inf / trb < pf[i].first) break;
            trb *= pf[i].first;
        }
        kol.push_back(kolko);
    }
    REP(i, 0, (int)pf.size())
    {
        rj = min(rj, (long long) kol[i] / (long long) pf[i].second);
    }
    cout << rj << endl;
    return 0;
}