#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const long long mod = 998244353;

using namespace std;

int n;
int p[N];
int d[N];
map < int, int > id;

int f(int x)
{
        if(id.find(x) != id.end()){
                return id[x];
        }
        n++;
        id[x] = n;
        p[n] = n;
        return n;
}

pair < int, int > get(int x)
{
        if(p[x] == x){
                return {0, x};
        }
        auto g = get(p[x]);
        p[x] = g.se;
        g.fi ^= d[x];
        d[x] = g.fi;
        return g;
}

void solve()
{
        int q;
        int last = 0;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int t, l, r, x;
                cin >> t;
                if(t == 1){
                        cin >> l >> r >> x;
                        l ^= last;
                        r ^= last;
                        x ^= last;
                        if(l > r){
                                swap(l, r);
                        }
                        //cout << l << " " << r << endl;
                        l--;
                        l = f(l);
                        r = f(r);
                        auto a = get(l);
                        auto b = get(r);
                        if(a.se != b.se){
                                p[a.se] = b.se;
                                d[a.se] = x ^ a.fi ^ b.fi;
                        }
                }
                else{
                        cin >> l >> r;
                        l ^= last;
                        r ^= last;
                        if(l > r){
                                swap(l, r);
                        }
                        //cout << l << " " << r << endl;
                        l--;
                        l = f(l);
                        r = f(r);
                        auto a = get(l);
                        auto b = get(r);
                        if(a.se != b.se){
                                last = 1;
                                cout << -1 << "\n";
                        }
                        else{
                                last = a.fi ^ b.fi;
                                cout << last << "\n";
                        }
                }
        }

}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int test = 1;
        while(test--){
                solve();
        }
}