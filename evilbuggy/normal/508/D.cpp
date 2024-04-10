#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> hsh;
string rhsh[400005];
int ptr, id[400005], od[400005], vis[400005];
vector<int> g[400005];
deque<int> st;

void dfs(int v){
    while(!g[v].empty()){
        int u = g[v].back();
        g[v].pop_back();
        dfs(u);
    }
    vis[v] = 1;
    st.push_front(v);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n; string s;
    cin>>n; ptr = 0;
    memset(id, 0, sizeof(id));
    memset(od, 0, sizeof(od));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        cin>>s;
        int u, v;
        if(hsh.find(s.substr(0, 2)) == hsh.end()){
            hsh[s.substr(0, 2)] = ++ptr;
            rhsh[ptr] = s.substr(0, 2);
        }
        if(hsh.find(s.substr(1, 2)) == hsh.end()){
            hsh[s.substr(1, 2)] = ++ptr;
            rhsh[ptr] = s.substr(1, 2);
        }
        u = hsh[s.substr(0, 2)];
        v = hsh[s.substr(1, 2)];
        g[u].push_back(v);
        od[u]++;
        id[v]++;
    }
    vector<int> arr;
    for(int i = 1; i <= ptr; i++){
        if(id[i] != od[i])arr.push_back(i);
    }
    int v1 = -1, v2 = -1;
    if(arr.size() != 0){
        if(arr.size() != 2){
            cout<<"NO"<<endl;
            return 0;
        }
        v1 = arr[0];
        v2 = arr[1];
        if(id[v1] + id[v2] != od[v1] + od[v2] || abs(id[v1] - od[v1]) > 1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(v1 != -1){
        if(od[v1] > id[v1])swap(v1, v2);
        g[v1].push_back(v2);
        od[v1]++;
        id[v1]++;
    }
    // cout<<v1<<" "<<rhsh[v1]<<" "<<v2<<" "<<rhsh[v2]<<endl;
    dfs(1);
    for(int i = 1; i <= ptr; i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i = 1; i < st.size(); i++){
        if(st[i-1] == v1 && st[i] == v2){
            deque<int> nst;
            for(int j = i; j < st.size(); j++){
                nst.push_back(st[j]);
            }
            for(int j = 1; j < i; j++){
                nst.push_back(st[j]);
            }
            st = nst;
            break;
        }
    }
    cout<<"YES"<<endl;
    cout<<rhsh[st[0]][0];
    for(int i = 0; i < st.size(); i++){
        cout<<rhsh[st[i]][1];
    }
}