#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9+7;
const int N = 1e5+10;
const int M = 1e4;

int main()
{
    //freopen("input.txt", "r", stdin);
    map<pair<int,int>,int> m;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << a+(b-d) << ' ' << b << ' ' << a+(b-d) << ' ' << d << endl;
        return 0;
    }
    if(b == d)
    {
        cout << a << ' ' << b+(a-c) << ' ' << c << ' ' << d+(a-c) << endl;
        return 0;
    }
    int x[2];
    int y[2];
    x[0] = min(a,c);
    x[1] = max(a,c);
    y[0] = min(b,d);
    y[1] = max(b,d);
    m[make_pair(a,b)] =1;
   m[make_pair(c,d)] =1;
    if(x[1] - x[0] != y[1] - y[0])
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(!m.count(make_pair(x[i],y[j])))
            {
                cout << x[i] << ' ' << y[j] << ' ';
            }
        }
    }
    return 0;
}