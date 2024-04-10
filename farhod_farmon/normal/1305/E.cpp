#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;
const int Q = 400200;

using namespace std;

int n;
int c[N];
int s[N];
bool used[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int k;
        cin >> n >> k;
        int able = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(i + j <= n){
                                //c[i] += 1;
                                //c[j] += 1;
                                //v[i + j].insert({i, j});

                                able += 1;
                                s[i + j] += 1;
                        }
                }
        }
        if(able < k){
                cout << -1 << "\n";
                return 0;
        }
        int last = 0;
        for(int i = 1; i <= n; i++){
                s[i] += s[i - 1];
                if(s[i] >= k){
                        last = i - 1;
                        break;
                }
        }

        k -= s[last];
        vector < int > res;
        for(int i = 1; i <= last; i++){
                res.push_back(i);
                used[i] = true;
        }
        while(k > 0){
                for(int i = 0; i < res.size(); i++){
                        for(int j = i + 1; j < res.size(); j++){
                                if(!used[res[i] + res[j]]){
                                        c[res[i] + res[j]] += 1;
                                }
                        }
                }
                int last = res.back() * 2;
                int best = 1;
                for(int i = 1; i <= last; i++){
                        if(c[i] <= k && c[i] > c[best]){
                                best = i;
                        }
                }
                used[best] = 1;
                k -= c[best];
                res.push_back(best);
                for(int i = 1; i <= last; i++){
                        c[i] = 0;
                }
        }
        assert((int)res.size() <= n);
        for(int &x: res)x *= n;
        int shit = 1e8;
        while(res.size() < n){
                res.push_back(shit++);
        }

        sort(res.begin(), res.end());
        for(int x: res){
                cout << x << ' ';
        }
}