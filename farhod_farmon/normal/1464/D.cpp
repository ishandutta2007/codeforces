#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int mod = 1e9 + 7;

using namespace std;

int solve(vector < int > c)
{
        int res = 0;
        for(int i = 6; i > 3; i--){
                res += c[i];
                c[i - 3] += c[i];
        }
        if(c[1] < c[2]){
                res += c[2];
        } else{
                res += c[1] - (c[1] - c[2]) / 3;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > p(n);
                for(int i = 0; i < n; i++){
                        cin >> p[i];
                        p[i] -= 1;
                }
                vector < int > used(n, 0);
                int need = 0;

                while((n - 2 * need) % 3){
                        need += 1;
                }

                int res = 1, cnt = 0;

                for(int i = 0; i < (n - 2 * need) / 3; i++){
                        res = 1ll * res * 3 % mod;
                }

                if(need == 1){
                        res = 1ll * res * 2 % mod;
                } else if(need == 2){
                        res = 1ll * res * 4 % mod;
                }

                vector < int > c(7, 0);
                for(int i = 0; i < n; i++){
                        if(used[i]){
                                continue;
                        }
                        int l = 1, x = p[i];
                        used[x] = true;
                        while(x != i){
                                l += 1;
                                x = p[x];
                                used[x] = true;
                        }
                        if(l > 6){
                                int g = (l - 4) / 3;
                                cnt += g;
                                l -= 3 * g;
                        }
                        c[l] += 1;
                }

                int best = 3 * n;
                if(!need){
                        best = solve(c);
                }
                vector < int > v;
                for(int i = 1; i < 7; i++){
                        for(int j = i; j < 7; j++){
                                for(int h = j; h < 7; h++){
                                        for(int k = h; k < 7; k++){
                                                v.clear();

                                                bool good = true;
                                                for(int x: {i, j, h, k}){
                                                        if(v.size() == 2 * need){
                                                                break;
                                                        }
                                                        if(c[x]){
                                                                v.push_back(x);
                                                                c[x] -= 1;
                                                        } else{
                                                                good = false;
                                                                break;
                                                        }
                                                }
                                                if(!good){
                                                        for(int x: v){
                                                                c[x] += 1;
                                                        }
                                                        continue;
                                                }
                                                int shit = need;
                                                for(int x: v){
                                                        if(x > 1){
                                                                shit += 1;
                                                                c[x - 1] += 1;
                                                        }
                                                }
                                                best = min(best, shit + solve(c));
                                                for(int x: v){
                                                        if(x > 1){
                                                                c[x - 1] -= 1;
                                                        }
                                                        c[x] += 1;
                                                }
                                        }
                                }
                                if(need == 2){
                                        for(int h = 2; h < 7; h++){
                                                v.clear();
                                                bool good = true;
                                                for(int x: {i, j, h}){
                                                        if(c[x]){
                                                                v.push_back(x);
                                                                c[x] -= 1;
                                                        } else{
                                                                good = false;
                                                                break;
                                                        }
                                                }
                                                if(!good){
                                                        for(int x: v){
                                                                c[x] += 1;
                                                        }
                                                        continue;
                                                }
                                                int shit = 1;
                                                for(int gg = 0; gg < 2; gg++){
                                                        int x = v[gg];
                                                        if(x > 1){
                                                                shit += 1;
                                                                c[x - 1] += 1;
                                                        }
                                                }
                                                for(int x: {v[2]}){
                                                        if(x > 2){
                                                                shit += 1;
                                                                c[x - 2] += 1;
                                                        }
                                                }
                                                best = min(best, shit + solve(c));
                                                for(int x: {v[2]}){
                                                        if(x > 2){
                                                                c[x - 2] -= 1;
                                                        }
                                                        c[x] += 1;
                                                }
                                                for(int gg = 0; gg < 2; gg++){
                                                        int x = v[gg];
                                                        if(x > 1){
                                                                c[x - 1] -= 1;
                                                        }
                                                        c[x] += 1;
                                                }

                                        }
                                        if(j < 3){
                                                continue;
                                        }
                                        v.clear();
                                        bool good = true;
                                        for(int x: {i, j}){
                                                if(c[x]){
                                                        c[x] -= 1;
                                                        v.push_back(x);
                                                } else{
                                                        good = false;
                                                        break;
                                                }
                                        }
                                        if(!good){
                                                for(int x: v){
                                                        c[x] += 1;
                                                }
                                                continue;
                                        }

                                        int shit = 1;
                                        if(i > 1){
                                                shit += 1;
                                                c[i - 1] += 1;
                                        }
                                        if(j > 3){
                                                shit += 1;
                                                c[j - 3] += 1;
                                        }
                                        best = min(best, solve(c) + shit);
                                        if(j > 3){
                                                c[j - 3] -= 1;
                                        }
                                        if(i > 1){
                                                c[i - 1] -= 1;
                                        }
                                        c[j] += 1;
                                        c[i] += 1;
                                }
                        }
                        for(int j = i; j < 7; j++){
                                if(i < 2){
                                        continue;
                                }
                                v.clear();
                                bool good = true;
                                for(int x: {i, j}){
                                        if(v.size() == need){
                                                break;
                                        }
                                        if(c[x]){
                                                v.push_back(x);
                                                c[x] -= 1;
                                        } else{
                                                good = false;
                                                break;
                                        }
                                }
                                if(!good){
                                        for(int x: v){
                                                c[x] += 1;
                                        }
                                        continue;
                                }
                                int shit = 0;
                                for(int x: v){
                                        if(x > 2){
                                                shit += 1;
                                                c[x - 2] += 1;
                                        }
                                }
                                best = min(best, shit + solve(c));
                                for(int x: v){
                                        if(x > 2){
                                                c[x - 2] -= 1;
                                        }
                                        c[x] += 1;
                                }
                        }
                        if(c[i] == 0 || i < 4 || need < 2){
                                continue;
                        }
                        c[i] -= 1;
                        int shit = 0;
                        if(i > 4){
                                c[i - 4] += 1;
                                shit += 1;
                        }
                        best = min(best, solve(c) + shit);
                        if(i > 4){
                                c[i - 4] -= 1;
                        }
                        c[i] += 1;
                }
                cout << res << " " << cnt + best << "\n";
        }

}