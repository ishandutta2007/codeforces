#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

stack<int> s;
int a[100005], d[100005];

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
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        int cnt = 0;
        while(!s.empty() && a[s.top()] < a[i]){
            cnt = max(cnt, d[s.top()]);
            s.pop();
        }
        if(s.empty())d[i] = 1e9;
        else if(cnt > 1e9)d[i] = 1e9;
        else ans = max(ans, (d[i] = cnt + 1));
        s.push(i);
        // cout<<d[i]<<endl;
    }
    cout<<ans<<endl;
}