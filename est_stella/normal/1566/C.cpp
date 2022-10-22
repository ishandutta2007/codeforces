#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int ans = 0;
    for(int i=0, j; i<s.size(); ) {
        if(s[i] + t[i] == '0' + '1') {
            ans += 2;
            i++;
            continue;
        }

        j = i;
        
        while(j < s.size() && s[j] + t[j] != '0' + '1') j++;

        int x = 0;
        for(int k=i; k<j; k++) {
            if(s[k] == '0') {
                if(x == 2) ans+=2, x = 0;
                else x=1, ans++;
            }
            else {
                if(x == 1) ans++, x=0;
                else x = 2;
            }
        }

        i = j;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}