#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int f[N];
vector < int > v[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        for(int i = 2; i < N; i++){
                if(f[i]){
                        continue;
                }
                for(int j = i; j < N; j += i){
                        if(!f[j]){
                                f[j] = i;
                        }
                }
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                while(x > 1){
                        int p = f[x];
                        int cnt = 0;
                        while(x % p == 0){
                                x /= p;
                                cnt += 1;
                        }
                        v[p].push_back(cnt);
                }
        }
        long long res = 1;
        for(int i = 1; i < N; i++){
                if(v[i].empty()){
                        continue;
                }
                if(v[i].size() < n - 1){
                        continue;
                } else if(v[i].size() == n - 1){
                        v[i].push_back(0);
                }
                sort(v[i].begin(), v[i].end());
                for(int j = 0; j < v[i][1]; j++){
                        res *= i;
                }
        }
        cout << res << "\n";
}