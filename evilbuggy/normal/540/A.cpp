#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    int ans = 0;
    for(int i = 0; i < n; i++){
        a = s[i] - '0', b = t[i] - '0';
        if(a < b){
            ans += min(b-a, 10-b+a);
        }else{
            ans += min(a-b, 10-a+b);
        }
    }
    cout<<ans<<endl;

}