#include<bits/stdc++.h>
#define maxn 2020300

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],c[maxn],d,r,n,s,id,ans;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i]-=i,s+=abs(a[i]); id=0;ans=s;
    for (int i=1;i<=n;i++){
        r=min(a[i],n-i+1);
        if (r>0) {
            c[1]++,c[r+1]--;
        }
    }
    for (int i=1;i<n;i++){
        r=a[n-i+1]+n-i;
        c[i+1]++,c[i+1+r]--;
    }
    for (int i=1;i<n;i++){
        d+=c[i];
        s+=(a[n-i+1]+n-i-d)*2;
        if (s<ans) id=i,ans=s;
    }
    cout << ans << ' ' << id << endl;
    return 0;
}