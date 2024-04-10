#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, s;
    cin>>s;
    bool ans = false;
    for(int i = 0; i < 5; i++){
        cin>>t;
        if(t[0] == s[0] || t[1] == s[1])ans = true;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}