#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 505;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
int d[N];
int p[N];

int get(vector < int > v)
{
        cout << "?";
        for(int x: v){
                cout << " " << x;
        }
        cout << endl;
        int x;
        cin >> x;
        return x;
}

int main()
{
        #ifdef zxc
                //freopen("input.txt", "r", stdin);
                //freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                d[i] = -1;
        }
        queue < int > q;
        q.push(0);
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int i = 0; i <= x; i++){
                        int y = k - i;
                        if(y < 0 || y > n - x){
                                continue;
                        } else if(d[x - i + y] == -1){
                                d[x - i + y] = d[x] + 1;
                                p[x - i + y] = i;
                                q.push(x - i + y);
                        }
                }
        }
        if(d[n] == -1){
                cout << -1 << endl;
                return 0;
        }
        vector < int > A, B;
        for(int i = 1; i <= n; i++){
                B.push_back(i);
        }
        vector < vector < int > > v;
        int cur = n;
        while(cur > 0){
                int x = p[cur];
                int y = k - x;
                v.push_back({});
                vector < int > va, vb;
                for(int i = 0; i < y; i++){
                        va.push_back(B.back());
                        B.pop_back();
                }
                for(int i = 0; i < x; i++){
                        vb.push_back(A.back());
                        A.pop_back();
                }
                for(int z: va){
                        A.push_back(z);
                        v.back().push_back(z);
                }
                for(int z: vb){
                        B.push_back(z);
                        v.back().push_back(z);
                }
                cur += x - y;
        }
        reverse(v.begin(), v.end());
        int res = 0;
        for(auto g: v){
                res ^= get(g);
        }
        cout << "! " << res << endl;
}