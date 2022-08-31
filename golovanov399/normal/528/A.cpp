#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

void paint(vector<int>& tr, int v, int l, int r, int l1, int r1, int x){
    if (l >= l1 && r <= r1){
        tr[v] = x;
        return;
    }
    if (r <= l1 || r1 <= l)
        return;
    int m = (l + r) / 2;
    if (tr[v])
        tr[v + v] = tr[v + v + 1] = tr[v];
    tr[v] = 0;
    paint(tr, v + v, l, m, l1, r1, x);
    paint(tr, v + v + 1, m, r, l1, r1, x);
}

int main(){

    int w, h;
    scanf("%d%d", &w, &h);
    int n;
    scanf("%d", &n);
    multiset<int> W, H;
    W.insert(-w);
    H.insert(-h);
    int rw = 1;
    while (rw < w)
        rw <<= 1;
    vector<int> stw(rw + rw);
    int rh = 1;
    while (rh < h)
        rh <<= 1;
    vector<int> sth(rh + rh);
    vector<int> Rw(w), Rh(h);
    Rw[0] = w;
    Rh[0] = h;
    stw[1] = sth[1] = 1;
    for (int i = 0; i < n; i++){
        char tp;
        int x;
        scanf("\n%c %d", &tp, &x);
        if (tp == 'H'){
            int v = 1;
            int l = 0;
            int r = rh;
            while (!sth[v]){
                int m = (l + r) >> 1;
                if (m > x){
                    r = m;
                    v = v + v;
                } else {
                    l = m;
                    v = v + v + 1;
                }
            }
            int qw = sth[v];
            H.erase(H.find(qw - 1 - Rh[qw - 1]));
            Rh[x] = Rh[qw - 1];
            Rh[qw - 1] = x;
            H.insert(qw - 1 - x);
            H.insert(x - Rh[x]);
            paint(sth, 1, 0, rh, qw - 1, x, qw);
            paint(sth, 1, 0, rh, x, Rh[x], x + 1);
        } else {
            int v = 1;
            int l = 0;
            int r = rw;
            // for (int i = 1; i < rw + rw; i++)
            //  cerr << stw[i] << " ";
            // cerr << "\n";
            while (!stw[v]){
                int m = (l + r) >> 1;
                if (m > x){
                    r = m;
                    v = v + v;
                } else {
                    l = m;
                    v = v + v + 1;
                }
            }
            int qw = stw[v];
            // cerr << qw << " " << x << "\n";
            W.erase(W.find(qw - 1 - Rw[qw - 1]));
            Rw[x] = Rw[qw - 1];
            Rw[qw - 1] = x;
            W.insert(qw - 1 - x);
            W.insert(x - Rw[x]);
            paint(stw, 1, 0, rw, qw - 1, x, qw);
            paint(stw, 1, 0, rw, x, Rw[x], x + 1);
        }
        printf("%I64d\n", 1ll * (*(W.begin())) * (*(H.begin())));
    }

    return 0;
}