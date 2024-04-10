#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

void solve(vector < int > &v, int n)
{
        for(int x: v){
                for(int y: v){
                        if(x == y) continue;
                        for(int z: v){
                                if(z == x || z == y) continue;
                                int rem = n - x - y - z;
                                if(rem != x && rem != y && rem != z && rem > 0){
                                        cout << "YES\n" << x << ' ' << y << " " << z << " " << rem << '\n';
                                        return;
                                }
                        }
                }
        }
        cout << "NO" << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        vector < int > v;
        for(int i = 2; i < 80; i++){
                int cnt = 0, x = i;
                for(int j = 2; j <= x; j++){
                        if(x % j == 0){
                                cnt += 1;
                                x /= j;
                                if(x % j == 0){
                                        cnt += 2;
                                        break;
                                }
                        }
                }
                if(cnt == 2){
                        v.push_back(i);
                }
        }

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                solve(v, n);
        }
}