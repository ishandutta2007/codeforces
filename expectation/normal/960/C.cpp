#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

const LL mod = 1000000007;

LL x,d,val=1;
vector<LL> ans;

int main()
{
    cin >> x >> d;
    while (x)
    {
        //cout << x << endl;
        int num = 1;
        while ((1<<(num+1)) - 1 <= x) num++;
        FOR (i,0,num) ans.push_back(val);
        x -= ((1<<num)-1);
        val+=d;
    }
    cout << ans.size()<<"\n";
    FOR (i,0,ans.size()) cout << ans[i]<<" ";
}