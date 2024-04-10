#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int segtreePow = 19;
const int segtreeMax = 1 << segtreePow;
const int segtreeSize = segtreeMax * 2;
const int llInf = 123456789012345678;

int segTree[segtreeSize] = {};
int lazy[segtreeSize] = {};
bool doLazy[segtreeSize] = {};

void init(int i, int tl, int tr, int n)
{
    if (tl == tr)
        segTree[i] = (tl < n) ? 0 : llInf;
    else
    {
        int tm = (tl + tr) / 2;
        init(i * 2, tl, tm, n);
        init(i * 2 + 1, tm + 1, tr, n);
        segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
    }
}

void push(int i)
{
    if (!doLazy[i]) return;
    if (i >= segtreeMax)
    {
        doLazy[i] = false;
        segTree[i] += lazy[i];
        lazy[i] = 0;
        return;
    }
    doLazy[i * 2] = doLazy[i * 2 + 1] = true;
    lazy[i * 2] += lazy[i]; lazy[i * 2 + 1] += lazy[i];
    doLazy[i] = false;
    segTree[i] += lazy[i];
    lazy[i] = 0;
}

void update(int i, int tl, int tr, int l, int r, int delta)
{
    if (l > r) return;
    push(i);
    if (l == tl && r == tr)
    {
        doLazy[i] = true;
        lazy[i] += delta;
        return;
    }
    int tm = (tl + tr) / 2;
    update(i * 2, tl, tm, l, min(r, tm), delta);
    update(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r, delta);
    segTree[i] = min(segTree[i * 2] + lazy[i * 2], segTree[i * 2 + 1] + lazy[i * 2 + 1]);
}

int query(int i, int tl, int tr, int l, int r)
{
    if (l > r) return llInf;
    push(i);
    if (l == tl && r == tr) return segTree[i] + lazy[i];
    int tm = (tl + tr) / 2;
    return min(query(i * 2, tl, tm, l, min(r, tm)),
               query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

main()
{
    int n; scanf("%I64d", &n);
    init(1, 0, segtreeMax - 1, n);
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%I64d", &a);
        update(1, 0, segtreeMax - 1, i, i, a);
/*
            cout << "Tree contents: " << endl;
            for (int i = 1; i < segtreeSize; i++)
                if (segTree[i] > llInf / 2)
                    cout << "? ";
                else
                    cout << segTree[i] << " ";
            cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << doLazy[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << lazy[i] << " "; cout << endl;
*/
    }
    int m; scanf("%I64d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b; scanf("%I64d%I64d", &a, &b);
        if (getchar() == ' ')
        {
            int c; scanf("%I64d", &c);
            if (a > b)
                update(1, 0, segtreeMax - 1, a, n - 1, c),
                update(1, 0, segtreeMax - 1, 0, b, c);
            else
                update(1, 0, segtreeMax - 1, a, b, c);
/*
            cout << "Tree contents: " << endl;
            for (int i = 1; i < segtreeSize; i++)
                if (segTree[i] > llInf / 2)
                    cout << "? ";
                else
                    cout << segTree[i] << " ";
            cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << doLazy[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << lazy[i] << " "; cout << endl;
*/
        }
        else
        {
            if (a > b)
                printf("%I64d\n", min(
                    query(1, 0, segtreeMax - 1, a, n - 1),
                    query(1, 0, segtreeMax - 1, 0, b)
                ));
            else
                printf("%I64d\n", query(1, 0, segtreeMax - 1, a, b));
/*
            cout << "Tree contents: " << endl;
            for (int i = 1; i < segtreeSize; i++)
                if (segTree[i] > llInf / 2)
                    cout << "? ";
                else
                    cout << segTree[i] << " ";
            cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << doLazy[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << lazy[i] << " "; cout << endl;
*/
        }
    }

    /*
    for (;;)
    {
        int id; cin >> id;
        if (id == 1)
        {
            int l, r, delta; cin >> l >> r >> delta;
            for (int i = l; i <= r; i++) naive[i] += delta;
            update(1, 0, segtreeMax - 1, l, r, delta);
            for (int i = 0; i < segtreeMax; i++) cout << naive[i] << " "; cout << endl;
            cout << "Tree contents: " << endl;
            for (int i = 1; i < segtreeSize; i++) cout << segTree[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << doLazy[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << lazy[i] << " "; cout << endl;
        }
        if (id == 2)
        {
            int l, r; cin >> l >> r;
            int na = 0; for (int i = l; i <= r; i++) na = max(na, naive[i]);
            int sa = query(1, 0, segtreeMax - 1, l, r);
            cout << "naive = " << na << "; segment = " << sa << endl;
            cout << "Tree contents: " << endl;
            for (int i = 1; i < segtreeSize; i++) cout << segTree[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << doLazy[i] << " "; cout << endl;
            for (int i = 1; i < segtreeSize; i++) cout << lazy[i] << " "; cout << endl;
        }
    }
    */
}