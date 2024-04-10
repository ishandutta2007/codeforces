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
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int mask = 0; mask < (1<<n); mask++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)){
                sum += a[i];
            }else{
                sum -= a[i];
            }
            if(sum >= 360)sum -= 360;
            if(sum < 0)sum += 360;
        }
        if(sum == 0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}