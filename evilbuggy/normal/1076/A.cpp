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

    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i+1]){
            if(i == 0)cout<<s.substr(1)<<endl;
            else cout<<s.substr(0, i)<<s.substr(i+1)<<endl;
            return 0;
        }
    }
    cout<<s.substr(0, n-1)<<endl;
}