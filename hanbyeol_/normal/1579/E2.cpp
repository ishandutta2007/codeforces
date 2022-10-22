#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 262144;
int idx[2*MAXN];
void setv(int a, int v)
{
    idx[a+=MAXN] = v;
    while((a=a/2)) idx[a] = idx[2*a]+idx[2*a+1];
}
int getv(int a, int b)
{
    a += MAXN; b += MAXN;
    int ans = 0;
    while(a<=b)
    {
        if(a%2 == 1) ans += idx[a++];
        if(b%2 == 0) ans += idx[b--];
        a /= 2; b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> V(N); for(int &x: V) cin >> x;
        vector<int> U = V;
        sort(U.begin(), U.end());
        U.erase(unique(U.begin(), U.end()), U.end());
        long long ans = 0;
        for(int x: V)
        {
            x = lower_bound(U.begin(), U.end(), x) - U.begin();
            ans += min(getv(0, x-1), getv(x+1, (int)U.size()-1));
            setv(x, getv(x, x)+1);
        }
        cout << ans << endl;
        for(int i=0; i<(int)U.size(); ++i) setv(i, 0);
    }
}