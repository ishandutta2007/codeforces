#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

using namespace std;

int n, m;
int a[N];
int A[N], B[N];
bool dead[N];
vector < int > v[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> A[i] >> B[i];

                for(int x: {A[i], B[i]}){
                        a[x] -= 1;
                        v[x].push_back(i);
                }
        }
        vector < int > G;
        for(int i = 1; i <= n; i++){
                if(a[i] >= 0){
                        G.push_back(i);
                }
        }
        vector < int > res;
        for(int i = 0; i < G.size(); i++){
                for(int x: v[G[i]]){
                        if(dead[x]){
                                continue;
                        }
                        dead[x] = true;
                        res.push_back(x);
                        for(int y: {A[x], B[x]}){
                                a[y] += 1;
                                if(a[y] == 0){
                                        G.push_back(y);
                                }
                        }
                }
        }
        if(res.size() != m){
                cout << "DEAD" << "\n";
                return 0;
        }
        reverse(res.begin(), res.end());
        cout << "ALIVE" << "\n";
        for(int x: res){
                cout << x << " ";
        }
}