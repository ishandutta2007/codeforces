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

const LL mod = 1000000007;

vector<pair<int, int>> q1, q2, w1, w2;
vector<int> Q;
int k,n,m;
int x,y;
map<pair<int,int>, LL> qwe[500000];

LL powe(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b/= 2;
    }
    return res;
}

LL take2(LL num)
{
    return (powe(2,num)-2+mod)%mod;
}

int main()
{
    cin >> k >> n >> m;
    FOR (i,0,n)
    {
        cin >> x >> y; x--; y--;
        q1.push_back(make_pair(x,y));
    }
    FOR (i,0,m)
    {
        cin >> x >> y; x--; y--;
        q2.push_back(make_pair(x,y));
    }
    sort(q1.begin(),q1.end()); sort(q2.begin(), q2.end());
    FOR (i,0,q1.size())
    {
        while (w1.size() && w1.back().second >= q1[i].second) w1.pop_back();
        w1.push_back(q1[i]);
    }
    FOR (i,0,q2.size())
    {
        while (w2.size() && w2.back().second >= q2[i].second) w2.pop_back();
        w2.push_back(q2[i]);
    }
    map<int,int> u; u[0] = 0; u[k] = 0;
    FOR (i,0,w1.size()) u[w1[i].first] = 0, u[w1[i].second+1] = 0;
    FOR (i,0,w2.size()) u[w2[i].first] = 0, u[w2[i].second+1] = 0;
    int g = 0;
    for(map<int,int>::iterator it = u.begin(); it != u.end(); it++)
        Q.push_back(it->first), it->second = g, g++;
    FOR (i,0,w1.size()) w1[i].first = u[w1[i].first], w1[i].second = u[w1[i].second+1];
    FOR (i,0,w2.size()) w2[i].first = u[w2[i].first], w2[i].second = u[w2[i].second+1];
    qwe[0][make_pair(0,0)] = 1;
    FOR (i,0,Q.size()-1)
    {
        long pf = lower_bound(w1.begin(),w1.end(),make_pair(i,(int)mod)) - w1.begin();
        long ps = lower_bound(w2.begin(),w2.end(),make_pair(i,(int)mod)) - w2.begin();

        for (map<pair<int,int>, LL>::iterator it = qwe[i].begin(); it != qwe[i].end(); it++)
        {
            pair<int,int> pos = it->first;
            LL res = it->second;
            LL num = Q[i+1] - Q[i];
            
            //take 1 1
            if (pos.second == w2.size() || w2[pos.second].second > i+1)
            {
                qwe[i+1][make_pair(pf,pos.second)] += res;
                qwe[i+1][make_pair(pf,pos.second)]%= mod;
            }
            
            //take 1 2
            if (pos.first == w1.size() || w1[pos.first].second > i+1)
            {
                qwe[i+1][make_pair(pos.first,ps)] += res;
                qwe[i+1][make_pair(pos.first,ps)]%= mod;
            }
            
            // take 2
            if (num > 1)
            {
                res = (res*take2(num))%mod;
                qwe[i+1][make_pair(pf,ps)] += res;
                qwe[i+1][make_pair(pf,ps)] %= mod;
            }
        }
    }
    cout << qwe[Q.size()-1][make_pair(w1.size(),w2.size())];
    return 0;
}