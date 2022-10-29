#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;
            
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 1010;

const pii d[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

pii operator+(pii a, pii b) {
    return mp(a.X + b.X, a.Y + b.Y);    
}

int n, m;
pii A, B;
string s[MAXN];
bool a[MAXN][MAXN];
bool used[MAXN][MAXN][4][3];
queue<pair<pii, pii>> q;

void addState(pii p, int a3, int a4) {
    if (!used[p.X][p.Y][a3][a4]) {
        used[p.X][p.Y][a3][a4] = 1;
        q.push(mp(p, mp(a3, a4)));    
    }
}

void bfs(pii A) {
    memset(used, 0, sizeof(used));

    forn(i, 4) {
        addState(A, i, 0);
    }
    
    while (!q.empty()) {
        auto qq = q.front();
        q.pop();

        pii S = qq.X;
        int cd = qq.Y.X;
        int num = qq.Y.Y;

        //noch dir
        pii nS = S + d[cd];
        if (0 <= nS.X && nS.X < n && 0 <= nS.Y && nS.Y < m && a[nS.X][nS.Y]) {
            addState(nS, cd, num);      
        }
        
        //ch dir
        for (int add = -1; add <= 1; add += 2) {
            int nd = (cd + 4 + add) % 4;
            if (num < 2) {
                addState(S, nd, num + 1);
            }
        }           
    }
}

int main() {
    
    while (cin >> n >> m) {
        forn(i, n) {
            cin >> s[i];   
        }
        
        forn(i, n) {
            forn(j, m) {
                if (s[i][j] == '*') {
                    a[i][j] = 0;
                } else {
                    a[i][j] = 1;
                    if (s[i][j] == 'S') {
                        A = {i, j};
                    }
                    if (s[i][j] == 'T') {
                        B = {i, j};
                    }
                }
            }
        }
        
        bfs(A);
        //cout << A.X << ' ' << A.Y << '\n';
        //cout << B.X << ' ' << B.Y << '\n';
        
        
        bool ans = 0;
        forn(i, 4) {
            forn(j, 3) {
                if (used[B.X][B.Y][i][j]) {
                    //cout << i << ' ' << j << '\n';
                    ans = 1;   
                }
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");
    }
    
    return 0;
}