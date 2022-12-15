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

LL n, q, x;
LL res(LL n, LL pos)
{
    //cout << n<<" "<<pos<<endl;
    if (pos%2 == 1) return (pos+1)/2;
    if (n%2 == 0) return res(n/2,pos/2)+n/2;
    else return res(n/2+1,pos/2+1)+n/2;
}

int main()
{
    cin >> n >> q;
    FOR (i,0,q)
    {
        cin >> x;
        cout << res(n,x) << "\n";
    }
}