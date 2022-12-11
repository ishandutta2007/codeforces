#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct st{
    int a, b, c, d;
    st() {}
    st(int a1, int b1, int c1, int d1) {a = a1, b = b1; c = c1; d = d1;}
};

int n, m, x = -1, y = -1;
deque<char> a[303][303], b[303][303];
vector<st> ans;

void go(int x1, int y1, int x2, int y2){
    ans.pb({x1, y1, x2, y2});
    a[x2][y2].push_front(a[x1][y1].back());
    a[x1][y1].pop_back();
}

void make(deque<char> &s){
    for (char c : s){
        if (c == '1'){
            for (int s = 0; s < n; s++) if (s != x){
                if (a[s][y].size()){
                    go(s, y, x, y);
                    break;
                }
            }
        } else {
            for (int s = 0; s < m; s++) if (s != y){
                if (a[x][s].size()){
                    go(x, s, x, y);
                    break;
                }
            }
        }
    }
}

int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        string s;
        cin >> s;
        for (char c : s) a[i][j].pb(c);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        string s;
        cin >> s;
        for (char c : s) b[i][j].pb(c);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        int sum1 = 0, sum2 = 0;
        for (int s = 0; s < n; s++){
            sum1 += a[s][j].size();
            sum2 += b[s][j].size();
        }
        for (int s = 0; s < m; s++){
            sum1 += a[i][s].size();
            sum2 += b[i][s].size();
        }
        if (sum1 <= sum2){
            x = i;
            y = j;
        }
    }
    if (x == -1) assert(0);
    for (int i = 0; i < n; i++){
        int nxt = y + 1;
        if (nxt == m) nxt = y - 1;
        while(a[i][y].size()){
            go(i, y, i, nxt);
        }
    }

    for (int j = 0; j < m; j++){
        int nxt = x + 1;
        if (nxt == n) nxt = x - 1;
        while(a[x][j].size()){
            go(x, j, nxt, j);
        }
    }


    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        if (i == x || j == y) continue;
        while(a[i][j].size()){
            if (a[i][j].back() == '1'){
                go(i, j, i, y);
            } else {
                go(i, j, x, j);
            }
        }
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        if (i == x || j == y) continue;
        reverse(all(b[i][j]));
        make(b[i][j]);
    }


    for (int i = 0; i < n; i++) if (i != x){
        reverse(all(b[i][y]));
        make(b[i][y]);
    }


    for (int j = 0; j < m; j++) if (j != y){
        reverse(all(b[x][j]));
        make(b[x][j]);
    }
    reverse(all(b[x][y]));
    make(b[x][y]);


    ///

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        if (i == x || j == y) continue;
        for (char c : b[i][j]){
            go(x, y, i, y);
            go(i, y, i, j);
        }
    }


    for (int i = 0; i < n; i++) if (i != x){
        for (char c : b[i][y]){
            go(x, y, i, y);
        }
    }

    for (int j = 0; j < m; j++) if (j != y){
        for (char c : b[x][j]){
            go(x, y, x, j);
        }
    }


 /*for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "-";
            for (int c : a[i][j]) cout << (char)c;
            cout << ' ';
        }
        cout << endl;
    }*/

    cout << ans.size() << "\n";
    for (auto c : ans) cout << c.a + 1 << ' ' << c.b + 1 << ' ' << c.c + 1 << ' ' << c.d + 1 << "\n";
}