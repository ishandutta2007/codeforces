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

int main()
{
    //freopen("input.txt", "r", stdin);
    int sum1;
    int sum2;
    sum1 = sum2 = 0;
    int n = 3;
    while(n--)
    {
        int x;
        cin >> x;
        sum1 += x;
    }
    n = 3;
    while(n--)
    {
        int x;
        cin >> x;
        sum2 += x;
    }
    int sum = 0;
    sum = sum1/5;
    if(sum1%5) sum++;
    sum += sum2/10;
    if(sum2%10) sum++;
    cin >> n;
    if(sum <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}