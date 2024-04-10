#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+6;
int phi[maxn],n,ans,f[maxn];
char s[maxn];
int main(){
    for (int i=1;i<maxn;i++) phi[i]=i;
    for (int i=1;i<maxn;i++) for (int j=2;j*i<maxn;j++) phi[i*j]-=phi[i];
    cin >> n >> s;
    for (int i=0;i<n;i++) f[i]=s[i]-'0';
    for (int i=1;i<=n;i++) if (n%i==0){
        bool flag=0;
        for (int j=0;j<i;j++){
            bool o=0;
            for (int k=0;k<n/i;k++) o^=f[k*i+j];
            flag|=o;
        }
        if (!flag) ans+=phi[n/i];
    }
    cout << ans << endl;
}