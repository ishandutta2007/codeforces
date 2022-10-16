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

map<int, int> compress;

int n;
int tree[810000];
int direct_hit[210000];
int loc[210000];
int upto[210000];
vector<int> coords;
vector<int> dominoes;
pair<int, int> trans[410000][21];

void build_tree(int i=1, int st=0, int end=n-1) {
    if (st == end) {
        tree[i] = st;
        return;
    }

    int mid = (st+end)/2;
    build_tree(2*i, st, mid);
    build_tree(2*i+1, mid+1, end);
    tree[i] = tree[2*i];
    if (upto[ tree[2*i+1] ] > upto[ tree[2*i] ]) tree[i] = tree[2*i+1];
}

int query(int a, int b, int i=1, int st=0, int end=n-1) {
    if (a <= st && end <= b) {
        return tree[i];
    }

    if (end < a || b < st) {
        return -1;
    }

    int mid = (st+end)/2;
    int f = query(a, b, 2*i, st, mid);
    int s = query(a, b, 2*i+1, mid+1, end);

    if (f == -1) swap(f, s);
    if (s == -1) return f;
    if (upto[f] < upto[s]) swap(f, s);
    return f;
}



int solve(int a, int b) {
    a--; b--;
    int start = dominoes[a];
    int end = dominoes[b];

    int p = 20;
    int ans = 0;
    while (p >= 0) {
        if (trans[start][p].first < end) {
            ans += trans[start][p].second;
            start = trans[start][p].first;
        } 
        p--;
    }

    return ans + trans[start][0].second;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int p, len;
        scanf("%d %d", &p, &len);
        loc[i] = p;
        upto[i] = p+len;
        coords.push_back(p);
        coords.push_back(p+len);
        dominoes.push_back(p);
    }

    build_tree();
    sort(coords.begin(), coords.end());
    int dd = unique(coords.begin(), coords.end()) - coords.begin();

    for (int i = 0; i < dd; i++) {
        compress[coords[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        direct_hit[i] = upper_bound(dominoes.begin(), dominoes.end(), upto[i]) - dominoes.begin();
        direct_hit[i]--;
    }

    for (int i = dd-1; i >= 0; i--) {
        int this_domino = lower_bound(dominoes.begin(), dominoes.end(), coords[i]) - dominoes.begin();
        
        if (this_domino == n) {
            trans[i][0] = mp(i, 0);
        }

        else if (dominoes[this_domino] != coords[i]) {
            trans[i][0] = mp(compress[dominoes[this_domino]], dominoes[this_domino] - coords[i]);
        }

        else {
            int max_reach = query(this_domino, direct_hit[this_domino]);
            if (max_reach == this_domino) {
                trans[i][0] = mp(compress[upto[this_domino]], 0);
            }
            else {
                trans[i][0] = mp(compress[dominoes[max_reach]], 0);
            }
        }
    }

    for (int p = 1; p <= 20; p++) {
        for (int i = 0; i < dd; i++) {
            pair<int, int> f = trans[i][p-1];
            pair<int, int> s = trans[trans[i][p-1].first][p-1];
            trans[i][p] = mp(s.first, f.second + s.second); 
        }
    }

    for (int i = 0; i < n; i++) {
        dominoes[i] = compress[dominoes[i]];
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b));
    }
}