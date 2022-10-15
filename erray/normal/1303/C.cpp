#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 100005
using namespace std;
ll n, t, x, a, b, c;
string s;
map <char, bool> vis;
set <ll> edge[500];
string DFS(char c){
    vis[c] = 1;
    string r = "";
    r += c;
    for(auto  a : edge[c]){
        if (!vis[a]){
            r += DFS(a);
        }
    }
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--){
        cin >> s;
        vis.clear();
        for(int i = 0; i < 500; i++){
                edge[i].clear();
        }
        for(int i = 0; i < s.size() - 1; i++){
            //cout << s[i] << " " << s[i + 1] << ln;
            edge[s[i]].insert(s[i + 1]);
            edge[s[i + 1]].insert(s[i]);
        }

        string ans = "";
        for(int i = 'a';  i <= 'z'; i++){
            if (edge[i].size() == 1 && !vis[i]){
                char cha = i;
                //cout << cha << " ";
                ans += DFS(i);
            }
        }

        for(int i = 'a'; i <= 'z'; i++){
            if (!vis[i]){
                ans += i;
            }
        }
        //cout << ans << ln;

        bool flag = 1;
        for(int i = 0; i < ans.size(); i++){
            vector <ll> v;
            ll b1 = i - 1, b2 = i + 1;
            if (b1 >= 0){
                v.pb(ans[b1]);
            }
            if (b2 < ans.size()){
                v.pb(ans[b2]);
            }
            for(auto a : edge[ans[i]]){
                bool f = 0;
                for(auto a2 : v){
                    if (a == a2){
                        f = 1;
                    }
                }
                if (!f){
                    flag = 0;
                }
            }
        }

        if (flag){
            cout << "YES" << ln << ans << ln;
        }
        else {
            cout << "NO" << ln;
        }


    }
    return 0;
}