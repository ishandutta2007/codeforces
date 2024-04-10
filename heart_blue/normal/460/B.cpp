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
const int N = 1e9;
const int M = N;


int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    vector<LL> ans;
    for (int i = 1; i < 82; i++)
    {
        LL x = 1;
        int t = a;
        while (t--) x *= i;
        x = x*b + c;
        int sum = 0;
        ans.push_back(x);
        while (x) sum += x % 10, x /= 10;
        if (sum != i) ans.pop_back();
    }
    if (!ans.empty()) sort(ans.begin(), ans.end());
    while (!ans.empty())
    {
        if (ans.back() >= N) ans.pop_back();
        else break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;

}