#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,k,cnt[26];
char s[205];
void solve(){
    cin >> n >> k >> s;
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;i++) cnt[s[i]-'a']++;
    for (int i=0;i<k;i++){
        int pos=0;
        for (int j=0;j<n/k;j++){
            if (cnt[pos]) cnt[pos]--,pos++; else break;
        }
        cout << (char)('a'+pos);
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}