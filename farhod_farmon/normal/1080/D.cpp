#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //freopen("nodes.in","r",stdin);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long n, k;
                cin >> n >> k;
                vector < pair < long long, long long > > v;
                long long l = 1, side = n;
                while(side > 0 && k >= l){
                        k -= l;
                        side--;
                        l = l * 2 + 1;
                        v.push_back({side, l - 2});
                }
                for(auto p: v){
                        while(k > 0 && p.fi > 0){
                                long long g = min(k, p.se);
                                k -= g;
                                p.fi--;
                                p.se *= 4;
                        }
                }
                if(!k){
                        cout << "YES" << " " << side << "\n";
                }
                else{
                        cout << "NO" << "\n";
                }
        }
}