#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long
using namespace std;
const int maxn = 300100, mod = 1e9 + 7, maxa = 10000100, maxb = 23, base = 737, base2 = 3079, mod2 = 242121643;
const long long inf = 2e18 + 13;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

vector <int> in[maxn];
vector <int> out[maxn];
long long cnt[maxn][27];
bool visited[maxn];
vector <int> topol;
bool check[maxn];

void dfs(int x)
{
    visited[x] = 1;
    for(int i = 0; i < out[x].size(); i++)
    {
        int u = out[x][i];
        if(!visited[u]){dfs(u);}
    }
    topol.push_back(x);
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    string s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a == b){cout << -1 << endl; return 0;}
        out[a].push_back(b);
        in[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]){dfs(i);}
    }
    long long ans = 1;
    reverse(topol.begin(), topol.end());
    for(int i = 0; i < n; i++)
    {
        int x = topol[i];
        for(int j = 0; j < out[x].size(); j++)
        {
            int u = out[x][j];
            if(check[u]){cout << -1 << endl; return 0;}
        }
        check[x] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        int x = topol[i];
        int ind = s[x] - 'a';
        cnt[x][ind] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        int x = topol[i];
        for(int j = 0; j < in[x].size(); j++)
        {
            int u = in[x][j];
            for(int k = 0; k < 27; k++)
            {
                int ind = (int)s[x] - 'a';
                if(ind == k)
                {
                    cnt[x][k] = max(cnt[u][k] + 1, cnt[x][k]);
                }
                else
                {
                    cnt[x][k] = max(cnt[x][k], cnt[u][k]);
                }
                ans = max(ans, cnt[x][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}