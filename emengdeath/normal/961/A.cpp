#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int a[N];
int n,m,sum;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int ans=0;
    for (int i=1;i<=m;i++){
        int x;
        cin>>x;
        if (!a[x])sum++;
        a[x]++;
        if (sum==n){
            for (int j=1;j<=n;j++){
                a[j]--;
                if (!a[j])sum--;
            }
            ans++;
        }
    }
    cout<<ans;
    return 0;
}