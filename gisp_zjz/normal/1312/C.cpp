#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[1005],_,n,k;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++){
            ll x; cin >> x;
            int j=0;
            while (x){
                cnt[j]+=x%k; x/=k;
                j++;
            }
        }
        bool flag=1;
        for (int i=0;i<1005;i++) flag&=cnt[i]<=1;
        if (flag) puts("YES"); else puts("NO");
    }
}