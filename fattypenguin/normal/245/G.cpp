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
#include <ext/hash_map>
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

using namespace __gnu_cxx;

short com[10001][10001];
bitset<10001> edge[10001];

VI e[10001];

char buff[11111];

string nextToken()
{
    scanf("%s", buff);
    return string(buff);
}

int n = 0;
map<string, int> dict;
string names[55555];
int getIndex(const string &s)
{
    if (dict.find(s) != dict.end())
        return dict[s];
    names[n] = s;
    return dict[s] = n++;
}

int main()
{
    int m;
    cin >> m;
    REP(i, m)
    {
        string su = nextToken(),
               sv = nextToken();
        int u = getIndex(su),
            v = getIndex(sv);
        edge[u][v] = edge[v][u] = 1;
        e[u].PB(v);
        e[v].PB(u);
    }

    REP(i, n)
    {
        REP(j, e[i].size())
            REP(k, j) if (!edge[e[i][j]][e[i][k]])
            {
                ++com[e[i][j]][e[i][k]];
                ++com[e[i][k]][e[i][j]];
            }
    }

    cout << n << endl;
    REP(i, n)
    {
        cout << names[i] << " ";
        int maxi = 0, num = 0;
        REP(j, n)
        {
            if (i == j || edge[i][j]) continue;
            if (com[i][j] > maxi)
            {
                maxi = com[i][j];
                num = 0;
            }

            if (com[i][j] == maxi)
                ++num;
        }

        //if (!maxi) num = 0;
        cout << num << endl;
    }
	return 0;
}