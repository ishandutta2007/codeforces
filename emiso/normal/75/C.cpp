#include <bits/stdc++.h>

using namespace std;

vector<int> div_[2], in(100010);
set<int> adiv[2];

int x, y, n, l, r;

void prep(int x, int id) {
    int aux = x, i = 2;
    while(i * i <= x) {
        if(aux % i == 0) div_[id].push_back(i);
        while(aux % i == 0) aux /= i;
        i++;
    }

    if(aux > 1) div_[id].push_back(aux);
}

void gen_div(int val, int dv, int id, int x) {
    adiv[id].insert(val);
    if(dv == div_[id].size()) return;

    int mult = 1, prime = div_[id][dv];
    while(x % mult == 0) {
        gen_div(val * mult, dv + 1, id, x);
        mult *= prime;
    }
}

void intersec() {
    in.resize
       (set_intersection(adiv[0].begin(),
           adiv[0].end(), adiv[1].begin(), adiv[1].end(), in.begin()) - in.begin());
}

int query(int l, int r) {
    int elem = upper_bound(in.begin(), in.end(), r) - in.begin();
    if(in[--elem] < l) return -1;
    return in[elem];
}

int main() {
    scanf("%d %d %d", &x, &y, &n);

    prep(x, 0);
    gen_div(1, 0, 0, x);

    prep(y, 1);
    gen_div(1, 0, 1, y);

    intersec();

    for(int i=0;i<n;i++) {
       scanf("%d %d", &l, &r);
       printf("%d\n", query(l, r));
    }
    return 0;
}