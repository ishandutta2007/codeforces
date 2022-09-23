#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,sse4.1,sse4.2,sse4a,xsave")

#define fi first
#define se second

const int N = 5050;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int k;
vector < int > res;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> k;
        int inf = 1e6;
        k += 1;
        res = {-1};
        while(k > 0){
                k += 1;
                int g = min(k, inf);
                res.push_back(g);
                k -= g;
        }
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}