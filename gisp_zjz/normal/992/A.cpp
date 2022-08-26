#include<bits/stdc++.h>
#define maxn 502030

using namespace std;
const int N=100000;
int f[maxn],n,k,ans;

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k;
        f[k+N]=1;
    }
    for (int i=0;i<maxn;i++) if (i!=N) ans+=f[i];
    cout << ans << endl;
}