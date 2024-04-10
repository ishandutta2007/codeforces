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

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

class ConvexHullTrick {
    struct CHTPoint {
        double x, y;
        int idx;
        double lim;
    };

    vector<CHTPoint> pilha;

    inline double get_intersection(CHTPoint a, CHTPoint b) {
        double denom = ( double(b.x) - a.x);
        double num = ( double(b.y) - a.y);
        
        return - num / denom;
    }

    bool ccw(CHTPoint p0, CHTPoint p1, CHTPoint p2) {
        return ((p1.y-p0.y)*(p2.x-p0.x) > (p2.y-p0.y)*(p1.x-p0.x));
    }

    public:

    void add_line(double a, double b, int idx) {
        CHTPoint novo = {a, b, idx, 0};
        int tam = pilha.size();
        while (tam >= 2 && !ccw(pilha[tam-2], pilha[tam-1], novo)) {
            pilha.pop_back();
            tam--;
        }
        while (tam >= 1 && fabs(pilha[tam-1].x - a) < 1e-8) {
            pilha.pop_back();
            tam--;
        }

        pilha.push_back(novo);
        if (tam >= 1) pilha[tam-1].lim = get_intersection(pilha[tam-1], pilha[tam]);
    }

    pair<int, double> get_maximum(double x) {
        int st = 0, ed = pilha.size() - 1;
        while (st < ed) {
            int mid = (st+ed)/2;
            if (pilha[mid].lim < x) st = mid+1;
            else ed = mid;
        }

        return make_pair(pilha[st].idx, pilha[st].x * x + pilha[st].y);
    }

    void print() {
        for (int i = 0; i < pilha.size(); i++) {
            printf("%f %f %f\n", pilha[i].x, pilha[i].y, pilha[i].lim);
        }
    }
};

int n, q;
pair< pair<int, int>, int > wal[110000];
ConvexHullTrick tree[410000];

void build_tree(int i=1, int st=0, int end=n-1) {
    vector< pair< pair<int, int>, int> > this_wal(wal+st, wal+(end+1));
    sort(this_wal.begin(), this_wal.end());
    
    for ( int j = 0; j < (int) this_wal.size(); j++) {
        tree[i].add_line(this_wal[j].first.first, this_wal[j].first.second, this_wal[j].second);
    }    

    if (st != end) {
        build_tree(2*i, st, (st+end)/2);
        build_tree(2*i+1, (st+end)/2+1, end);
    }
}

pair<int, double> query(int l, int r, int t, int i=1, int st=0, int end=n-1) {
    if (l <= st && end <= r) {
        return tree[i].get_maximum(t);
    }
    
    if (end < l || r < st) return mp(0, -1);

    pair<int, double> q1 = query(l, r, t, 2*i, st, (st+end)/2);
    pair<int, double> q2 = query(l, r, t, 2*i+1, (st+end)/2+1, end);

    if (q1.second < q2.second) swap(q1, q2);
    return q1;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wal[i].first.second, &wal[i].first.first);
        wal[i].second = i;
    }

    build_tree();
    
    for (int i = 0; i < q; i++) {
        int l, r, t;
        scanf("%d %d %d", &l, &r, &t); l--; r--;
        pair<int, double> ans = query(l, r, t);
        printf("%d\n", ans.first + 1);
    }
}