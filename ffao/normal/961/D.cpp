    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr(i,j,k) for(int i=j;i<k;i++)
    #define f(n) fr(i,0,n)
    #define f1(n) fr(i,1,n+1)
    #define pb push_back
    #define F first
    #define S second
    #define all(x) x.begin(), x.end()
    const int mod = 1e9 + 7;
    const int maxn = 100005;
    ll xx[maxn], yy[maxn];
    int n;
    bool isline(int x,int y, int z) {
        return (xx[x] - xx[y]) * (yy[z] - yy[y]) == (yy[x] - yy[y]) * (xx[z] - xx[y]);
    }
    bool check(int x, int y) {
        vector<int>rem;
        f1(n) {
            if (i == x || i == y) {
                continue;
            }
            if (isline(i,x,y)) {
                continue;
            }
            rem.pb(i);
        }
        if (rem.size() <= 2) {
            return 1;
        }
        for(int i = 2 ; i < rem.size() ; i++) {
            if (!isline(rem[0], rem[1],rem[i])) {
                return 0;
            }
        }
        return 1;
    }
    void go() {
        cin >> n;
        f1(n) {
            cin >> xx[i] >> yy[i];
        } 
        if (n <= 4) {
            cout << "YES\n";
            return;
        }
        else if (check(1,2) || check(2,3) || check(1,3)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int c = 0;
        int t;
        if (!c) {
            t = 1;
        }
        else {
            cin >> t;
        }
        while (t--) {
            go();
        }
        
    }