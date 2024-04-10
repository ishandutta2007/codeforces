#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
const long long mod=1e9+7;
long long f[N],help[N];
int ans[N];
string s;
int n;
long long get(int l,int r){
    return (f[r]-f[l-1]*help[r-l+1]%mod+mod)%mod;
}
bool check(int len,int midl,int midr){
    return get(midl-len+1,midl+len-1)==get(midr-len+1,midr+len-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    help[0]=1;
    for (int i=1;i<=n;i++)help[i]=help[i-1]*26%mod;
    for (int i=1;i<=n;i++)
        f[i]=(f[i-1]*26+s[i-1]-'a')%mod;
    for (int i=1;i<=(n+1)/2;i++){
        int midl=i,midr=n-i+1;
        if (get(midl,midl)!=get(midr,midr)||midl==midr){
            ans[i]=-1;
        }else{
            int l=1,r=i,mid,s=1;
            while (l<=r){
                if (check(mid=(l+r)/2,midl,midr))l=mid+1,s=max(mid,s);
                else
                    r=mid-1;
            }
            ans[i-s+1]=max(s*2-1,ans[i-s+1]);
        }
    }
    for (int i=1;i<=(n+1)/2;i++){
        ans[i]=max(ans[i-1]-2,ans[i]);
        cout<<ans[i]<<' ';
    }
    return 0;
}