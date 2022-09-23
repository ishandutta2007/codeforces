#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int n;
string I = "";
pair < int, int > a[N];

vector < string > solve(int i)
{
        vector < string > res;
        if(i > n){
                return res;
        } else if(i == n - 1){
                res.push_back(I);
                if(a[i].fi == 1){
                        (res.back())[a[i].se] = '1';
                        a[i].fi -= 1;
                }
                return res;
        } else if(a[i].fi == n - i){
                res.push_back(I);
                for(int j = i; j < n; j++){
                        (res.back())[a[j].se] = '1';
                }
                for(int h = 0; h < n - i; h++){
                        res.push_back(res.back());
                }
                for(int j = i; j < n; j++){
                        res[j - i + 1][a[j].se] = '0';
                }
                return res;
        }
        res.push_back(I);
        for(int j = i; j < n; j++){
                (res.back())[a[j].se] = '1';
                a[j].fi -= 1;
                if(a[j].fi == 0 && j > i){
                        a[j].fi += 1;
                        (res.back())[a[j].se] = '0';
                }
        }
        if(a[i].fi == 0){
                while(i < n && a[i].fi == 0){
                        i += 1;
                }
                auto shit = solve(i);
                for(auto p: shit){
                        res.push_back(p);
                }
                return res;
        }

        auto shit = solve(i + 1);
        reverse(shit.begin(), shit.end());
        for(int j = 0; j < a[i].fi; j++){
                shit[j][a[i].se] = '1';
        }
        a[i].fi = 0;
        for(auto s: shit){
                res.push_back(s);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > v;
        for(int i = 0; i < n; i++){
                cin >> a[i].fi;
                a[i].se = i;
                I += '0';
        }
        sort(a, a + n);
        auto res = solve(0);
        cout << res.size() << "\n";
        for(auto s: res){
                cout << s << "\n";
        }
}