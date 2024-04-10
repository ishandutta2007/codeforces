#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <queue>

#define itn int 
#define float long double 
#define LL long long 
#define pb push_back 
#define mp make_pair
#define x first
#define y second 

using namespace std; 

int main(){ 
    
    int n;
    cin >> n;
    vector<vector<int> > a(n);
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = (v[i] ^ x);
    }
    vector<bool> used(n, false);
    vector<pair<int, int> > p(n, mp(0, 0));
    queue<int> q;
    q.push(0);
    used[0] = true;
    vector<int> ans;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        if (p[x].x != v[x]){
            ans.pb(x);
            p[x].x = (p[x].x ^ 1);
        }
        swap(p[x].x, p[x].y);
        for (int i = 0; i < a[x].size(); i++){
            if (!used[a[x][i]]){
                used[a[x][i]] = true;
                q.push(a[x][i]);
                p[a[x][i]] = p[x];
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << "\n";
    }
    
    return 0; 
}