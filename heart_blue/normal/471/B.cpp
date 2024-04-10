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
const int N = 2001;
vector<int> v[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int x;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        v[x].push_back(i);
    }
    int cnt2(0),cnt3(0);
    for(int i = 1; i < N; i++)
    {
        if(v[i].size() == 2) cnt2++;
        if(v[i].size() > 2) cnt3++;
    }
    if(cnt3 == 0 && cnt2 < 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    int t = 3;
    cout << "YES" << endl;
    while(t--)
    {
        int flag = 0;
        for(int i = 1; i < N; i++)
        {
            for(auto &x : v[i]) cout << x << ' ';
            if(!v[i].empty() && !flag) flag = next_permutation(v[i].begin(), v[i].end());
        }
        cout << endl;
    }
    return 0;

}