#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,ans,p,w;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (p<n){
        p++; w=a[p]; ans++;
        while (p<w) p++,w=max(w,a[p]);
    }
    cout << ans << endl;
}