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
const LL INF = 1000000007;
const int N = 3e5;
int a[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == i)
        {
            sum++;
            continue;
        }
        if(i == a[a[i]]) flag = 1;
    }
    if(flag) sum += 2;
    else sum++;
    if(sum > n) sum = n;
    cout << sum << endl;
    return 0;

}