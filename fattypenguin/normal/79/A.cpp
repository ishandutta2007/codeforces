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

const long double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

bool Win(int x,int y,bool first)
{
    if ((x*100 + y*10 < 220) || y < 2) return false;
    if (first)
    {
        if (y >= 22)
            return !Win(x,y-22,!first);
        else if (y >= 12 && x >= 1)
            return !Win(x-1,y-12,!first);
        else if (y >= 2 && x >= 2)
            return !Win(x-2,y-2,!first);
        else return false;
    }
    else
    {
        if (x >= 2 && y >= 2)
            return !Win(x-2,y-2,!first);
        else if (x && y >= 12)
            return !Win(x-1,y-12,!first);
        else if (y >= 22)
            return !Win(x,y-22,!first);
        else
            return false;
    }
}

int main()
{
    int x,y;
    cin >> x >> y;
    while (x >= 2 && y >= 24)
    {
        x -= 2;
        y -= 24;
    }
    if (Win(x,y,0))
        cout << "Ciel\n";
    else
        cout << "Hanako\n";
    return 0;

}