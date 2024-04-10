#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n[3];
ll a[3][1234567],sum[3],mn[3],S;

int main(){
    cin >> n[0] >> n[1] >> n[2];
    for (int i=0;i<3;i++){
        for (int j=0;j<n[i];j++) cin >> a[i][j];
        mn[i]=sum[i]=a[i][0];
        for (int j=1;j<n[i];j++){
            sum[i]+=a[i][j];
            mn[i]=min(a[i][j],mn[i]);
        }
    }
    sort(sum,sum+3);
    sort(mn,mn+3);
    cout << max(sum[1]+sum[2]-sum[0],sum[0]+sum[1]+sum[2]-2*(mn[0]+mn[1])) << endl;
}