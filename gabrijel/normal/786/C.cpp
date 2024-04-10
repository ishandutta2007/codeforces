#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int offset = (1<<18);

int n, k;
int poc, brrj;

int tajm = 0;

int niz[maxn];

vector <vector <int> > poz;
vector <int> vi;

vector <int> rj;

struct node
{
    int vr = 0;
    node *l = 0, *r = 0;
    node(int _vr, node *_l, node *_r)
    {
        vr = _vr;
        l = _l;
        r = _r;
    }
    node()
    {
        vr = 0;
        l = 0;
        r = 0;
    }
};

struct tournament
{
    node *NIL = new node(0, 0, 0);
    node *root[maxn];
    tournament()
    {
        NIL -> l = NIL;
        NIL -> r = NIL;
        NIL -> vr = 0;
    }
    node* build(int l, int r)
    {
        if(l == r)
        {
            if(l < n)
            {
                int koji = niz[l];
                if(poz[koji].back() == l)
                {
                    //poz[koji].pop_back();
                    return new node(1, NIL, NIL);
                }
                return new node(0, NIL, NIL);
            }
            return new node(0, NIL, NIL);
        }
        int mid = (l + r) / 2;
        node *ld = build(l, mid);
        node *rd = build(mid + 1, r);
        return new node((ld -> vr) + (rd -> vr), ld, rd);
    }
    node* update(node *prosli, int ind, int l, int r, int kolko)
    {
        if(l == r) return new node(kolko, NIL, NIL);
        int mid = (l + r) / 2;
        node *ld, *rd;
        if(ind <= mid)
        {
            ld = update(prosli -> l, ind, l, mid, kolko);
            rd = prosli -> r;
        }
        else
        {
            ld = prosli -> l;
            rd = update(prosli -> r, ind, mid + 1, r, kolko);
        }
        return new node((ld -> vr) + (rd -> vr), ld, rd);
    }
    void query(node *cvor, int l, int r)
    {
        //cout << cvor -> vr << " " << l << " " << r << endl;
        poc = max(poc, l);
        if(l >= n)
        {
            poc = n;
            return;
        }
        if(l == r) return;
        int mid = (l + r) / 2;
        node *ld, *rd;
        ld = cvor -> l;
        rd = cvor -> r;
        if(k >= ld -> vr)
        {
            k -= ld -> vr;
            query(rd, mid + 1, r);
        }
        else
        {
            query(ld, l, mid);
        }
        return;
    }
}T;

int main()
{
    scanf("%d", &n);
    poz.insert(poz.begin(), n, vi);
    REP(i, 0, n)
    {
        scanf("%d", &niz[i]);
        niz[i]--;
        poz[niz[i]].push_back(i);
    }
    REP(i, 0, n)
    {
        reverse(poz[i].begin(), poz[i].end());
    }
    T.root[0] = T.build(0, offset - 1);
    REP(i, 0, n)
    {
        if(poz[i].size()) poz[i].pop_back();
    }
    tajm++;
    REP(i, 0, n)
    {
        int izb = niz[i];
        T.root[i + 1] = T.update(T.root[i], i, 0, offset - 1, 0);
        if(poz[izb].size())
        {

            int dod = poz[izb].back();
            poz[izb].pop_back();
            T.root[i + 1] = T.update(T.root[i + 1], dod, 0, offset - 1, 1); //! valjda radi
        }
    }
    REP(t, 1, n + 1)
    {
        poc = 0;
        brrj = 0;
        while(poc < n)
        {
            k = t;
            //cout << poc <<  " " << k << endl;
            brrj++;
            T.query(T.root[poc], 0, offset - 1);
        }
        rj.push_back(brrj);
    }
    REP(i, 0, (int)rj.size())
    {
        printf("%d ", rj[i]);
    }
    return 0;
}