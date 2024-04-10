#include <bits/stdc++.h>

using namespace std;

pair<int,int> f[200005], b[200005];

int n,x,y;
string s;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    cin>>s;
    cin>>x>>y;
    
    if(abs(x) + abs(y) > n || (n - abs(x) - abs(y))%2 == 1){
        cout<<-1<<endl;
        exit(0);
    }

    f[0] = make_pair(0,0);
    for(int i = 1; i <= n; i++){
        f[i] = f[i-1];
        if(s[i-1] == 'U'){
            f[i].second++;
        }else if(s[i-1] == 'D'){
            f[i].second--;
        }else if(s[i-1] == 'L'){
            f[i].first--;
        }else{
            f[i].first++;
        }
    }

    b[n+1] = make_pair(x,y);
    for(int i = n; i >= 1; i--){
        b[i] = b[i+1];
        if(s[i-1] == 'U'){
            b[i].second--;
        }else if(s[i-1] == 'D'){
            b[i].second++;
        }else if(s[i-1] == 'L'){
            b[i].first++;
        }else{
            b[i].first--;
        }
    }

    if(b[1].first == 0 && b[1].second == 0){
        cout<<0<<endl;
        exit(0);
    }
    int ans = n;
    for(int i = 1; i <= n; i++){
        int l = i, r = n;
        while(l < r){
            int m = (l+r)/2;
            int diff = abs(b[m+1].first - f[i-1].first) + abs(b[m+1].second - f[i-1].second);
            if(diff <= (m-i+1)){
                r = m;
                ans = min(ans, m-i+1);
            }else{
                l = m+1;
            }
        }
        int diff = abs(b[l+1].first - f[i-1].first) + abs(b[l+1].second - f[i-1].second);
        if(diff <= (l-i+1)){
            ans = min(ans, l-i+1);
        }
    }
    cout<<ans<<endl;
}