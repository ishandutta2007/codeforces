#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];

int solve_fast()
{
        //cin >> n;
        vector < pair < int, int > > v;
        vector < int > co(n + 1, 0);
        for(int i = 1, j = 1; i <= n; i++){
                //cin >> a[i];
                co[a[i]] += 1;
        }
        for(int i = 1, j = 1; i <= n; i++){
                if(co[i] * 2 - 1 > n){
                        return -1;
                }

                if(i == n || a[i] == a[i + 1]){
                        v.push_back({j, i});
                        j = i + 1;
                }
        }
        vector < int > A(n + 1, 0), B(n + 1, 0);
        int res = (int)v.size() - 1;
        for(auto p: v){
                if(a[p.fi] == a[p.se]){
                        A[a[p.fi]] += 1;
                } else{
                        B[a[p.fi]] += 1;
                        B[a[p.se]] += 1;
                }
        }
        int x = -1;
        int real_shit = 0;
        for(int i = 1; i <= n; i++){
                int C = (int)v.size() - A[i] - B[i];
                int shit = C - (A[i] - 1);
                if(shit < 0){
                        assert(x == -1);
                        x = i;
                        real_shit = - shit;
                }
        }
        int cnt = 0;
        for(auto p: v){
                if(a[p.fi] == x && a[p.se] == x){
                        bool good = false;
                        for(int i = p.fi; i < p.se; i++){
                                if(a[i] != x && a[i + 1] != x){
                                        good = true;
                                }
                        }
                        cnt += good;
                }
        }
        //cout << real_shit << "\n";
        if(real_shit > 0){
                //int g = min(cnt, real_shit / 2);
                res += real_shit;
        }
        return res;
}

int solve_slow()
{
        vector < int > v;
        for(int i = 1; i <= n; i++){
                v.push_back(i);
        }
        int res = -1;
        do{
                int cnt = 0;
                for(int i = 0; i < n - 1; i++){
                        if(abs(v[i] - v[i + 1]) > 1){
                                cnt += 1;
                        }
                        if(a[v[i]] == a[v[i + 1]]){
                                cnt = -1;
                                break;
                        }
                }
                if(cnt != -1){
                        if(res == -1){
                                res = cnt;
                        } else if(cnt < res){
                                res = cnt;
                        }
                }
        }while(next_permutation(v.begin(), v.end()));
        return res;
}

void solve()
{
        cin >> n;
        for(int i= 1; i <= n; i++){
                cin >> a[i];
        }

        /*
        while(solve_fast() == solve_slow()){
                n = rand() % 8 + 1;
                for(int i = 1; i <= n; i++){
                        a[i] = rand() % n + 1;
                }
        }
        */

        //cout << solve_slow() << "\n";
        cout << solve_fast() << "\n";
        //for(int i = 1; i <= n; i++){
        //        cout << a[i] << " ";
        //}

}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}