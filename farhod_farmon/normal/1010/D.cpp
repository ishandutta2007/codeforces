#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int tp[N];
int a[N];
int b[N];
int d[N];
int ans[N];

void ff(int x)
{
        if(a[x]){
                ff(a[x]);
        }
        if(b[x]){
                ff(b[x]);
        }
        if(tp[x] == 1){
                d[x] = d[a[x]] & d[b[x]];
        }
        if(tp[x] == 2){
                d[x] = d[a[x]] | d[b[x]];
        }
        if(tp[x] == 3){
                d[x] = d[a[x]] ^ d[b[x]];
        }
        if(tp[x] == 4){
                d[x] = !d[a[x]];
        }
}

void go(int x)
{
        if(tp[x] == 5){
                ans[x] = d[1];
                return;
        }
        if(a[x]){
                go(a[x]);
        }
        if(b[x]){
                go(b[x]);
        }
}

int C;

void dfs(int x)
{
        if(tp[x] == 5){
                ans[x] = (d[x] ^ 1) ^ (C % 2);
                return;
        }
        if(tp[x] == 1){
                if(d[a[x]] == 0){
                        go(b[x]);
                }
                else{
                        dfs(b[x]);
                }
                if(d[b[x]] == 0){
                        go(a[x]);
                }
                else{
                        dfs(a[x]);
                }
        }
        else if(tp[x] == 2){
                if(d[a[x]] == 1){
                        go(b[x]);
                }
                else{
                        dfs(b[x]);
                }
                if(d[b[x]] == 1){
                        go(a[x]);
                }
                else{
                        dfs(a[x]);
                }
        }
        else if(tp[x] == 3){
                C += d[a[x]];
                dfs(b[x]);
                C -= d[a[x]];
                C += d[b[x]];
                dfs(a[x]);
                C -= d[b[x]];
        }
        else{
                C++;
                dfs(a[x]);
                C--;
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                if(s == "AND"){
                        tp[i] = 1;
                        cin >> a[i] >> b[i];
                }
                else if(s == "OR"){
                        tp[i] = 2;
                        cin >> a[i] >> b[i];
                }
                else if(s == "XOR"){
                        tp[i] = 3;
                        cin >> a[i] >> b[i];
                }
                else if(s == "NOT"){
                        tp[i] = 4;
                        cin >> a[i];
                }
                else if(s == "IN"){
                        tp[i] = 5;
                        cin >> d[i];
                }
        }
        ff(1);
        dfs(1);
        for(int i = 1; i <= n; i++){
                if(tp[i] == 5){
                        cout << ans[i];
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}