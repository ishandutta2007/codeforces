#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1000000000000LL;
ll resp[100010];

struct v {
    ll x, y, id;
    ll ml, mr;
    v *l, *r;

    v(ll x, ll y, ll id) : x(x), y(y), id(id) {}
    v(ll x, ll y, v *l, v *r, ll ml, ll mr) :
        x(x), y(y), id(-1), l(l), r(r), ml(ml), mr(mr) {}

    ll m() {
        return (x*x + y*y);
    }

    void calc(ll mult) {
        if(id != -1) {
            resp[id] = mult;
            return;
        }

        l->calc(mult * ml);
        r->calc(mult * mr);
    }
};

v* PP(v *a, v *b) {
    return new v(a->x + b->x, a->y + b->y, a, b, 1, 1);
}

v* PN(v *a, v *b) {
    return new v(a->x - b->x, a->y - b->y, a, b, 1, -1);
}

v* NP(v *a, v *b) {
    return new v(- a->x + b->x, - a->y + b->y, a, b, -1, 1);
}

v* NN(v *a, v *b) {
    return new v(- a->x - b->x, - a->y - b->y, a, b, -1, -1);
}

queue<v*> vs;

int main() {
    ll n, x, y;
    scanf("%lld", &n);

    for(ll i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        vs.push(new v(x, y, i));
    }

    while(vs.size() > 2) {
        v *a = vs.front(); vs.pop();
        v *b = vs.front(); vs.pop();
        v *c = vs.front(); vs.pop();
        v *d;

        if(PP(a, b)->m() <= INF) {
            d = PP(a, b);
            vs.push(c);
        } else if(PN(a, b)->m() <= INF) {
            d = PN(a, b);
            vs.push(c);
        } else if(PP(a, c)->m() <= INF) {
            d = PP(a, c);
            vs.push(b);
        } else if(PN(a, c)->m() <= INF) {
            d = PN(a, c);
            vs.push(b);
        } else if(PP(b, c)->m() <= INF) {
            d = PP(b, c);
            vs.push(a);
        } else if(PN(b, c)->m() <= INF) {
            d = PN(b, c);
            vs.push(a);
        } else assert(false);

        vs.push(d);
    }

    if(vs.size() == 2) {
        v *a = vs.front(); vs.pop();
        v *b = vs.front(); vs.pop();
        v *d;

        if(PP(a, b)->m() <= INF + INF/2) {
            d = PP(a, b);
        } else if(PN(a, b)->m() <= 2.25*INF) {
            d = PN(a, b);
        } else assert(false);

        vs.push(d);
    }

    vs.front()->calc(1);
    assert(vs.front()->m() <= 2.25*INF);

    for(int i = 0; i < n; i++) {
        printf("%d ", resp[i]);
    }

    return 0;
}