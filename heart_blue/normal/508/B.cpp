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
    
    string str;
    cin >> str;
    int l = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] & 1) continue;
        if (str[l - 1] > str[i])
        {
            swap(str[i], str[l - 1]);
            cout << str << endl;
            return 0;
        }
    }
    for (int i = l - 1; i >= 0; i--)
    {
        if (str[i] & 1) continue;
        swap(str[i], str[l - 1]);
        cout << str << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}