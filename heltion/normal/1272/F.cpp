#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 216;
char s[maxn], t[maxn];
int d[maxn][maxn][maxn << 1];
char tran[maxn][maxn][maxn << 1];
struct Triple{
    int i, j, k;
}from[maxn][maxn][maxn << 1];
int main(){
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    queue<Triple> Triples;
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= m; j += 1)
            for(int k = 0; k <= 400; k += 1)
                d[i][j][k] = 666666;
    d[0][0][0] = 0;
    Triples.push({0, 0, 0});
    while(not Triples.empty()){
        int ui = Triples.front().i, uj = Triples.front().j, uk = Triples.front().k;
        Triples.pop();
        if(uk <= 400){
            int vi = ui, vj = uj, vk = uk + 1;
            if(ui < n and s[ui] == '(') vi += 1;
            if(uj < m and t[uj] == '(') vj += 1;
            if(d[vi][vj][vk] > d[ui][uj][uk] + 1){
                d[vi][vj][vk] = d[ui][uj][uk] + 1;
                from[vi][vj][vk] = {ui, uj, uk};
                tran[vi][vj][vk] = '(';
                Triples.push({vi, vj, vk});
            }
        }
        if(uk){
            int vi = ui, vj = uj, vk = uk - 1;
            if(ui < n and s[ui] == ')') vi += 1;
            if(uj < m and t[uj] == ')') vj += 1;
            if(d[vi][vj][vk] > d[ui][uj][uk] + 1){
                d[vi][vj][vk] = d[ui][uj][uk] + 1;
                from[vi][vj][vk] = {ui, uj, uk};
                tran[vi][vj][vk] = ')';
                Triples.push({vi, vj, vk});
            }
        }
    }
    int pi = n, pj = m, pk = 0;
    string ans;
    while(pi != 0 or pj != 0 or pk != 0){
        ans += tran[pi][pj][pk];
        Triple triple = from[pi][pj][pk];
        pi = triple.i;
        pj = triple.j;
        pk = triple.k;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}