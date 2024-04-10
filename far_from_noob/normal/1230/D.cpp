#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a[n],b[n];
        fo(i,n)cin>>a[i];
        fo(i,n)cin>>b[i];
        vector<ll>v[n];
        fo(i,n){
            ll kk=a[i];
            for(int j=59;j>=0;j--){
                if(a[i]/(ll)pow(2,j) ==1){
                    v[i].push_back(j);
                    a[i] = a[i] - (ll)pow(2,j);
                }
            }
            a[i]=kk;
        }
        ll sum=0;
        ll c[n];
        fo(i,n)c[i]=0;
        pair<ll,ll>p[n];
        fo(i,n)p[i]=make_pair(a[i],i);
        sort(p,p+n);
        ll pro[60];
        fo(i,60)pro[i]=0;
        ll ifused[n];
        fo(i,n)ifused[i]=0;
        ll temp=p[n-1].first;
        ll count=1;
        sum+=b[p[n-1].second];
        //cout<<sum<<endl;
        for(int i=n-2;i>=0;i--){
            if(p[i].first==temp)count++,sum+=b[p[i].second];
            else {
                if(count==1){
                    ll j = p[i+1].second,f=0;
                    fo(l,n){
                        if(ifused[l]==1){
                            ll len=0;
                            fo(h,v[l].size()){
                                if(v[l][h]==v[j][len])len++;
                                if(len==v[j].size())break;
                            }
                            if(len==v[j].size()){f=1;break;}
                        }
                    }
                    if(f==0)sum-=b[p[i+1].second];
                    //out<<sum<<endl<<endl;
                }
                else {
                    ifused[p[i+1].second]=1;
                }
                
                temp=p[i].first;
                sum+=b[p[i].second];
                count=1;
            }
            //cout<<sum<<endl;
        }
        if(count==1){
            if(p[0].first==0){
                if(sum==b[p[0].second]){cout<<0;return 0;}
                
            }
            ll j = p[0].second,f=0;
                    fo(l,n){
                        if(ifused[l]==1){
                            ll len=0;
                            fo(h,v[l].size()){
                                if(v[l][h]==v[j][len])len++;
                                if(len==v[j].size())break;
                            }
                            if(len==v[j].size()){f=1;break;}
                        }
                    }
                    if(f==0)sum-=b[p[0].second];
        }
        
        cout<<sum;
        
    }

    return 0;
}