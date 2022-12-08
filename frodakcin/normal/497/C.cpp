#include <iostream>
#include <cstdio>

#include <utility>
#include <set>
#include <algorithm>
#include <memory>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 1000;
const int MAXM = 1e5 + 1000;

struct TUP {
    int a, b;
    int d;
    TUP() {a = b = d = -1;}
    TUP(int c, int e, int f) {
        a = c;
        b = e;
        d = f;
    }
} actors[MAXM], parts[MAXN];

const auto acmp = [](const int& a, const int& b) {return actors[a].b < actors[b].b;};
typedef multiset<int, decltype(acmp), allocator<int> > si;

int N, M;
int ans[MAXN];

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < N;i++) {
        scanf("%d%d", &parts[i].a, &parts[i].b);
        parts[i].d = i;
    }
    scanf("%d", &M);
    int as[MAXM];
    for(int i = 0;i < M;i++) {
        scanf("%d%d%d", &actors[i].a, &actors[i].b, &actors[i].d);
        as[i] = i;
    }
    
    sort(parts, parts + N, [](const TUP& a, const TUP& b){return a.a < b.a;});
    sort(as, as + M, [](const int& a, const int& b){return actors[a].a < actors[b].a;});
    si acts(acmp);
    
    for(int i = 0;i <= M;i++) ans[i] = 0;
    
    for(int i = 0, j = 0;ans[0] != -1 and i < N;i++) {
        while(j < M and actors[as[j]].a <= parts[i].a) acts.insert(as[j++]);
        while(!acts.empty() and actors[*acts.begin()].b < parts[i].a) acts.erase(acts.begin());
        
        actors[M] = parts[i];
        si::iterator s = acts.lower_bound(M);
        
        if(s == acts.end()) ans[0] = -1;
        else {
            ans[parts[i].d] = *s;
            if(--actors[*s].d == 0) acts.erase(s);
        }
    }
    
    if(ans[0] == -1) printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0;i < N;i++) printf("%d ", ans[i] + 1);
        printf("\n");
    }
    
    return 0;
}