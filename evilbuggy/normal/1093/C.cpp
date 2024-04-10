#include <bits/stdc++.h>
using namespace std;

long long int a[200005], b[100005];

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

    for(int i = 1; i <= n/2; i++){
        cin>>b[i];
    }

    a[1] = 0;
    a[n] = b[1];

    for(int i = 2; i <= n/2; i++){
        if(b[i] == b[i-1]){
            a[i] = a[i-1];
            a[n-i+1] = a[n-i+2];
        }else if(b[i] < b[i-1]){
            a[i] = a[i-1];
            a[n-i+1] = b[i] - a[i];
        }else{
            a[n-i+1] = a[n-i+2];
            a[i] = b[i] - a[n-i+1];
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}