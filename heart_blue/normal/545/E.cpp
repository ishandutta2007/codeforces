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
const int N = 3e5 + 10;
const double eps = 1e-6;
class Edge
{
public:
    int v, w,idx;
    Edge(){};
    Edge(int _v, int _w, int _idx) :v(_v), w(_w), idx(_idx){}
};
vector<Edge> v[N];
LL dis[N];
vector<pair<int,int>> ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    ans.resize(n+1);
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        v[x].push_back(Edge(y, w, i));
        v[y].push_back(Edge(x, w, i));
    }
    int u;
    scanf("%d", &u);
    queue<int> q;
    q.push(u);
    for (int i = 1; i <= n; i++) dis[i] = INF*INF;
    dis[u] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &x : v[u])
        {
            if (dis[x.v] > dis[u] + x.w)
            {
                dis[x.v] = dis[u] + x.w;
                ans[x.v] = { x.w, x.idx };
                q.push(x.v);
            }
            if (dis[x.v] == dis[u] + x.w)
            {
                if (ans[x.v].first > x.w)
                {
                    ans[x.v] = { x.w, x.idx };
                }
            }
        }
    }
    vector<int> vv;
    LL sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == u) continue;
        sum += ans[i].first;
        vv.push_back(ans[i].second);
    }
    if(!vv.empty()) sort(vv.begin(), vv.end());
    cout << sum << endl;
    for (auto &x : vv) cout << x << ' ';
    return 0;

}