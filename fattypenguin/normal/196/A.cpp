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

set<pair<int, int> > S;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.size();
    VI cur[26];
    REP(i, n) cur[s[i]-'a'].PB(i);
    string ans;
    int cnt = -1;
    while (1)
    {
        int where = -1;
        for (int j = 25; j >= 0; --j)
        {
            VI::iterator it = upper_bound(ALL(cur[j]), cnt);
            if (it == cur[j].end()) continue;
            ans += (char)('a'+j);
            cnt = *it;
            where = 1;
            break;
        }

        if(-1 == where) break;
    }
    cout << ans << endl;

	return 0;
}