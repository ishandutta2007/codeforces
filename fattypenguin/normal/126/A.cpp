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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

ll t1,t2,x1,x2,t0;

ll xx=0,yy=0;

ll gcd(ll a,ll b) {return !b?a:gcd(b,a%b);}

void update(ll x,ll y)
{
    if (x<0) x=0;
    if (x>x1) x=x1;
    if (y<0) y=0;
    if (y>x2) y=x2;
    if (((ll)xx*t1+yy*(ll)t2)>=(xx+yy)*t0)
    {
        if ((x+y)*t0<=((ll)x*t1+y*(ll)t2))
        {
            if ((long long)(x+y)*((ll)xx*t1+yy*(ll)t2)==(ll)(xx+yy)*((ll)x*t1+y*(ll)t2))
            {
                if (x+y>xx+yy) xx=x,yy=y;
            }
            else
            {
                ll up = ((ll)xx*t1+yy*(ll)t2),down=(xx+yy);
                ll upp = ((ll)x*t1+y*(ll)t2),downn=x+y;
                if (up*downn>upp*down) xx=x,yy=y;
            }
        }
    } else xx=x,yy=y;
}

int main()
{
    cin>>t1>>t2>>x1>>x2>>t0;
    if (t0==t1||t0==t2)
    {
        if (t0==t1) xx=x1;
        if (t0==t2) yy=x2;
        cout<<xx<<" "<<yy<<endl;
        return 0;
    }
    if (t0<t1&&t0<t2)
    {
        if (t1==t2) xx=x1,yy=x2;
        if (t1<t2) xx=x1,yy=0;
        if (t2<t1) xx=0,yy=x2;
        cout<<xx<<" "<<yy<<endl;
        return 0;
    }
    if (t0>t1&&t0>t2)
    {
        if (t1==t2) xx=x1,yy=x2;
        if (t1<t2) xx=0,yy=x2;
        if (t2<t1) xx=x1,yy=0;
        cout<<xx<<" "<<yy<<endl;
        return 0;
    }
    for (ll i = 0;i <= x1;++i)
    {
        ll y = (t1*i-t0*i)/(t0-t2);
        update(i,y);
        update(i,y-1);
        update(i,y+1);
    }
    swap(xx,yy);
    swap(x1,x2);
    swap(t1,t2);
    for (ll i = 0;i <= x1;++i)
    {
        ll y = (t1*i-t0*i)/(t0-t2);
        update(i,y);
        update(i,y-1);
        update(i,y+1);
    }
    swap(xx,yy);
    cout<<xx<<" "<<yy<<endl;
    return 0;
}