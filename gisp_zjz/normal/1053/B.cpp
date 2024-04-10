#include<bits/stdc++.h>
#define maxn 423456

using namespace std;
typedef long long ll;
ll a[maxn],ans,d[maxn],s[maxn],n,k,p,q,l,r;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for (int i=1;i<=n;i++) {
        d[i]=0;
        while (a[i]){
            d[i]+=(a[i]&1);
            a[i]>>=1;
        }
        s[i]=s[i-1]+d[i];
    }
    for (int i=0;i<=n;i++) if (s[i]%2==0) p++; else q++;
    ans=p*(p-1)/2+q*(q-1)/2;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=61;j++){
            if (i+j>n) break;
            if (s[i+j]-s[i]>=d[i]) break;
            for (int k=0;k<=61;k++){
                if (i-k<=0) break;
                if (s[i+j]-s[i-k-1]>=d[i]*2) break;
                if (!((s[i+j]-s[i-k-1])&1)) ans--;
            }
        }
    }
    cout << ans << endl;
}