#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int n;
int s[N];
vector < int > v[N];

void dfs(int x)
{
        if(v[x].size() == 0){
                s[x] = 1;
        }
        for(int y: v[x]){
                dfs(y);
                s[x] += s[y];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        dfs(1);
        vector < int > ans;
        for(int i = 1; i <= n; i++){
                ans.push_back(s[i]);
        }
        sort(ans.begin(), ans.end());
        for(int x: ans){
                cout << x << " ";
        }
}