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

char img[2][100007];
int dist[2][100007];

int main()
{
    int n, k;
    cin >> n >> k;
    REP(i, 2) scanf("%s", img[i]);
    FILL(dist, 0x7f);
    dist[0][0] = 0;
    queue<pair<int, int> > Q;
    Q.push(MP(0, 0));
    bool ans = false;
    int d[3] = {-1, 1, k};
    while (Q.size() && !ans)
    {
        int x = Q.front().first,
            y = Q.front().second;
        Q.pop();
        REP(k, 3)
        {
            int nx = k == 2 ? 1 - x : x,
                ny = y + d[k];
            if (ny >= n)
            {
                ans = true;
                break;
            }
            if (ny < 0) continue;
            if (img[nx][ny] == 'X') continue;
            if (ny < dist[x][y]+1) continue;
            if (dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                Q.push(MP(nx, ny));
            }
        }

    }
        if (ans)
            cout << "YES\n";
        else cout << "NO\n";
	return 0;
}