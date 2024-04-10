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
const int N = 1e5 + 10;
priority_queue<int,vector<int>, greater<int>> q1, q2, q3;
vector<int> v;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    int n1, n2, n3;
    int t1, t2, t3;
    cin >> k;
    cin >> n1 >> n2 >> n3;
    cin >> t1 >> t2 >> t3;
    v.resize(k,0);
    for (int i = 0; i < k; i++)
    {
        if (q1.size() < n1) q1.push(v[i] + t1), v[i] = v[i] + t1;
        else
        {
            int x = q1.top();
            q1.pop();
            if (x < v[i]) q1.push(v[i] + t1), v[i] += t1;
            else q1.push(x + t1), v[i] = x+t1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (q2.size() < n2) q2.push(v[i] + t2), v[i] = v[i] + t2;
        else
        {
            int x = q2.top();
            q2.pop();
            if (x < v[i]) q2.push(v[i] + t2), v[i] += t2;
            else q2.push(x + t2), v[i] = x+t2;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (q3.size() < n3) q3.push(v[i] + t3), v[i] = v[i] + t3;
        else
        {
            int x = q3.top();
            q3.pop();
            if (x < v[i]) q3.push(v[i] + t3), v[i] += t3;
            else q3.push(x + t3), v[i] = x+t3;
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) ans = max(ans, v[i]);
    cout << ans << endl;
    return 0;
}