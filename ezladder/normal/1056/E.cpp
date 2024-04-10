#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int mod;
const int p = 31;

string s1, s2;
int cnt[2];
int h[1000007];
int st[1000007];

bool pr(int x){
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
        return 1;
}

int geth(int l, int r){
    int ans = (h[r + 1] - h[l] * (ll)st[r - l + 1]) % mod;
    if (ans < 0) ans += mod;
    return ans;
}

int main(){
    srand(time(NULL) + 31);
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> kek;
    for (int i = 1e9 + 7; i < 1e9 + 1000; i++) if (pr(i)) kek.pb(i);
    mod = kek[rand() % kek.size()];
    cin >> s1 >> s2;
    for (char c : s1) cnt[c - '0']++;

    st[0] = 1;
    h[0] = 0;
    for (int i = 0; i < s2.size(); i++){
        st[i + 1] = st[i] * (ll)p % mod;
        h[i + 1] = (h[i] * (ll)p + s2[i] - 'a' + 1) % mod;
    }
    int ans = 0;

    for (int len = 1; len < s2.size(); len++){
        ll len2 = (int)s2.size() - len * (ll)cnt[s1[0] - '0'];
        if (len2 <= 0 || len2 % cnt[(s1[0] - '0') ^ 1] != 0) continue;
        len2 /= cnt[(s1[0] - '0') ^ 1];
        if (len * (ll)cnt[s1[0] - '0'] + len2 * (ll)cnt[(s1[0] - '0') ^ 1] != s2.size()) continue;
        int uk = 0;
        bool f = 1;
        int last = -1;
        int fr = geth(0, len - 1);
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] == s1[0]){
                if (geth(uk, uk + len - 1) != fr){
                    f = 0;
                    break;
                }
                uk += len;
            } else {
                if (last == -1){
                    last = geth(uk, uk + len2 - 1);
                }
                if (last != geth(uk, uk + len2 - 1)){
                    f = 0;
                    break;
                }
                uk += len2;
            }
        }
        //cout << len << ' ' << len2 << ' ' << fr << ' ' << last << endl;
        if (last == fr) f = 0;
        ans += f;
    }

    cout << ans;
}