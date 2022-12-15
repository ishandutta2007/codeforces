//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <string.h>
#include<fstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000001
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define eps 1e-5
#define X first
#define Y second

int n;
int a[444];

int main()
{
    cin >> n;
    FOR (i,0,2*n)
    {
        cin >> a[i];
    }
    int ans = 0;
    FOR (i,0,2*n)
    {
        int pos = 2*i;
        FOR (j,pos+1,2*n)
        {
            if (a[j] == a[pos])
            {
                ans += j-pos-1;
                for(int POS = j; POS > pos+1; POS--)
                    swap(a[POS],a[POS-1]);
                break;
            }
        }
    }
    cout << ans;
}