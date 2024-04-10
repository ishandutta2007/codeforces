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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

int main()
{
    char s[10];
    cin >> s;
    sort(s,s+6);
    int kind = 1;
    for (int i = 1;i < 6;++i)
        if (s[i] != s[i-1])
            ++kind;
    if (kind == 1)
    {
        cout << 1 << endl;
    }
    else if (kind == 6)
    {
        cout << 30 << endl;
    }
    else if (kind == 5)
    {
        cout << 15 << endl;
    } else if (kind == 4)
    {
        int ex3 = 1;
        for (int i = 1;i < 6 && ex3 != 3;++i)
            if (s[i] == s[i-1])
            {
                ++ex3;
            } else ex3 = 1;
        if (3 == ex3)
            cout << 5 << endl;
        else cout << 8 << endl;
    } else if (kind == 2)
    {
        int count = 1;
        for (int i = 1;s[i] == s[i-1];++i)
            ++count;
        if (count == 5 || count == 1)
            cout << 1 << endl;
        else if (count == 4 || count == 2)
            cout << 2 << endl;
        else if (count == 3)
            cout << 2 << endl;
    } else if (kind == 3)
    {
        int a[3] = {0,0,0};
        int now = 0;
        a[0] = 1;
        for (int i = 1;i < 6;++i)
        {
            if (s[i] != s[i-1])
                ++now;
            a[now]++;
        }
        sort(a,a+3);
        if (a[0] == 1 && a[1] == 1)
            cout <<  2 << endl;
        else if (a[0] == 1 && a[1] == 2)
            cout << 3 << endl;
        else
            cout << 6 << endl;
    }
    return 0;
}