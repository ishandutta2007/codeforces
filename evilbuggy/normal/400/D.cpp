#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = (1LL<<55);

ll d[505][505], c[505];
int a[100005], p[100005];
map<int,int> arr[100005];

int find(int v){
    return (p[v] == v)?v:(p[v] = find(p[v]));
}

void combine(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(arr[u].size() < arr[v].size())swap(u, v);
    p[v] = u;
    for(map<int,int>::iterator i = arr[v].begin(); i != arr[v].end(); i++){
        arr[u][i->first] += i->second;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, u, v, w;
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            d[i][j] = inf;
        }
    }
    int ptr = 1;
    for(int i = 1; i <= k; i++){
        cin>>w;
        c[i] = w;
        if(w == 1){
            d[i][i] = 0;
        }
        while(w--){
            a[ptr] = i;
            ptr++;
        }
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
        arr[i][a[i]]++;
    }
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        if(w == 0){
            combine(u, v);
        }
        d[a[u]][a[v]] = min(d[a[u]][a[v]], 1LL*w);
        d[a[v]][a[u]] = min(d[a[v]][a[u]], 1LL*w);
    }
    set<int> tmparr;
    for(int i = 1; i <= n; i++){
        tmparr.insert(find(i));
    }
    for(auto x : tmparr){
        for(auto y : arr[x]){
            if(c[y.first] != y.second){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    for(int x = 1; x <= k; x++){
        for(int y = 1; y <= k; y++){
            for(int z = 1; z <= k; z++){
                d[y][z] = min(d[y][z], d[y][x] + d[x][z]);
            }
        }
    }
    for(int i = 1; i <= k; i++){
        if(d[i][i] != 0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(d[i][j] < inf)cout<<d[i][j]<<" ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }
}