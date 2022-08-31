#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=234556;
ll a[maxn],cnt,n,ans;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        bool flag=0;
        for (int j=1;j<i;j++)
            if (a[i]%a[j]==0) flag=1;
        if (!flag) ++ans;
    }
    cout << ans << endl;
}