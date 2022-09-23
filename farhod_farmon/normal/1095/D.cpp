#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int b[N];
bool used[N];
vector < int > v[N];
vector < int > ord;

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = true;
        ord.push_back(x);
        for(int y: v[x]){
                dfs(y);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                a[i] = x;
                b[i] = y;
                v[y].push_back(x);
                v[x].push_back(y);
        }
        dfs(1);
        bool good = true;
        for(int i = 0; i < n; i++){
                int j = ord[(i + 1) % n], h = ord[(i + 2) % n];
                int x = ord[i];
                if(!(a[x] == j && b[x] == h) && !(a[x] == h && b[x] == j)){
                        good = false;
                }
        }
        if(!good){
                reverse(ord.begin(), ord.end());
        }
        for(int x: ord){
                cout << x << " ";
        }
}