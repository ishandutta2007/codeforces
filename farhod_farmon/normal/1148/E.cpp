#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int b[N];
pair < int, int > a[N];

vector < pair < pair < int, int >, int > > res;

void upd(int x, int y, int d)
{
        res.push_back({{a[x].se, a[y].se}, d});
        a[x].fi += d;
        a[y].fi -= d;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        vector < int > v;
        for(int i = 1; i <= n; i++){
                a[i].fi -= b[i];
                if(a[i].fi > 0){
                        while(!v.empty() && a[i].fi > 0){
                                int g = min(a[i].fi, - a[v.back()].fi);
                                upd(v.back(), i, g);
                                if(a[v.back()].fi == 0){
                                        v.pop_back();
                                }
                        }
                        if(a[i].fi){
                                cout << "NO" << "\n";
                                return 0;
                        }
                } else if(a[i].fi < 0){
                        v.push_back(i);
                }
        }
        if(!v.empty()){
                cout << "NO" << "\n";
                return 0;
        }
        cout << "YES" << "\n";
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi.fi << " " << p.fi.se << " " << p.se << "\n";
        }
}