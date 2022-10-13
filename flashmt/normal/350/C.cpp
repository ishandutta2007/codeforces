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

bool cmp(pair <int,int> u, pair <int,int> v)
{
    return abs(u.first) + abs(u.second) < abs(v.first) + abs(v.second);
}

int main()
{
    int ans = 0, n, x, y;
    pair <int,int> a[100100];
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> x >> y; 
        a[i] = make_pair(x, y);
        ans += ((x != 0) + (y != 0) + 1) * 2;
    }
    
    sort(a, a + n, cmp);
    
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            x = a[i].first; y = a[i].second;
            if (x > 0) printf("1 %d %c\n", x, (j ? 'L' : 'R'));
            if (x < 0) printf("1 %d %c\n", -x, (j ? 'R' : 'L'));
            if (y > 0) printf("1 %d %c\n", y, (j ? 'D' : 'U'));
            if (y < 0) printf("1 %d %c\n", -y, (j ? 'U' : 'D'));
            printf("%d\n", j + 2);
        }
}