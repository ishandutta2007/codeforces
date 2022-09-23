#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N];
int s[N];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                p[i] = i;
                s[i] = 1;
        }
        for(int i = 1; i <= m; i++){
                int k;
                cin >> k;
                vector < int > v(k);
                for(int j = 0; j < k; j++){
                        cin >> v[j];
                        if(j > 0){
                                int x = get(v[0]);
                                int y = get(v[j]);
                                if(x != y){
                                        p[x] = y;
                                        s[y] += s[x];
                                }
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                int x = get(i);
                cout << s[x] << " ";
        }
}