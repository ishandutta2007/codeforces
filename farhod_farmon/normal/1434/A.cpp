#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600100;

using namespace std;

int n;
int a[6];
int b[N];
int c[N];
int cnt;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        for(int i = 0; i < 6; i++){
                cin >> a[i];
        }
        cin >> n;
        vector < pair < int, int > > v;
        for(int i = 0; i < n; i++){
                cin >> b[i];
                for(int j = 0; j < 6; j++){
                        v.push_back({b[i] - a[j], i});
                }
        }
        sort(v.begin(), v.end());
        int res = 2e9;
        for(int i = 0, j = -1; i < v.size(); i++){
                while(cnt < n && j + 1 < v.size()){
                        j += 1;
                        cnt += c[v[j].se] == 0;
                        c[v[j].se] += 1;
                }
                if(cnt < n){
                        break;
                }
                res = min(res, v[j].fi - v[i].fi);
                c[v[i].se] -= 1;
                cnt -= c[v[i].se] == 0;
        }
        cout << res << "\n";
}