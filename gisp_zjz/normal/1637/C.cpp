#include<bits/stdc++.h>
using namespace std;
int _,n,a[1000005];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        if (n==3&&a[2]%2==1){puts("-1");continue;}
        long long sum=0;
        bool flag=0;
        for (int i=2;i<n;i++){
            sum+=(a[i]+1)/2;
            flag|=a[i]>1;
        }
        if (!flag) puts("-1"); else cout << sum << endl;
    }
    return 0;
}