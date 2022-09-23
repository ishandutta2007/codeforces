#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int t;
vector < int > v;
pair < pair < int, int >, int > p[N];

bool can(int m)
{
        v.clear();
        int cnt = 0;
        if(m == 0){
                return true;
        }
        for(int i = 1; i <= n; i++){
                if(m <= p[i].fi.se){
                        cnt += p[i].fi.fi;
                        v.push_back(p[i].se);
                }
                if(cnt > t){
                        return false;
                }
                if(v.size() == m){
                        break;
                }
        }
        if(v.size() == m){
                return true;
        }
        return false;
}

void solve()
{
        cin >> n >> t;
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi.se >> p[i].fi.fi;
                p[i].se = i;
        }
        sort(p + 1, p + n + 1);
        int l = 0, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        can(l);
        cout << l << "\n";
        cout << l << "\n";
        for(int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
        }
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