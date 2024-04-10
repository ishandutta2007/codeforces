#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 300300;
const int Q = 1000;

using namespace std;

int d[6][6][6][Q][3];

int n;
int m[6][6][6];
int base = 100;
long long a[N];

int get(long long x, long long mod)
{
        if(x < base) return x;
        return (x - base) % mod + base;
}

void solve()
{
        int x, y, z;
        cin >> n >> x >> y >> z;

        int S = 0, mod = m[x][y][z];
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                S ^= d[x][y][z][get(a[i], mod)][0];
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                S ^= d[x][y][z][get(a[i], mod)][0];

                long long nx = max(0ll, a[i] - x);
                nx = get(nx, mod);
                res += (S ^ d[x][y][z][nx][0]) == 0;
                nx = max(0ll, a[i] - y);
                nx = get(nx, mod);
                res += (S ^ d[x][y][z][nx][1]) == 0;
                nx = max(0ll, a[i] - z);
                nx = get(nx, mod);
                res += (S ^ d[x][y][z][nx][2]) == 0;

                S ^= d[x][y][z][get(a[i], mod)][0];
        }

        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);


        for(int x = 1; x <= 5; x++) for(int y = 1; y <= 5; y++) for(int z = 1; z <= 5; z++){
                for(int i = 1; i < Q; i++){
                        for(int j = 0; j < 3; j++){
                                set < int > s;
                                d[x][y][z][i][j] = 0;
                                int ni = max(0, i - x);
                                s.insert(d[x][y][z][ni][0]);
                                ni = max(0, i - y);
                                if(j != 1)s.insert(d[x][y][z][ni][1]);
                                ni = max(0, i - z);
                                if(j != 2)s.insert(d[x][y][z][ni][2]);

                                while(s.find(d[x][y][z][i][j]) != s.end()) d[x][y][z][i][j]++;

                        }
                }
        }
        for(int x = 1; x <= 5; x++) for(int y = 1; y <= 5; y++) for(int z = 1;z <= 5; z++){
                int mod = 1, bad = 1;
                while(bad){
                        bad = 0;
                        for(int i = 1; i < Q; i++){
                                for(int j = 0; j < 3; j++){
                                        if(d[x][y][z][i][j] != d[x][y][z][get(i, mod)][j])bad = 1;
                                }
                        }
                        if(bad) mod += 1;
                }
                m[x][y][z] = mod;
        }

        int T;
        cin >> T;
        while(T--) solve();
}