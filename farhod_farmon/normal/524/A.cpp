#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 210;

using namespace std;

int m, k;
int a[N];
int b[N];
bool f[N][N];
vector < int > order;
map < int, int > id;
map < int, bool > used;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        if(!used[a[i]]){
            used[a[i]] = true;
            order.pb(a[i]);
        }
        if(!used[b[i]]){
            used[b[i]] = true;
            order.pb(b[i]);
        }
    }
    sort(order.begin(), order.end());
    int n = 0;
    for(int i = 0; i < order.size(); i++){
        int x = order[i];
        id[x] = ++n;
    }
    for(int i = 1; i <= m; i++)
        f[id[a[i]]][id[b[i]]] = f[id[b[i]]][id[a[i]]] = true;
    for(int i = 0; i < order.size(); i++){
        int x = order[i],
            id_x = id[order[i]];
        vector < int > v;
        for(int j = 1; j <= n; j++){
            if(f[id_x][j] || j == id_x)
                continue;
            int cnt1 = 0,
                cnt2 = 0;
            for(int h = 1; h <= n; h++){
                if(h == id_x || h == j)
                    continue;
                if(f[id_x][h] && f[j][h])
                    cnt1++;
                if(f[id_x][h])
                    cnt2++;
            }
            if(cnt2 * k <= cnt1 * 100)
                v.pb(order[j - 1]);
        }
        cout << x << ": " << v.size() << " ";
        for(int j = 0; j < v.size(); j++)
            cout << v[j] << " ";
        cout << endl;
    }
}