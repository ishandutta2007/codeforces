#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
char s[maxn],t[maxn];
ll l,r,k,n,ans,d,w;

int main(){
    cin >> n >> k;
    cin >> s >> t;
    for (int i=0;i<n;i++){
        l=l*2+s[i]-'0';
        r=r*2+t[i]-'0';
        w=min(r-l+1-d,k);
        ans+=w*(n-i);
        k-=w; d+=w;
        if (!k) break;
    }
    cout << ans << endl;
}