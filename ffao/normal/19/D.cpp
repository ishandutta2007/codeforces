#include <stdio.h>
#include <set>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
set<pii> tree[1000000];
char op[10];
int type[200000];

int n;

pii best;
bool found;

int maxy;

void add(const pii& point, int i=1, int st=1, int end=maxy) {
    int y = point.second;
    
    bool left = false;
    while (true) { 
        if (!left && st <= y && end >= y) {
            tree[i].insert(point);
        }
        
        if (st == end) return;
        
        if (y <= (st+end)/2) {
            i = 2*i;
            end = (st+end)/2;
            left = true;
        }
        else {
            i = 2*i+1;
            st = (st+end)/2 + 1;
            left = false;
        }
    }
}

void remove(const pii& point, int i=1, int st=1, int end=maxy) {
    int y = point.second;
    
    bool left = false;
    while (true) {
        if (st > y || end < y) return; 
        if (!left && st <= y && end >= y) {
            tree[i].erase(point);
        }
        
        if (st == end) return;
        
        if (y <= (st+end)/2) {
            i = 2*i;
            end = (st+end)/2;
            left = true;
        }
        else {
            i = 2*i+1;
            st = (st+end)/2 + 1;
            left = false;
        }
    }
}

void query(const pii& point, int i=1, int st=1, int end=maxy) {
    int x = point.first, y = point.second;
    
    if (end <= y) return; 
    if (st > y) {
        set<pii>::iterator iter = tree[i].lower_bound(make_pair(x+1, -1));
        if (iter != tree[i].end()) {
            pii ans = *iter;
            if (!found || ans.first < best.first || (ans.first == best.first && ans.second < best.second) ) {    
                found = true;
                best = ans;
            }
        }
        return;
    }
    
    query(point, 2*i, st, (st+end)/2);
    query(point, 2*i+1, (st+end)/2 + 1, end);
}

int x, y;
pair< pii, int > points[500000];

bool comparay(pair<pii, int> a, pair<pii, int> b) {
    return a.first.second < b.first.second;
}

bool comparaid(pair<pii, int> a, pair<pii, int> b) {
    return a.second < b.second;
}

int origx[500000], origy[500000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", op, &points[i].first.first, &points[i].first.second);
        
        if (op[0] == 'a') type[i] = 0;
        else if (op[0] == 'f') type[i] = 2;
        else type[i] = 1;
        
        points[i].second = i;
    }
    
    sort(points,points+n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        origx[cur] = points[i].first.first;
        int oc = cur;     
        if (i != n-1 && points[i].first.first != points[i+1].first.first) cur++;
        points[i].first.first = oc;
    }
    
    sort(points,points+n,comparay);
    cur = 1;
    for (int i = 0; i < n; i++) {
        origy[cur] = points[i].first.second;
        int oc = cur;
        if (i != n-1 && points[i].first.second != points[i+1].first.second) cur++;
        points[i].first.second = oc; 
    }
    
    maxy = cur;
    sort(points,points+n,comparaid);
    
    for (int i = 0; i < n; i++) {
        //printf("%s\n", op[i]);
        if (type[i] == 0) {
            //printf("add %d %d\n", points[i].first.first, points[i].first.second);
            add(points[i].first);
        }
  
        else if (type[i] == 1) {
            remove(points[i].first);
        }
        
        else {
            found = false;
            query(points[i].first);
            if (found) printf("%d %d\n", origx[best.first], origy[best.second]);
            else printf("-1\n");
        }
    }
}