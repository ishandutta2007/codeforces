#include <bits/stdc++.h>

#define rep(a, s, b)   for(int a = (s); a < (b); ++a)
#define trav(a,b)   for(auto& a : (b))
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define tests int _testsvariableXXX; cin >> _testsvariableXXX; while (_testsvariableXXX--)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    int n, m; cin >> n >> m;
    vector games(n, 0), bills(m,0);
    trav(gi, games) cin >> gi;
    trav(bi, bills) cin >> bi;
    reverse(all(games));
    reverse(all(bills));
    int i = 0;
    while (games.size() && bills.size()) {
        if (games.back() <= bills.back()) {
            bills.pop_back();
            i += 1;
        }
        games.pop_back();
    }
    cout << i << endl;


    cout.flush();
    return 0;
}