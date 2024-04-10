#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+7;

int main () {
    int n, m, tmp; cin>>n>>m; int a[n][m]; ll ans=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            a[i][j]=-1;
        }
    }
    for(int i=0; i<n; i++) {
        cin>>tmp; for(int j=0; j<tmp; j++) a[i][j]=1; if(tmp<m) a[i][tmp]=0;
    }
    for(int i=0; i<m; i++) {
        cin>>tmp; for(int j=0; j<tmp; j++) a[j][i]=a[j][i]==0?2:1; if(tmp<n) a[tmp][i]=a[tmp][i]==1?2:0;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            //cout<<a[i][j]<<" ";
            if(a[i][j]==-1) {
                ans*=2; ans%=N;
            }
            else if(a[i][j]==2) ans=0;
        }
        //cout<<endl;
    }
    cout<<ans;
}