#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string s;
    int cnt[26];
    cin>>t;
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        cin>>s;
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']++;
        }
        int tmp = 0;
        for(int i = 0; i < 26; i++){
            tmp += (cnt[i] > 0);
        }
        if(tmp == 1){
            cout<<-1<<endl;
        }else{
            sort(s.begin(), s.end());
            cout<<s<<endl;
        }
    }
}