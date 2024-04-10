#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1000005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int n = s.size();
    int cnt = 0, pre = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == 'F'){
            cnt++;
            if(i == 1)a[i] = 0;
            else if(pre == 0)a[i] = i - cnt;
            else if(a[pre] == 0)a[i] = i - cnt;
            else a[i] = max(a[pre] +  1, i - cnt);
            pre = i;
            ans = max(ans, a[i]);
        }
    }
    cout<<ans<<endl;
}