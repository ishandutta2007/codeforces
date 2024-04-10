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

    int n,x;
    cin>>n;

    int a[n+1], pos[n+1];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }

    int ptr = 1;

    for(int i = 1; i <= n; i++){
        cin>>x;
        if(pos[x] < ptr)cout<<"0 ";
        else{
            cout<<pos[x] - ptr + 1<< " ";
            ptr = pos[x] + 1;
        }
    }

}