#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

int ini, fim;
int n,m;

struct channel {
    int a, b;
    int c, id;

    bool operator< (const channel& ot) const {
        return b < ot.b;
    }

} ch[210000];

pair<int, pair<int, int>> comm[210000];

int times[810000];
int distinct_times;

pair<int, int> tree[3210000];
pair<int, int> update1[3210000];
pair<int, int> update12[3210000];

void visit(int i, int st, int end) {
    int xx = update1[i].first - times[st];
    //printf("updating node %d with xx=%d\n", i, xx);
    if (xx > tree[i].first) {
        tree[i] = make_pair(xx, update1[i].second);
    }

    if (update12[i].first > tree[i].first) {
        tree[i] = update12[i];
    } 

    if (st != end) {
        update1[2*i] = max(update1[2*i], update1[i]);
        update1[2*i+1] = max(update1[2*i+1], update1[i]);
        update12[2*i] = max(update12[2*i], update12[i]);
        update12[2*i+1] = max(update12[2*i+1], update12[i]);
    }

    update1[i] = make_pair(0, 0);
    update12[i] = make_pair(0, 0);
}

pair<int, int> read(int x, int y, int i=1, int st=0, int end=distinct_times-1) {
    visit(i, st, end);
    
    if (x > end || y < st) return make_pair(0,0);
    if (x <= st && end <= y) return tree[i];

    int mid = (st+end)/2;
    return max(read(x,y,2*i,st,mid), read(x,y,2*i+1,mid+1,end));
}

void update(int x, int y, pair<int, int> delta, int i=1, int st=0, int end=distinct_times-1) {
    if (x > y) return;

    visit(i, st, end);

    if (x > end || y < st) return;
    if (x <= st && end <= y) {
        if (delta.second < 0) {
            delta.second = -delta.second;
            update12[i] = delta;
        } 
        else {
            update1[i] = delta;
        }
        visit(i, st, end);
        return;
    }

    int mid = (st+end)/2;
    update(x,y,delta,2*i,st,mid);
    update(x,y,delta,2*i+1,mid+1,end);
    tree[i] = max(tree[2*i], tree[2*i+1]);
}

void upd(int idx, int curtime) {
    if (curtime > comm[idx].second.first) curtime = comm[idx].second.first;
    int len = curtime - comm[idx].first;

    int curtime_compressed = lower_bound(times, times+distinct_times, curtime) - times;
    int left_compressed = lower_bound(times, times+distinct_times, comm[idx].first) - times;
    //printf("updating %d %d %d %d %d\n", left_compressed, comm[idx].first, curtime_compressed, curtime, idx);
    
    update(left_compressed, curtime_compressed, make_pair(curtime, idx));
    update(0, left_compressed-1, make_pair(len, -idx));
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &comm[i].first, &comm[i].second.first);
        comm[i].second.second = i;
        times[2*i] = comm[i].first;
        times[2*i+1] = comm[i].second.first;
    }

    sort(comm, comm+n);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ch[i].a, &ch[i].b, &ch[i].c);
        ch[i].id = i;
        times[2*n + 2*i] = ch[i].a;
        times[2*n + 2*i + 1] = ch[i].b;
    }

    sort(ch, ch+m);
    sort(times, times+2*(n+m));
    
    distinct_times = unique(times, times+2*(n+m)) - times;

    long long best = 0;
    int best_ch = -1;
    int best_comm = -1;

    for (int i = 0; i < m; i++) {
        while (fim < n && comm[fim].first <= ch[i].b) {
            fim++;
        }

        while (ini != fim && comm[ini].second.first <= ch[i].b) {
            upd(ini, ch[i].b);
            ini++;
        }

        if (ini != fim) upd(ini, ch[i].b);

        int aa = lower_bound(times, times+distinct_times, ch[i].a) - times;
        int bb = lower_bound(times, times+distinct_times, ch[i].b) - times;
        pair<int, int> rr = read(aa, bb);

        long long cand = ch[i].c * 1ll * rr.first;
        if (cand > best) {
            best = cand;
            best_ch = ch[i].id;
            best_comm = comm[rr.second].second.second;
        }
    }

    if (best_ch == -1) printf("0\n");
    else printf("%lld\n%d %d\n", best, best_comm+1, best_ch+1);
}