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

const LL INF = 1e7 + 7;
const int N = 1e3 + 10;



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    string str;
    cin >> n;
    vector<int> ans;
    while (n--)
    {
        cin >> str;
        ans.clear();
        for (int i = 1; i <= 12; i++)
        {
            if (12 % i) continue;
            int sum = 0;
            int a = i;
            int b = 12 / i;
            for (int s = 0; s < b; s++)
            {
                int sum = 0;
                for (int t = 0; t < a; t++)
                {
                    if (str[t*b+s] == 'X') sum++;
                }
                if (sum == a)
                {
                    ans.push_back(a);
                    break;
                }
            }
        }
        cout << ans.size();
        for (int i = 0; i < ans.size(); i++) cout << ' ' << ans[i] << 'x' << 12 / ans[i];
        cout << endl;
    }
    return 0;
}