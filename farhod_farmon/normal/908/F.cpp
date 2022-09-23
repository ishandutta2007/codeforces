#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
long long ans;
deque < pair < int, char > > a;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                char c;
                cin >> x >> c;
                a.push_back({x, c});
        }
        int lr = 0, lb = 0;
        for(int i = 0; i < n; i++){
                if(a[i].se == 'G'){
                        if(lr) ans += a[i].fi - lr;
                        if(lb) ans += a[i].fi - lb;
                        while(i){
                                a.pop_front();
                                i--;
                        }
                        break;
                }
                else if(a[i].se == 'R'){
                        if(lr) ans += a[i].fi - lr;
                        lr = a[i].fi;
                }
                else{
                        if(lb) ans += a[i].fi - lb;
                        lb = a[i].fi;
                }
        }
        if(a[0].se != 'G'){
                a.clear();
        }
        n = a.size(); lr = lb = 0;
        for(int i = n - 1; i >= 0; i--){
                if(a[i].se == 'G'){
                        if(lr) ans += lr - a[i].fi;
                        if(lb) ans += lb - a[i].fi;
                        while(i < n - 1){
                                a.pop_back();
                                i++;
                        }
                        break;
                }
                else if(a[i].se == 'R'){
                        if(lr) ans += lr - a[i].fi;
                        lr = a[i].fi;
                }
                else{
                        if(lb) ans += lb - a[i].fi;
                        lb = a[i].fi;
                }
        }
        if(!a.empty() && a.back().se != 'G'){
                a.clear();
        }
        n = a.size(); lr = lb = 0;
        for(int i = 1; i < n; i++){
                if(a[i].se == 'G'){
                        ans += a[i].fi - a[i - 1].fi;
                        continue;
                }
                lr = lb = 0;
                int fr = 0, fb = 0, j = i, bestr = 0, bestb = 0;
                while(a[j].se != 'G'){
                        if(a[j].se == 'R'){
                                if(lr) bestr = max(bestr, a[j].fi - lr);
                                else bestr = max(bestr, a[j].fi - a[i - 1].fi);
                                lr = a[j].fi;
                                fr = 1;
                        }
                        else{
                                if(lb) bestb = max(bestb, a[j].fi - lb);
                                else bestb = max(bestb, a[j].fi - a[i - 1].fi);
                                lb = a[j].fi;
                                fb = 1;
                        }
                        j++;
                }
                if(lr) bestr = max(bestr, a[j].fi - lr);
                if(lb) bestb = max(bestb, a[j].fi - lb);
                long long f1 = 1ll * (fr + fb + 1) * (a[j].fi - a[i - 1].fi) - bestb - bestr;
                long long f2 = 1ll * (fr + fb) * (a[j].fi - a[i - 1].fi);
                if(fb + fr == 2) ans += min(f1, f2);
                else ans += f1;
                i = j;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}