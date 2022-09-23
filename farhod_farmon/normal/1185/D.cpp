#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
pair < int, int > a[N];

int get(int d, int st, int shit)
{
        vector < int > res;
        if(shit){
                res.push_back(a[shit].se);
        }
        for(int i = st + 1; i <= n; i++){
                if(a[i].fi - a[st].fi == d){
                        st = i;
                } else{
                        res.push_back(a[i].se);
                }
        }
        if(res.size() > 1){
                return -1;
        } else if(res.size() == 1){
                return res[0];
        } else{
                return a[n].se;
        }
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
        if(n == 2){
                cout << 1 << "\n";
                return 0;
        }
        sort(a + 1, a + n + 1);
        vector < int > res;
        res.push_back(get(a[2].fi - a[1].fi, 1, 0));
        res.push_back(get(a[3].fi - a[2].fi, 2, 1));
        res.push_back(get(a[3].fi - a[1].fi, 1, 0));

        for(int x: res){
                if(x != -1){
                        cout << x << "\n";
                        return 0;
                }
        }

        cout << -1 << "\n";
}