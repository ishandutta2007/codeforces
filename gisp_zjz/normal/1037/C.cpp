#include<bits/stdc++.h>
#define maxn 1123456
#define M 1000000007

using namespace std;
typedef long long ll;
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}
char s[maxn],t[maxn];
int n,ans,f[maxn],o;

int main(){
    cin >> n; cin >> s >> t; o=0;
    for (int i=0;i<n;i++) f[i]=(s[i]=='1')*2+(t[i]=='1');
    for (int i=0;i<n;i++) {
        if (f[i]==0||f[i]==3) o=0;
        else {
            if (o&&f[i]+f[i-1]==3) o=0;
            else o=1,ans++;
        }
    }
    cout << ans << endl;
}