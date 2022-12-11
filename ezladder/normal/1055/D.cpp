#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
string a[3003];
string b[3003];
pair<int, int> t[3003];

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> d;
    for (int i = 0; i < n; i++){
        int l = -1, r = -1;
        for (int j = 0; j < a[i].size(); j++){
            if (a[i][j] != b[i][j]){
                r = j;
                if (l == -1) l = j;
            }
        }
        t[i] = mp(l, r);
        if (l != -1) d.pb(i);
    }
    if (d.size() == 0) assert(0);
    for (int i = 0; i < d.size(); i++) if (t[d[i]].y - t[d[i]].x != t[d[0]].y - t[d[0]].x) cout << "NO", exit(0);
    int len = t[d[0]].y - t[d[0]].x + 1;
    string ans, ans2;
    for (int i = 0; i < len; i++){
        for (int x : d){
            if (a[x][t[x].x + i] != a[d[0]][t[d[0]].x + i] || b[x][t[x].x + i] != b[d[0]][t[d[0]].x + i]) cout << "NO", exit(0);
        }
        ans += a[d[0]][t[d[0]].x + i];
        ans2 += b[d[0]][t[d[0]].x + i];
    }

    for (int it = 1; ; it++){
        bool ok = 1;
        for (int x : d){
            if (t[x].y + it >= a[x].size() || a[d[0]][t[d[0]].y + it] != a[x][t[x].y + it]){
                ok = 0;
                break;
            }
        }
        if (ok){
            ans += a[d[0]][t[d[0]].y + it];
            ans2 += b[d[0]][t[d[0]].y + it];
        } else break;
    }

    reverse(all(ans));
    reverse(all(ans2));

    for (int it = 1; ; it++){
        bool ok = 1;
        for (int x : d){
            if (t[x].x - it < 0 || a[d[0]][t[d[0]].x - it] != a[x][t[x].x - it]){
                ok = 0;
                break;
            }
        }
        if (ok){
            ans += a[d[0]][t[d[0]].x - it];
            ans2 += b[d[0]][t[d[0]].x - it];
        } else break;
    }

    reverse(all(ans));
    reverse(all(ans2));

    for (int i = 0; i < n; i++){
        string tt = ans;
        tt += "#";
        tt += a[i];
        auto now = prefix_function(tt);
        int v = -1;
        for (int j = ans.size() + 1; j < now.size(); j++){
            if (now[j] == ans.size()){
                v = j - ans.size() * 2;
                break;
            }
        }
        if (v != -1){
            if (t[i].x == -1) cout << "NO", exit(0);
            for (int j = 0; j < ans.size(); j++) a[i][v + j] = ans2[j];
            //cout << a[i] << ' ' << b[i] << endl;
            if (a[i] != b[i]) cout << "NO", exit(0);
        }
    }

    cout << "YES\n" << ans << "\n" << ans2;
}