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
const ld eps = 1e-8;
const int INF = (int)1e9;
const int MAXN = 200500;

int rnd() {
    return (rand() << 15) + rand();
}

struct node {
    pii key;
    int pr, cnt;
    ll sum;
    node *l, *r;
    node(pii _key){
        key = _key;
        sum = key.X;
        pr = rand();
        cnt = 1;
        l = r = NULL;
    }
};

int cnt(node *p) {
    return p ? p->cnt : 0;
}

ll sum(node *p) {
    return p ? p->sum : 0;
}

void upd_cnt(node *&p) {
    if (p) {
        p->cnt = 1 + cnt(p->l) + cnt(p->r);
        pii key = p->key;
        p->sum = (ll)key.X + sum(p->l) + sum(p->r);
    }
}

void split(node *p, pii key, node *&l, node *&r) {
    if (p == NULL) {
        l = r = NULL;
        return;
    }

    if (key <= p->key) {
        split(p->l, key, l, p->l);
        r = p;
    } else {
        split(p->r, key, p->r, r);
        l = p;
    }
    upd_cnt(p);
}

void merge(node *&p, node *l, node *r) {
    if (l == NULL)
        p = r;
    else if (r == NULL)
        p = l;
    else if (l->pr < r->pr) {
        p = l;
        merge(l->r, l->r, r);
    } else {
        p = r;
        merge(r->l, l, r->l);
    }
    upd_cnt(p);
}

void insert(node *&p, pii key, int pr) {
    if (p == NULL) {
        p = new node(key);
        p->pr = pr;
        return;
    }
    if (pr > p->pr) {
        if (key > p->key)
            insert(p->r, key, pr);
        else
            insert(p->l, key, pr);
    } else {
        node *t = new node(key);
        t->pr = pr;
        split(p, key, t->l, t->r);
        p = t;
    }
    upd_cnt(p);
}

void erase(node *&p, pii key) {
    if (p == NULL)
        return;
    if (p->key == key)
        merge (p, p->l, p->r);
    else {
        if (key < p->key)
            erase(p->l, key);
        else
            erase(p->r, key);
    }
    upd_cnt(p);
}

ll getSum(node *t, int need) {
    if (need == 0) {
        return 0;
    }
    if (!t) {
        return 0;
    }
    
    ll res = 0;
    if (need < cnt(t->l)) {
        return getSum(t->l, need);
    }
    need -= cnt(t->l);
    res += sum(t->l);   
    
    if (need == 0) {
        return res;   
    }
    
    pii key = t->key;
    need -= 1;
    res += key.X;
    
    if (need == 0) {
        return res;
    }
    
    return res + getSum(t->r, need);
}

const ll LINF = (ll)1e18;

node *root;
int n, m, k, cost[MAXN];
int ok[MAXN][2];
vector<pii> c[2][2];
ll ans, res;

int main() {

    while (cin >> n >> m >> k) {
        res = LINF;
        
        forn(i, n) {
            scanf("%d", &cost[i]);
        }
        
        forn(i, n) {
            ok[i][0] = ok[i][1] = 0;
        }
        
        forn(id, 2) {
            int sz, k;
            scanf("%d", &sz);
            forn(i, sz) {
                scanf("%d", &k);
                k--;
                ok[k][id] = 1;
            }
        }
        
        forn(i, 2) {
            forn(j, 2) {
                c[i][j].clear();
            }
        }
        
        forn(i, n) {
            c[ok[i][0]][ok[i][1]].pb(mp(cost[i], i));   
        }
        
        forn(i, 2) {
            forn(j, 2) {
                sort(all(c[i][j]));
            }
        }
        
        int sT = min((int)c[1][1].size(), m);
        
        //init
        root = NULL;
        ans = 0;
                
        for (int i = 0; i < sT; i++) {
            ans += c[1][1][i].X;       
        }
        
        int sK = max(0, k - sT);
        
        if (sK > (int)c[0][1].size() || sK > (int)c[1][0].size()) {
            cout << -1 << '\n';
            continue;    
        }
        
        for (int i = 0; i < sK; i++) {
            ans += c[0][1][i].X;
            ans += c[1][0][i].X;
        }
        
        for (int mask = 1; mask <= 2; mask++) {
            int x = (mask >> 1) & 1;
            int y = (mask     ) & 1;

            for (int i = sK; i < (int)c[x][y].size(); i++) {
                insert(root, c[x][y][i], rnd());
            }
        }
        
        for (int i = 0; i < (int)c[0][0].size(); i++) {
            insert(root, c[0][0][i], rnd());    
        }
/*        
        forn(i, 2) {
            forn(j, 2) {
                cout << i << ' ' << j << ":\n";
                for (auto p: c[i][j]) {
                    cout << p.X << ", " << p.Y << '\n';
                }
            }
        }
*/         
        //LET'S GO
        for (int t = sT; t >= 0; t--) {
            //cout << "watch " << t << '\n';
            int need = m - (t + 2 * sK);
           // cout << "ANS = " << ans << '\n';
            //cout << need << '\n';
            //cout << cnt(root) << '\n';
            if (need >= 0 && cnt(root) >= need) {
                ll add = getSum(root, need);  

                res = min(res, ans + add);               
            }
            
            if (t == 0) {
                break;
            }
            
            ans -= c[1][1][t - 1].X;
            int nK = max(0, k - (t - 1));
            if (nK > (int)c[0][1].size() || nK > (int)c[1][0].size()) {
                break;
            }
            
            for (int mask = 1; mask <= 2; mask++) {
                int x = (mask >> 1) & 1;
                int y = (mask     ) & 1;

                for (int i = sK; i < nK; i++) {
                    erase(root, c[x][y][i]);
                    ans += c[x][y][i].X;    
                }
            }
            
            sK = nK;                
        }
        
        if (res == LINF) {
            res = -1;
        }
        
        cout << res << '\n';
    }          
    
    return 0;
}