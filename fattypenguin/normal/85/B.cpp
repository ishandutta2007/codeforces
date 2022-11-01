#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

int arr[200001 + 4099];

struct Myt
{
    LL t;
    int x;
    bool operator < (const Myt &p) const
    {
        if (t != p.t) return t > p.t;
        return arr[x] > arr[p.x];
    }
} que[200007],inp[200007],que1[200007];

void process(int n,int k,int x)
{
    int use = 0;
    LL now = 0;
    int rear1 = 0,head = 0,rear = 0;
    que[n].t = 0x7f7f7f7f;
    ++n;
    for (int i = 0;i < n;++i)
    {
        if (now > que[i].t)
            que[i].t = now;
        now = que[i].t;
        while (head < rear && inp[head].t+x <= now)
        {
            que1[rear1] = inp[head];
            que1[rear1++].t += x;
            --use;
            ++head;
        }
        if (use >= k)
        {
            que1[rear1] = inp[head];
            que1[rear1++].t += x;
            now = que[i].t = inp[head].t + x;
            --use;
            ++head;
        }
        inp[rear++] = que[i];
        ++use;
    }
}

int main()
{
    int k1,k2,k3,t1,t2,t3;
    cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3;
    int n;
    cin >> n;
    for (int i = 0;i < n;++i)
    {
        cin >> arr[i];
        que[i].t = arr[i];
        que[i].x = i;
    }
    process(n,k1,t1);
    memcpy(que,que1,sizeof(que1));
    process(n,k2,t2);
    memcpy(que,que1,sizeof(que1));
    process(n,k3,t3);
    LL ans = 0;
    for (int i = 0;i < n;++i)
        ans = max(ans,que1[i].t - arr[que1[i].x]);
    cout << ans << endl;

}