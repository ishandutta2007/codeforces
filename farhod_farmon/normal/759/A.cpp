#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 200200;
const long long mod = 1e15 + 3;

using namespace std;

int n;
int s;
bool used[N];
vector < int > v[N];

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    for(int y: v[x])
        dfs(y);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v[i].pb(x);
        v[x].pb(i);
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s += x;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1)
        cnt = 0;
    cout << cnt + 1 - s % 2 << endl;
}