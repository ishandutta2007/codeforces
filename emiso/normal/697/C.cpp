#include <bits/stdc++.h>

#define MP(a,b) make_pair(a,b)

using namespace std;

typedef long long ll;

map<pair<ll,ll>,ll> fee;

void update(ll u, ll w) {

    if(fee.find(MP(u/2,u)) == fee.end())
        fee.insert(MP(MP(u/2,u),w));

    else fee[MP(u/2,u)] += w;
}

ll query(ll u) {
    if(fee.find(MP(u/2,u)) == fee.end())
        return 0;

    else return fee[MP(u/2,u)];
}

int main() {
    int n;
    ll t,v,u,w;

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%lld %lld %lld",&t,&v,&u);

        if(v > u) swap(v,u);

        int hv=0, hu=0;

        for(ll i = u; i > 0; i/=2,hu++);
        for(ll i = v; i > 0; i/=2,hv++);

        ll ans = 0;

        if(t == 1) {
            scanf("%lld",&w);

            while(hv != hu) {
                if(u != 1) {
                    update(u,w);
                    hu--;
                    u /= 2;
                }
            }


            while(v != u) {
                if(u != 1) {
                    update(u,w);
                    hu--;
                    u /= 2;
                }
                if(v != 1) {
                    update(v,w);
                    hv--;
                    v /= 2;
                }
            }
        }
        else {
            while(hv != hu) {
                if(u != 1) {
                    ans += query(u);
                    hu--;
                    u /= 2;
                }
            }

            while(v != u) {
                if(u != 1) {
                    ans += query(u);
                    hu--;
                    u /= 2;
                }

                if(v != 1) {
                    ans += query(v);
                    hv--;
                    v /= 2;
                }
            }

            printf("%lld ",ans);
        }
    }
    printf("\n");
    return 0;
}