#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,d[N],correct;
ll v1[N],v2[N],e[N],s,s2[N];
vector<ll> rd1[N],rd2[N],ans;
ll mn[N],mx[N],gv1,gv2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<=n;i++) mx[i]=n;
    for(int i=1;i<=n;i++){ cin>>d[i]; s+=d[i]; }
    sort(d+1,d+1+n); reverse(d+1,d+1+n);
    for(int i=1;i<=n;i++) e[d[i]]=i;
    for(int i=n;i>=1;i--) if(!e[i]) e[i]=e[i+1];
    for(int i=1;i<=n+1;i++) s2[i]=s2[i-1]+d[i];
    for(int i=1;i<=n+1;i++) v1[i]=v1[i-1]+d[i];
    for(int i=n+1,j=n+1;i>=1;i--){
        while(j+1<=n+1&&d[j+1]>=i) j++;
        v2[i]+=(ll)i*(j-i);
        v2[i]+=s2[n+1]-s2[j];
        if(i==j) j--;
    }
    for(int i=1;i<=n+1;i++)
        if(v1[i]<=(ll)i*(i-1)+v2[i]) correct++;
    if(correct==n+1&&s%2==0) ans.push_back(0);
    for(int i=1;i<=n;i++){
        if(v1[i]>(ll)i*(i-1)+v2[i]+i)
            rd1[d[i]].push_back(n+1);
        rd1[d[i]].push_back(v1[i]-(ll)i*(i-1)-v2[i]);
        ll pb=v2[i]+(ll)i*(i+1)-v1[i];
        if(e[i+1]>i) pb+=e[i+1]-(ll)i;
        rd2[d[i]+1].push_back(pb);
    }
    for(int deg=n;deg>=1;deg--){
        mn[deg]=mn[deg+1];
        for(auto &it : rd1[deg])
            mn[deg]=max(mn[deg],it);
    }
    for(int deg=1;deg<=n;deg++){
        mx[deg]=mx[deg-1];
        for(auto &it : rd2[deg])
            mx[deg]=min(mx[deg],it);
    }
    for(int deg=1,i=n+1,j=n;deg<=n;deg++){
        while(i-1>=1&&d[i-1]<deg){
            if(j==i-1) j--;
            i--;
        }
        while(j+1<=n&&d[j+1]>=i) j++;
        gv1=s2[i-1]+deg;
        //1~i-1 me i~j j+1~n
        gv2=0;
        gv2+=(ll)i*(j-i+1);
        gv2+=s2[n]-s2[j];
        if(mn[deg]<=deg&&deg<=mx[deg]){
            if(gv1<=(ll)i*(i-1)+gv2&&(s+deg)%2==0){
                ans.push_back(deg);
            }
        }
    }
    if(ans.size()==0) cout<<-1;
    else{
        sort(ans.begin(),ans.end());
        for(auto &it : ans) cout<<it<<" ";
    }
    return 0;
}