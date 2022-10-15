#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const int INF = 1000000000;

int n;
    
int query(int i)
{
    if (i < 1 || i > n)
        return INF;
    cout << "? " << i << endl;
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

int main() 
{
    cin >> n;
    
    int a = 1, b = n+1;
    while (b-a > 1)
    {
        int c = (a+b)/2;
        if (query(c-1) < query(c))
            b = c;
        else
            a = c;
    }   
    cout << "! " << a << endl;
    
    return 0;
}