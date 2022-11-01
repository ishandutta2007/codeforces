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

int s[100007];

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    REP(i,n) cin>>s[i];
    bool all1 = true,allm = true;
    REP(i,n) if (s[i]!=1) all1 = false;
    REP(i,n) if (s[i]!=1000000000) allm = false;
    sort(s,s+n);
    if (n > 1)
    {
        cout<<1;
        REP(i,n-1)
        {
            int y = s[i];
            if (i) y = min(y,s[i-1]);
            if (i != n-2)
            {
                cout<<" "<<s[i];
            }
            else
            {
                if (all1) cout<<" "<<2; else cout<<" "<<s[i];
            }
        }
        cout<<endl;
    }
        else cout << (s[0]==1?2:1) <<endl;
    return 0;
}