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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    vector<int> v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int cnt = 0;
        do
        {
            if (i%v[0] % v[1] % v[2] % v[3] == i) cnt++;
        } while (next_permutation(v.begin(), v.end()));
        if (cnt >= 7) ans++;
    }
    cout << ans << endl;
    return 0;
}