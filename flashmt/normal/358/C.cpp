#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const string PUSH[] = {"pushStack", "pushQueue", "pushFront", "pushBack"};
const string POP[] = {"popStack", "popQueue", "popFront"};

int main()
{
    int n, x, type[100100];
    vector <int> ans[100100];
    priority_queue < pair<int,int> > q;
    
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x;
        if (!x)
        {
            type[i] = -1;
            for (int j = 0; j < 3 && !q.empty(); j++)
            {
                pair <int,int> u = q.top();
                q.pop();
                ans[i].push_back(j);
                type[u.second] = j;
            }               
            while (!q.empty()) q.pop();
        }
        else q.push(make_pair(x, i)), type[i] = 3;
    }
        
    for (int i = 1; i <= n; i++)
        if (type[i] < 0)
        {
            cout << ans[i].size();
            for (int j = 0; j < int(ans[i].size()); j++)
                cout << ' ' << POP[ans[i][j]];
            puts("");
        }
        else cout << PUSH[type[i]] << endl;
}