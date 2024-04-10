#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s1, s2, virus;
int n1, n2, m;
int nxt[105][26];

void build(){
    vector<int> f(m);
    f[0] = 0;
    int i = 1, j = 0;
    while(i < m){
        if(virus[i] == virus[j]){
            f[i] = j+1;
            i++; j++;
        }else if(j == 0){
            f[i] = 0;
            i++;
        }else{
            j = f[j-1];
        }
    }
    memset(nxt, -1, sizeof(nxt));
    for(i = 0; i < m; i++){
        nxt[i][virus[i] - 'A'] = i+1;
    }
    for(i = 0; i < 26; i++){
        if(nxt[0][i] == -1)nxt[0][i] = 0;
    }
    for(i = 1; i <= m; i++){
        for(j = 0; j < 26; j++){
            if(nxt[i][j] != -1)continue;
            nxt[i][j] = nxt[f[i-1]][j];
        }
    }
}

struct Node{
    int i, j, k, len;
    Node(int ii = 0, int ij = 0, int ik = 0, int il = 0){
        i = ii;
        j = ij;
        k = ik;
        len = il;
    }
};

Node nxtn[105][105][105];
Node head[105][105][105];
bool vis[105][105][105];

Node dfs(int i, int j, int k){
    if(k == m)return Node(-1, -1, -1, -1);
    if(i == n1 || j == n2)return Node(-1, -1, -1, 0);
    if(vis[i][j][k])return head[i][j][k];
    vis[i][j][k] = true;
    if(s1[i] == s2[j]){
        int ch = s1[i] - 'A';
        Node t1 = dfs(i + 1, j + 1, k);
        Node t2 = dfs(i + 1, j + 1, nxt[k][ch]);
        if(t2.len != -1){
            if(t1.len >= t2.len + 1){
                head[i][j][k] = t1;
            }else{
                head[i][j][k] = Node(i, j, k, t2.len + 1);
                nxtn[i][j][k] = t2;
            }
        }else{
            head[i][j][k] = t1;
            return t1;
        }
    }else{
        Node t1 = dfs(i + 1, j, k);
        Node t2 = dfs(i, j + 1, k);
        if(t1.len >= t2.len){
            head[i][j][k] = t1;
        }else{
            head[i][j][k] = t2;
        }
    }
    return head[i][j][k];
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

    
    cin>>s1>>s2>>virus;
    n1 = s1.size();
    n2 = s2.size();
    m = virus.size();
    build();
    memset(vis, false, sizeof(vis));
    Node v = dfs(0,0,0);
    if(v.len <= 0){
        cout<<0<<endl;
        return 0;
    }
    v = head[v.i][v.j][v.k];
    while(v.i != -1 && v.j != -1 && v.k != -1){
        cout<<s1[v.i];
        v = nxtn[v.i][v.j][v.k];
    }
}