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

LL n, k;
LL A[200];
vector<pair<LL, LL>> p;
vector<LL> val[200];
int frst = 1;
vector<LL> v1, v2;

LL enough(LL x)
{
    
if (frst)
{
    frst = 0;
    p.clear();
    FOR (i,0,n)
    {
        LL a = A[i];
        val[a].clear();
        val[a].push_back(1);
        while (val[a].back() <= x/a &&
               val[a].back()*a <= x) val[a].push_back(val[a].back()*a);
        p.push_back(make_pair(val[a].size(),a));
        //FOR (qwe,0,val[a].size()) cout << val[a][qwe]<<" -> ";
        //cout << endl;
    }
    
    v1.push_back(1); v2.push_back(1);
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    FOR (i,0,p.size())
    {
        //cout << v1.size()<<" "<<v2.size()<<endl;
        int dil = (int)p[i].second;
        if ((i%4) == 2 || (i%4) == 1)
        {
            int sz = (int)v2.size();
            FOR (j,0,sz)
            FOR (k,1,val[dil].size())
            if (v2[j] <= x/val[dil][k] &&
                v2[j]*val[dil][k] <= x)
                v2.push_back(v2[j]*val[dil][k]);
        }
        else
        {
            int sz = (int)v1.size();
            FOR (j,0,sz)
            FOR (k,1,val[dil].size())
            if (v1[j] <= x/val[dil][k] &&
                v1[j]*val[dil][k] <= x)
                v1.push_back(v1[j]*val[dil][k]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return 0;
}
    
    int p2 = v2.size()-1;
    LL ans = 0;
    //FOR (i,0,v1.size()) cout << v1[i]<<" and ";
    //cout << endl;
    //FOR (j,0,v2.size()) cout << v2[j]<<" AND ";
    //cout << endl;
    FOR (p1,0,v1.size())
    {
        while (p2 >= 0 && (v1[p1] > x/v2[p2] ||
                           v1[p1]*v2[p2] > x)) p2--;
        if (p2 < 0) break;
        ans += p2+1;
    }
    //cout <<"&"<< ans << endl;
    return k - ans;
}

int main()
{
    cin >> n;
    FOR (i,0,n) cin >> A[i]; sort(A,A+n);
    cin >> k;
    
    LL l = 0, r = 1000*1000*1000LL*1000*1000*1000;
    enough(r);
    while (l != r)
    {
        LL x = (l+r)/2;
        
        LL delta = enough(x);
        //cout << l<<" "<<r<<" "<<x <<" "<<delta<< endl;
        if (delta <= 0) r = x+delta;
        else l = x+delta;
    }
    cout << l;
}