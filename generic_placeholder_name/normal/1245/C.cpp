#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+7;

ll f[100002];

void init(int n) {
    f[0]=1; f[1]=1;
    for (int i=2; i<=n+1; i++) f[i]=(f[i-1]+f[i-2])%N;
}

ll solve(string s) {
    for(int i=0; i<s.length(); i++) if(s[i]=='m'||s[i]=='w') return 0;
    int cnt=1; ll ans=1;
    for(int i=1; i<s.length(); i++) {
        if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n')) cnt++;
        else {
            (ans*=f[max(0, cnt)])%=N; cnt=(s[i]=='u'||s[i]=='n')?1:-10000000;
        }
    }
    (ans*=f[max(0, cnt)])%=N;
    return ans;
}

int32_t main() {
    string s; cin>>s; init(s.length()); cout<<solve(s);
}