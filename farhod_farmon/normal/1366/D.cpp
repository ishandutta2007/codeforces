#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 10000001;

using namespace std;

int ls[Q];
vector < int > v;

int A, B, X;

int n;
int a[N], b[N];

void solve(int i, int x, vector < pair < int, int > > &g)
{
        if(i == g.size()){
                if(A != -1) return;
                if(x != 1 && x != X && __gcd(x + X / x, X) == 1){
                        A = x;
                        B = X / x;
                }
                return;
        }
        for(int j = 0; j <= g[i].se; j++){
                solve(i + 1, x, g);
                x *= g[i].fi;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        for(int i = 2; i < Q; i++){
                if(ls[i] == 0){
                        ls[i] = i;
                        v.push_back(i);
                }
                for(int j = 0; j < (int)v.size() && v[j] <= ls[i] && i * v[j] < Q; j++){
                        ls[i * v[j]] = v[j];
                }
        }

        scanf("%d", &n);
        vector < pair < int, int > > g;
        for(int i = 1; i <= n; i++){
                int x;
                scanf("%d", &x);
                g.clear();
                int y = x;
                while(y > 1){
                        g.push_back({ls[y], 0});
                        while(y % g.back().fi == 0){
                                y /= g.back().fi;
                                g.back().se += 1;
                        }
                }
                X = x;
                A = B = -1;
                solve(0, 1, g);
                a[i] = A;
                b[i] = B;
        }
        for(int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
        for(int i = 1; i <= n; i++) printf("%d ", b[i]);
}