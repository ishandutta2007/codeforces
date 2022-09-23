#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N];
int M[N];
int h[N];
vector < int > v[N];

void dfs(int x)
{
        if(M[x]){
                return;
        }
        int res = 1;
        set < int > s;
        for(int y: v[x]){
                dfs(y);
                s.insert(M[y]);
        }
        while(s.find(res) != s.end()){
                res += 1;
        }
        M[x] = res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
                if(!M[i]){
                        dfs(i);
                }
                h[M[i]] ^= a[i];
        }
        int res = 0;
        for(int i = 1; i < N; i++){
                if(h[i]){
                        res = i;
                }
        }
        if(res == 0){
                cout << "LOSE" << "\n";
                return 0;
        }
        cout << "WIN" << "\n";
        int pos = -1;
        for(int i = 1; i <= n; i++){
                if(M[i] == res){
                        if((a[i] ^ h[res]) < a[i]){
                                pos = i;
                                break;
                        }
                }
        }
        assert(pos != -1);
        a[pos] ^= h[res];
        for(int y: v[pos]){
                if(M[y] < res){
                        h[M[y]] ^= a[y];
                        a[y] = h[M[y]];
                        h[M[y]] = 0;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
}