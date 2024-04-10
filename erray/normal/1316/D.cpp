#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define ln '\n'
#define MOD 1000000007
#define N 1005
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
int n, t, x, y, vis[N][N], mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
char ans[N][N];
pii mat[N][N];
string tr = "UDLR", rt = "DURL";
vector <pii> control[N][N];
bool inRange(int x, int y){return x <= n && x >= 1 && y >= 1 && y <= n;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans[i][j] = '*';
            cin >> mat[i][j].st >> mat[i][j].nd;
            if(mat[i][j].st != -1 ){
             control[mat[i][j].st][mat[i][j].nd].pb(mp(i, j));
            }

        }
    }
    vector <pii> v;
    bool isValid = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mat[i][j] == mp(i, j)){
            ans[i][j] = 'X';
                queue <pii> q;
                q.push(mp(i, j));
                while(!q.empty()){
                    x = q.front().st, y = q.front().nd;
                    q.pop();
                    //cout << x << " " << y << ln;
                    if(vis[x][y])continue;

                    vis[x][y] = 1;
                    for(int ii = 0; ii < 4 ;ii++){
                        int nx = x + mx[ii], ny = y + my[ii];
                        //cout << nx << " " << ny << " is " << mat[nx][ny].st << " " << mat[nx][ny].nd << ln;

                        if(inRange(nx, ny)){
                            if(!vis[nx][ny] && mat[nx][ny] == mat[x][y]){
                            //cout << "asd" << ln;
                                ans[nx][ny] = tr[ii];
                                q.push(mp(nx, ny) );
                                //cout << nx << " " << ny << ln;
                            }
                        }
                    }


                }
                for(auto a : control[i][j]){
                        if(!vis[a.st][a.nd]){
                            cout << "INVALID";
                            return 0;
                        }
                    }
            }
            else if(mat[i][j].st == -1)v.pb(mp(i, j));
        }
    }
    //cout << v.size() << ln;
    /*
     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j];
        }
        cout << ln;
    }
    */
    for(auto a : v){
        if(vis[a.st][a.nd])continue;
        bool fnd = 0;
       // cout << a.st << " " << a.nd << ln;
        for(int i = 0; i < 4; i++){
            int nx = a.st + mx[i], ny = a.nd + my[i];
            if(inRange(nx, ny) && !fnd){
                if(!vis[nx][ny] && mat[nx][ny].st == -1){
                 //cout << nx << " " << ny << " " << x << " " << ny << " ";
                    fnd = 1;
                    ans[nx][ny] = tr[i];
                  //  cout << tr[i] << " "  << rt[i] << ln;
                    ans[a.st][a.nd] = rt[i];

                    vis[nx][ny] = 1;
                    vis[a.st][a.nd] = 1;
                    break;
                }
            }
        }
    }
    //cout << "asd" << ln;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ans[i][j] == '*'){
            bool f = 0;
                if(mat[i][j] == mp(-1, -1)){
                    for(int a = 0; a < 4; a++){
                    int nx = i + mx[a], ny = j + my[a];
                    //cout << nx << " " << ny << ln;
                        if(inRange(nx, ny)){
                            if(mat[nx][ny].st == -1){
                            //cout << "asd" << ln;
                                ans[i][j] = rt[a];
                                f = 1;
                            }
                        }
                    }
                    if(!f){
                    cout << "INVALID";
                return 0;
                    }
                }

            else {
                cout << "INVALID";
                return 0;
            }
            }
        }
    }


    cout << "VALID" << ln;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j];
        }
        cout << ln;
    }
}