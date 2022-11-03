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
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    string str;
    cin >> n;
    cin >> str;
    string s1, s2;
    s1 = str.substr(0, n);
    s2 = str.substr(n);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 > s2) swap(s1, s2);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] >= s2[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}