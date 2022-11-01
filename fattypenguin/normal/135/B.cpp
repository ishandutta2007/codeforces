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

int x[8],y[8];

long long dis(int a,int b) {return (long long)(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);}

int main()
{
    REP(i,8) cin>>x[i]>>y[i];
    REP(i,(1<<8))
    {
        vector<int> a,b;
        a.clear();
        b.clear();
        REP(j,8)
            if (i&(1<<j)) a.PB(j); else b.PB(j);
        if (a.size()!=4) continue;
        bool flag = false;
        REP(j,4) REP(k,4)
            if (j!=k)
                if (x[a[j]]==x[a[k]]&&y[a[j]]==y[a[k]])
                    flag = true;
        REP(j,4) REP(k,4)
            if (j!=k)
                if (x[b[j]]==x[b[k]]&&y[b[j]]==y[b[k]])
                    flag = true;
        if (flag) continue;
        int m=0,M=0;
        REP(j,4)
        {
            if (dis(a[m],a[j])>dis(a[m],a[M])) M=j;
        }
        if (m==M) continue;
        bool ok = true;
        REP(j,4) REP(k,4)
            if (j<k&&j!=m&&k!=M&&j!=M&&k!=m)
            {
                if (dis(a[j],a[k])!=dis(a[m],a[M])) ok=false;
                if ((long long)(x[a[j]]-x[a[k]])*(x[a[m]]-x[a[M]])+(y[a[j]]-y[a[k]])*(y[a[m]]-y[a[M]])!=0) ok = false;
                if ((long long)(x[a[m]]-x[a[k]])*(x[a[M]]-x[a[k]])+(y[a[m]]-y[a[k]])*(y[a[M]]-y[a[k]])!=0) ok = false;
            }
        if (!ok) continue;
        REP(i,4) swap(a[i],b[i]);
        m=0,M=0;
        REP(j,4)
        {
            if (dis(a[m],a[j])>dis(a[m],a[M])) M=j;
        }
        if (m==M) continue;
        ok = true;
        REP(j,4) REP(k,4)
            if (j<k&&j!=m&&k!=M&&j!=M&&k!=m)
            {
                if (dis(a[j],a[k])!=dis(a[m],a[M])) ok=false;
                if ((long long)(x[a[m]]-x[a[k]])*(x[a[M]]-x[a[k]])+(y[a[m]]-y[a[k]])*(y[a[M]]-y[a[k]])!=0) ok = false;
                if ((long long)(x[a[m]]-x[a[j]])*(x[a[M]]-x[a[j]])+(y[a[m]]-y[a[j]])*(y[a[M]]-y[a[j]])!=0) ok = false;
            }
        if (!ok) continue;
        cout<<"YES\n";
        REP(i,4)
        {
            if (i) cout<<" ";
            cout<<b[i]+1;
        }
        cout<<endl;
        REP(i,4)
        {
            if (i) cout<<" ";
            cout<<a[i]+1;
        }
        cout<<endl;
        return 0;
    }
        cout<<"NO\n";
    return 0;
}