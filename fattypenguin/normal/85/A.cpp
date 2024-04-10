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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    char ans[8][300];
    int n;
    memset(ans,0,sizeof(ans));
    cin >> n;
    if (n == 1)
    {
        cout << "a\na\nb\nb\n" << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << "aa\nbb\ncc\ndd\n" << endl;
        return 0;
    }
    if (n&1)
    {
        for (int i = 0;i < n/2;++i)
        {
            ans[0][i*2] = ans[0][i*2+1] = 'a'+(i&1);
            ans[3][1+i*2] = ans[3][1+i*2+1] = 'a'+(i&1);
        }
        for (int i = 0;i < n/2;++i)
        {
            ans[1][i*2] = ans[1][i*2+1] = 'e' + (i&1);
            ans[2][1+i*2] = ans[2][1+i*2+1] = 'u' + (i&1);
        }
        ans[0][n-1] = ans[1][n-1] = 'z';
        ans[2][0] = ans[3][0] = 'x';
    }
    else
    {
        for (int i = 0;i < n/2;++i)
        {
            ans[0][i*2] = ans[0][i*2+1] = 'a'+(i&1);
            ans[3][i*2] = ans[3][i*2+1] = 'a'+(i&1);
        }
        for (int i = 0;i < n/2-1;++i)
        {
            ans[1][1+i*2] = ans[1][1+i*2+1] = 'e' + (i&1);
            ans[2][1+i*2] = ans[2][1+i*2+1] = 'u' + (i&1);
        }
        ans[1][0] = ans[2][0] = 'z';
        ans[1][n-1] = ans[2][n-1] = 'x';
    }
    for (int i = 0;i < 4;++i)
    {
        cout << ans[i] << endl;
    }
}