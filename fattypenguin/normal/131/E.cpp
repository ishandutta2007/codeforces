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
#include <cassert>
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
typedef set<int>::iterator SI;

int BASE;

vector<pair<int,int> > c[200007];
int x[200007],y[200007],s[200007];

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>m>>n;
    REP(i,n) cin>>x[i]>>y[i];
    REP(i,n) s[i]=0;

    REP(i,2*m+1) c[i].clear();
    REP(i,n) c[x[i]].PB(MP(y[i],i));
    REP(i,m+1) SORT(c[i]);
    REP(i,m+1)
    {

        for (int j = 0;j < c[i].size();++j)
            if (j>=1&&j+1<c[i].size())
                s[c[i][j].second]+=2;
            else if (c[i].size()>1) s[c[i][j].second]+=1;
    }

    REP(i,2*m+1) c[i].clear();
    REP(i,n) c[y[i]].PB(MP(x[i],i));
    REP(i,m+1) SORT(c[i]);
    REP(i,m+1)
    {
        for (int j = 0;j < c[i].size();++j)
            if (j>=1&&j+1<c[i].size())
                s[c[i][j].second]+=2;
            else if (c[i].size()>1) s[c[i][j].second]+=1;
    }


    REP(i,2*m+1) c[i].clear();
    REP(i,n) c[x[i]+y[i]].PB(MP(x[i]-y[i],i));
    REP(i,2*m+1) SORT(c[i]);
    REP(i,2*m+1)
    {
        for (int j = 0;j < c[i].size();++j)
            if (j>=1&&j+1<c[i].size())
                s[c[i][j].second]+=2;
            else if (c[i].size()>1) s[c[i][j].second]+=1;
    }

    REP(i,2*m+1) c[i].clear();
    REP(i,n) c[x[i]-y[i]+m].PB(MP(x[i]+y[i],i));
    REP(i,2*m+1) SORT(c[i]);
    REP(i,2*m+1)
    {
        for (int j = 0;j < c[i].size();++j)
            if (j>=1&&j+1<c[i].size())
                s[c[i][j].second]+=2;
            else if (c[i].size()>1) s[c[i][j].second]+=1;
    }
    int ss[9];
    CLEAR(ss);
    REP(i,n) { ++ss[s[i]];}
    REP(i,9)
    {
        if (i) cout<<" ";
        cout<<ss[i];
    }
    cout<<endl;
}