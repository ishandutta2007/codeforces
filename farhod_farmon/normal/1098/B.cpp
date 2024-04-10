#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int m;
int a[N][4][2];
int b[N][4][2];
vector < vector < int > > c;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        c.resize(n + 2);
        for(int i = 0; i <= n + 1; i++){
                c[i].resize(m + 2);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        char x;
                        cin >> x;
                        if(x == 'A'){
                                c[i][j] = 0;
                        }
                        else if(x == 'C'){
                                c[i][j] = 1;
                        }
                        else if(x == 'G'){
                                c[i][j] = 2;
                        }
                        else{
                                c[i][j] = 3;
                        }
                        a[i][c[i][j]][j % 2] += 1;
                        b[j][c[i][j]][i % 2] += 1;
                }
        }
        int res = 1e9, rev;
        pair < int, int > ax, ay;
        for(int ii = 0; ii < 4; ii++){
                for(int jj = ii + 1; jj < 4; jj++){
                        pair < int, int > x = {ii, jj};
                        vector < int > gg;
                        pair < int, int > y;
                        for(int i = 0; i < 4; i++){
                                if(i != ii && i != jj){
                                        gg.push_back(i);
                                }
                        }
                        y = {gg[0], gg[1]};
                        int cnt = 0;
                        for(int i = 1; i <= n; i++){
                                if(i % 2){
                                        int c1 = m - a[i][x.fi][0] - a[i][x.se][1];
                                        int c2 = m - a[i][x.se][0] - a[i][x.fi][1];
                                        cnt += min(c1, c2);
                                }
                                else{
                                        int c1 = m - a[i][y.fi][0] - a[i][y.se][1];
                                        int c2 = m - a[i][y.se][0] - a[i][y.fi][1];
                                        cnt += min(c1, c2);
                                }
                        }
                        if(cnt < res){
                                res = cnt;
                                ax = x;
                                ay = y;
                                rev = 0;
                        }
                        cnt = 0;
                        for(int i = 1; i <= m; i++){
                                if(i % 2){
                                        int c1 = n - b[i][x.fi][0] - b[i][x.se][1];
                                        int c2 = n - b[i][x.se][0] - b[i][x.fi][1];
                                        cnt += min(c1, c2);
                                }
                                else{
                                        int c1 = n - b[i][y.fi][0] - b[i][y.se][1];
                                        int c2 = n - b[i][y.se][0] - b[i][y.fi][1];
                                        cnt += min(c1, c2);
                                }
                        }
                        if(cnt < res){
                                res = cnt;
                                ax = x;
                                ay = y;
                                rev = 1;
                        }
                }
        }
        if(rev == 0){
                auto x = ax;
                auto y = ay;
                for(int i = 1; i <= n; i++){
                        if(i % 2){
                                int c1 = m - a[i][x.fi][0] - a[i][x.se][1];
                                int c2 = m - a[i][x.se][0] - a[i][x.fi][1];
                                if(c1 < c2){
                                        for(int j = 1; j <= m; j++){
                                                if(j % 2){
                                                        c[i][j] = x.se;
                                                }
                                                else{
                                                        c[i][j] = x.fi;
                                                }
                                        }
                                }
                                else{
                                        for(int j = 1; j <= m; j++){
                                                if(j % 2){
                                                        c[i][j] = x.fi;
                                                }
                                                else{
                                                        c[i][j] = x.se;
                                                }
                                        }
                                }
                        }
                        else{
                                int c1 = m - a[i][y.fi][0] - a[i][y.se][1];
                                int c2 = m - a[i][y.se][0] - a[i][y.fi][1];
                                if(c1 < c2){
                                        for(int j = 1; j <= m; j++){
                                                if(j % 2){
                                                        c[i][j] = y.se;
                                                }
                                                else{
                                                        c[i][j] = y.fi;
                                                }
                                        }
                                }
                                else{
                                        for(int j = 1; j <= m; j++){
                                                if(j % 2){
                                                        c[i][j] = y.fi;
                                                }
                                                else{
                                                        c[i][j] = y.se;
                                                }
                                        }
                                }
                        }
                }
        }
        else{
                auto x = ax;
                auto y = ay;
                for(int i = 1; i <= m; i++){
                        if(i % 2){
                                int c1 = n - b[i][x.fi][0] - b[i][x.se][1];
                                int c2 = n - b[i][x.se][0] - b[i][x.fi][1];
                                if(c1 < c2){
                                        for(int j = 1; j <= n; j++){
                                                if(j % 2){
                                                        c[j][i] = x.se;
                                                }
                                                else{
                                                        c[j][i] = x.fi;
                                                }
                                        }
                                }
                                else{
                                        for(int j = 1; j <= n; j++){
                                                if(j % 2){
                                                        c[j][i] = x.fi;
                                                }
                                                else{
                                                        c[j][i] = x.se;
                                                }
                                        }
                                }
                        }
                        else{
                                int c1 = n - b[i][y.fi][0] - b[i][y.se][1];
                                int c2 = n - b[i][y.se][0] - b[i][y.fi][1];
                                if(c1 < c2){
                                        for(int j = 1; j <= n; j++){
                                                if(j % 2){
                                                        c[j][i] = y.se;
                                                }
                                                else{
                                                        c[j][i] = y.fi;
                                                }
                                        }
                                }
                                else{
                                        for(int j = 1; j <= n; j++){
                                                if(j % 2){
                                                        c[j][i] = y.fi;
                                                }
                                                else{
                                                        c[j][i] = y.se;
                                                }
                                        }
                                }
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] == 0){
                                cout << 'A';
                        }
                        else if(c[i][j] == 1){
                                cout << 'C';
                        }
                        else if(c[i][j] == 2){
                                cout << 'G';
                        }
                        else{
                                cout << 'T';
                        }
                }
                cout << "\n";
        }
}