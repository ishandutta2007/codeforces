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
#include <assert.h>
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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

priority_queue<PII> Q;

MII m;

struct PIII
{
    int a,b,c;
    PIII(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    PIII() {};
};

vector<vector<int> > fr;
vector<int> aa;

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    fr.resize(n);
    REP(i,n)
    {
        fr[i].clear();
        int a;
        REP(j,n)
        {
            cin>>a;
            --a;
            if (a!=i) fr[i].PB(a);
        }
    }
    aa.clear();
    int answer[3000],inv[3000];
    REP(i,n)
    {
        int a;
        cin>>a;
        aa.PB(--a);
        inv[a] = i;
    }
    CLEAR(answer);
    REP(i,n)
    {
        REP(j,n-1)
        {
            bool ok = true;
            for (int k = 0;k < fr[i][j];++k)
                if (inv[k]<inv[fr[i][j]]&&k!=i)
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                answer[i] = fr[i][j];
                break;
            }
        }
    }
    REP(i,n)
    {
        if (i) cout << " ";
        cout<<answer[i]+1;
    }
    return 0;
}