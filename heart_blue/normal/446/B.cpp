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
const int N = 1e3 + 10;
priority_queue<LL> q1, q2;
LL a[N], b[N];
const int M = 1e6 + 10;
LL A[M], B[M];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    MEM(a, 0);
    MEM(b, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i] += x;
            b[j] += x;
        }
    }
    for (int i = 0; i < n; i++) q1.push(a[i]);
    for (int j = 0; j < m; j++) q2.push(b[j]);
    A[0] = B[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        int x = q1.top(); q1.pop();
        A[i] = A[i - 1] + x;
        q1.push(x - m*p);
        x = q2.top(); q2.pop();
        B[i] = B[i - 1] + x;
        q2.push(x - n*p);
    }
    LL ans = -(1LL << 60);
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, A[i] + B[k - i] - (LL)i*(k-i)*p);
    }
    cout << ans << endl;
    
    return 0;
}