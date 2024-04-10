#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;

vector<int> d2v(deque<int> q) {
    vector<int> v(q.size());
    for (int i = q.size(); i--; ) {
        v[i] = q.back();
        q.pop_back();
    }
    return v;
}

deque<int> v2d(vector<int> v) {
    deque<int> q;
    while (v.size()) {
        q.push_front(v.back());
        v.pop_back();
    }
    return q;
}

int n,q,x,l,r,k,lastans;
int bsize;
int cnt[320][100005];
deque<int> blocks[320];

int main()
{
    scanf("%d",&n);
    bsize = int(sqrt(n+0.)) + 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        blocks[i / bsize].push_back(x);
        ++cnt[i / bsize][x];
    }

    scanf("%d",&q);
    while (q--) {
        scanf("%d%d%d",&x,&l,&r);
        l = ((l + lastans - 1) % n + n) % n;
        r = ((r + lastans - 1) % n + n) % n;
        if (l > r) swap(l, r);
        if (x == 1) {
            if (l == r) continue;
            int bl = l / bsize;
            int br = r / bsize;
            if (bl == br) {
                vector<int> v = d2v(blocks[bl]);
                l %= bsize;
                r %= bsize;
                int curnum = v[r];
                v.erase(v.begin() + r);
                v.insert(v.begin() + l, curnum);
                blocks[bl] = v2d(v);
            } else {
                vector<int> vl = d2v(blocks[bl]);
                vector<int> vr = d2v(blocks[br]);

                l %= bsize;
                r %= bsize;
                int curnum = vr[r];
                vr.erase(vr.begin() + r);
                --cnt[br][curnum];
                vl.insert(vl.begin() + l, curnum);
                ++cnt[bl][curnum];

                blocks[bl] = v2d(vl);
                blocks[br] = v2d(vr);
                for (int i = bl; i < br; ++i) {
                    curnum = blocks[i].back();
                    blocks[i].pop_back();
                    --cnt[i][curnum];
                    blocks[i+1].push_front(curnum);
                    ++cnt[i+1][curnum];
                }
            }
        } else {
            scanf("%d",&k);
            k = ((k + lastans - 1) % n + n) % n + 1;
            lastans = 0;
            int bl = l / bsize;
            int br = r / bsize;
            if (bl == br) {
                vector<int> v = d2v(blocks[bl]);
                l %= bsize;
                r %= bsize;
                for (int i = l; i <= r; ++i)
                    lastans += v[i] == k;
            } else {
                vector<int> vl = d2v(blocks[bl]);
                vector<int> vr = d2v(blocks[br]);
                l %= bsize;
                r %= bsize;
                for (int i = l; i < vl.size(); ++i)
                    lastans += vl[i] == k;
                for (int i = 0; i <= r; ++i)
                    lastans += vr[i] == k;
                for (int i = bl + 1; i < br; ++i)
                    lastans += cnt[i][k];
            }
            printf("%d\n",lastans);
        }
    }

    return 0;
}