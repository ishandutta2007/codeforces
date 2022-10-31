#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
using namespace std;

queue<int> q;
stack<int> t;
set<int> v;

int main(void)
{
    int n, k, x;

    scanf("%d %d", &n, &k);
    while(n --)
    {
        scanf("%d", &x);
        if(v.count(x))
            continue;
        v.insert(x);

        if((signed)q.size() >= k)
        {
            v.erase(q.front());
            q.pop();
        }
        q.push(x);
    }

    printf("%d\n", (int)q.size());
    for(; !q.empty(); q.pop())
        t.push(q.front());
    for(; !t.empty(); t.pop())
        printf("%d ", t.top());
    printf("\n");

    return 0;
}