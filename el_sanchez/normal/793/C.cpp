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
const int MAXN = 100500;

typedef pair<ll, ll> fraction;

fraction mf(ll a) {
    return mp(a, 1ll);    
}

fraction mf(ll a, ll b) {
    return mp(a, b);    
}

fraction operator+(fraction a, fraction b) {
    return mp(a.X * b.Y + a.Y * b.X, a.Y * b.Y);        
}

fraction operator*(fraction a, fraction b) {
    return mp(a.X * b.X, a.Y * b.Y);        
}

bool cmp0(fraction a, fraction b) {
    if (a.Y < 0) {
        a.X *= -1;
        a.Y *= -1;    
    }
    if (b.Y < 0) {
        b.X *= -1;
        b.Y *= -1;    
    }
    
    return a.X * b.Y < a.Y * b.X;    
}

bool cmp1(fraction a, fraction b) {
    if (a.Y < 0) {
        a.X *= -1;
        a.Y *= -1;    
    }
    if (b.Y < 0) {
        b.X *= -1;
        b.Y *= -1;    
    }
    
    return a.X * b.Y <= a.Y * b.X;    
}

bool eq(fraction a, fraction b) {
    return a.X * b.Y == a.Y * b.X;    
}

const int SHIFT = (int)3e5;
int n;
ll Lx, Rx, Ly, Ry;
fraction LX, RX, LY, RY;
int x, y, vx, vy;
int ptr, sz;
fraction T[4], nT[4];
fraction TL, TR;

bool inside(int x, int y) {
    return (Lx <= x && x <= Rx) && (Ly <= y && y <= Ry);
}

void calcY(ll Ly) {
    ll dy = Ly - y;
    T[ptr] = mf(dy, vy);

    fraction nx = mf(x, 1) + T[ptr] * mf(vx, 1);
    
    //cout << Ly << ": " << 1.0 * nx.X / nx.Y << '\n';
    
    if (cmp1(LX, nx) && cmp1(nx, RX)) {
        ptr++;                   
    }     
}

void calcX(ll Lx) {
    ll dx = Lx - x;
    T[ptr] = mf(dx, vx);

    fraction ny = mf(y, 1) + T[ptr] * mf(vy, 1);
    if (cmp1(LY, ny) && cmp1(ny, RY)) {
        ptr++;                   
    }     
}

int main() {
    
    cin >> n;
    cin >> Lx >> Ly >> Rx >> Ry;
    LX = mf(Lx);
    LY = mf(Ly);
    RX = mf(Rx);
    RY = mf(Ry);
    
    TL = mf(0);
    TR = mf(1e9);
    forn(i, n) {
        scanf("%d%d%d%d", &x, &y, &vx, &vy);
        
        //if stop
        if (vx == 0 && vy == 0) {
            if (!inside(x, y) || (x == Lx || x == Rx || y == Ly || y == Ry)) {
                cout << -1 << '\n';
                return 0;
            } else {
                continue;
            }
        }
        
        if (vx == 0 && (x == Lx || x == Rx)) {
            cout << -1 << '\n';
            return 0;    
        }
        if (vy == 0 && (y == Ly || y == Ry)) {
            cout << -1 << '\n';
            return 0;    
        }
        
        ptr = 0;
        
        //get Ly
        if (vy != 0) {
            calcY(Ly);
            calcY(Ry);
        }
        if (vx != 0) {
            calcX(Lx);
            calcX(Rx);
        }
        
        //unique
        if (ptr != 0) {
            sort(T, T + ptr, cmp0);
        }
        
        //cout << ptr << '\n';
        
        sz = 0;
        for (int i = 0; i < ptr; i++) {
            bool ok = 1;
            for (int j = 0; j < i; j++) {
                if (eq(T[i], T[j])) {
                    ok = 0;
                }
            }
            if (ok) {
                nT[sz++] = T[i];   
            }
        }
        
        forn(i, sz) {
            T[i] = nT[i];    
        }
/*        
        forn(i, sz) {
            cout << 1.0 * T[i].X / T[i].Y << ' ';   
        }
        cout << '\n';
*/        
        if (sz <= 1) {
            cout << -1 << '\n';
            return 0;   
        } else {
            assert(sz == 2);
            if (cmp0(TL, T[0])) {
                TL = T[0];   
            }
            if (cmp0(T[1], TR)) {
                TR = T[1];   
            }
        }
    }
    
    if (cmp1(TR, TL)) {
        cout << -1 << '\n';
        return 0;
    }
    cout.precision(30);
    cout << 1.0 * TL.X / TL.Y << '\n';
    
    return 0;
}