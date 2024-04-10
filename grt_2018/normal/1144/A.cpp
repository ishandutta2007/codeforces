#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnt[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>s;
        for(int i=0; i<26;i++) cnt[i]=0;
        for(int i=0; i<s.size();i++)
            cnt[s[i]-'a']++;
        bool ok = 1, alr = 0;
        for(int i=0; i<26;i++) {
            if(cnt[i]>1||(cnt[i]>0&&alr)) {
                ok=0;
            }
            if(i>0&&cnt[i-1]==1&&cnt[i]==0) {
                alr=1;
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}