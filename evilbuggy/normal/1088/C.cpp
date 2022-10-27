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
    int n;
    cin>>n;
    int a[n+1];
    cout<<n+1<<endl;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    cout<<"1 "<<n<<" "<<10*n<<endl;
    for(int i = 1; i <= n; i++){
        int x = 10*n + a[i];
        cout<<"2 "<<i<<" "<<x-i<<endl;
    }
}