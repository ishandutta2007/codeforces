#include <bits/stdc++.h>
using namespace std;
/*
const long long int mod = 1000000007;

long long int modPow(long long int n, long long int p){
    if(p == 0)return 1;
    long long int t = modPow(n, p/2);
    t = (t*t)%mod;
    if(p%2 == 0)return t;
    return (t*n)%mod;
}
*/

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a;
    string s;
    cin>>a>>s;
    int n = s.size();
    map<int,int> arr;
    for(int i = 0; i < n; i++){
        int tmp = s[i]-'0';
        arr[tmp]++;
        for(int j = i+1; j < n; j++){
            tmp += s[j]-'0';
            arr[tmp]++;
        }
    }
    long long int ans = 0;
    if(a == 0){
        ans = 2LL*arr[0]*(1LL*n*(n+1)/2) - 1LL*arr[0]*arr[0];
        cout<<ans<<endl;
        exit(0);
    }
    for(int i = 0; i < s.size(); i++){
        int tmp = s[i]-'0';
        if(tmp != 0 && a%tmp == 0)ans += arr[a/tmp];
        for(int j = i+1; j < s.size(); j++){
            tmp += s[j]-'0';
            if(tmp != 0 && a%tmp == 0)ans += arr[a/tmp];
        }
    }
    cout<<ans<<endl;
}