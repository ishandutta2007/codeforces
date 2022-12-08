#include <iostream>
#include <cstdio>

#include <map>
#include <utility>
#include <vector>

#include <cassert>

using namespace std;

const int MAXQ = 2e5 + 1000;
const bool DEBUG = false;

typedef map<int, int> mapi;

int Q;

#define is ==

int Why_so_complicated_Noam = 0;
void get_next(int& t, int& l, int& r, int& x) {
    scanf("%d", &t);
    if(t == 1) {
        scanf("%d%d%d", &l, &r, &x);
        if(not DEBUG) l ^= Why_so_complicated_Noam, r ^= Why_so_complicated_Noam, x ^= Why_so_complicated_Noam;
        if(l > r) swap(l, r);
    }
    if(t == 2) {
        scanf("%d%d", &l, &r);
        if(not DEBUG) l ^= Why_so_complicated_Noam, r ^= Why_so_complicated_Noam;
        if(l > r) swap(l, r);
    }
    r++;
}
void answer(int v) {
    Why_so_complicated_Noam = v is -1 ? 1 : v;
    printf("%d\n", v);
}

int t, l, r, x;

typedef vector<int> vi;

int pv[2 * MAXQ];

int dsup[2 * MAXQ];
vi dsuv[2 * MAXQ];
void dsui(const int& s) {
    for(int i = 0;i <= s;i++) dsup[i] = i, dsuv[i].assign(1, i), pv[i] = 0;
}
int dsuf(const int& n) {
    if(dsup[n] == n) return n;
    return (dsup[n] = dsuf(dsup[n]));
}
bool dsum(int a, int b, int c) {
    int C = pv[a]^pv[b]^c;
    a = dsuf(a), b = dsuf(b);
    if(a == b) return false;
    if(dsuv[b].size() > dsuv[a].size()) swap(a, b);
    dsup[b] = a;
    for(int i = 0;i < dsuv[b].size();i++) {
        dsuv[a].push_back(dsuv[b][i]);
        pv[dsuv[b][i]] ^= C;
    }
    dsuv[b].clear();
    return true;
}

mapi O;
int get_ind(int v, bool insert) {
    if(O.find(v) != O.end()) return O[v];
    if(insert) {
        int ind = O.size();
        O.insert(make_pair(v, ind));
        return ind;
    } else return -1;
}

int main() {
    scanf("%d", &Q);
    
    dsui(Q + 10);
    
    while(Q--) {
        get_next(t, l, r, x);
        
        
        if(t == 1) {
            l = get_ind(l, true);
            r = get_ind(r, true);
            if(dsuf(l) != dsuf(r)) assert(dsum(l, r, x));
        }
        if(t == 2) {
            l = get_ind(l, false);
            r = get_ind(r, false);
            if(l is -1 or r is -1) {answer(-1);}
            else if(dsuf(l) == dsuf(r)) answer(pv[l]^pv[r]);
            else answer(-1);
        }
        
        //cerr << l << " " << r << "\n";
    }
    
    return 0;
}