#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int n,k,m,a[111],d[111],mn=oo,mx=-oo;

int main()
{
    cin >> n >> k;
    m=n/k;
    for (int i=1;i<=n;i++) cin >> a[i];
    int q,x,c=0,app=0;
    cin >> q;
    while (q--)
    {
        int s=0,first=0;
        for (int i=0;i<m;i++) 
        {
            cin >> x;
            if (!d[x]) first=1;
            d[x]=1; s+=a[x];
        }
        app+=first;
        mn=min(mn,s); mx=max(mx,s);
    }
    vector <int> b;
    for (int i=1;i<=n;i++) if (!d[i]) c++;
    if (c>=m && app<k)
    {
        for (int i=1;i<=n;i++) if (!d[i]) b.pb(a[i]);
        sort(b.begin(),b.end());
        int s=0;
        fr(i,0,m-1) s+=b[i];
        mn=min(mn,s); mx=max(mx,s);
        s=0;
        fr(i,0,m-1) s+=b[c-1-i];
        mn=min(mn,s); mx=max(mx,s);
    }
    double re=1.0*mn/m,ree=1.0*mx/m;
    printf("%.10lf %.10lf\n",re,ree);
    return 0;
}