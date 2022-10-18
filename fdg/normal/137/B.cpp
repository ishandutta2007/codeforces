#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool used[5003];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,ans=0,a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if (a<=n&&used[a]||a>n) ans++;
        used[a]=true;
    }
    cout << ans << endl;
    return 0;
}