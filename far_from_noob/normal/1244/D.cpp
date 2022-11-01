#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
vector<ll>v[100005];
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
        ll p,w,d;
        ll p1[n],p2[n],p3[n];
        fo(i,n)cin>>p1[i];
        fo(i,n)cin>>p2[i];
        fo(i,n)cin>>p3[i];
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        fo1(i,n)if(v[i].size()>2){cout<<-1;return 0;}
        ll temp=1,temp1=1;
        fo1(i,n)if(v[i].size()==1)temp=i;
        //cout<<temp<<endl;
        ll pp=temp;
        ll ans=10000000000000000;
        ll val[n+1],tval[n+1];
        temp1=temp;
        k=0;
        ll sum=0;
        while(k==0|| v[temp].size()!=1){
            //123
            if(k%3==0)sum+=p1[temp-1],tval[temp]=1;
            if(k%3==1)sum+=p2[temp-1],tval[temp]=2;
            if(k%3==2)sum+=p3[temp-1],tval[temp]=3;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p1[temp-1],tval[temp]=1;
        if(k%3==1)sum+=p2[temp-1],tval[temp]=2;
        if(k%3==2)sum+=p3[temp-1],tval[temp]=3;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        //cout<<ans;
        k=0;
        temp=pp,temp1=pp,sum=0;
        while(k==0|| v[temp].size()!=1){
            //132
            if(k%3==0)sum+=p1[temp-1],tval[temp]=1;
            if(k%3==1)sum+=p3[temp-1],tval[temp]=3;
            if(k%3==2)sum+=p2[temp-1],tval[temp]=2;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p1[temp-1],tval[temp]=1;
        if(k%3==1)sum+=p3[temp-1],tval[temp]=3;
        if(k%3==2)sum+=p2[temp-1],tval[temp]=2;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        //cout<<ans;
         k=0;
        temp=pp,temp1=pp,sum=0;
        while(k==0|| v[temp].size()!=1){
            //231
            if(k%3==0)sum+=p2[temp-1],tval[temp]=2;
            if(k%3==1)sum+=p3[temp-1],tval[temp]=3;
            if(k%3==2)sum+=p1[temp-1],tval[temp]=1;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p2[temp-1],tval[temp]=2;
        if(k%3==1)sum+=p3[temp-1],tval[temp]=3;
        if(k%3==2)sum+=p1[temp-1],tval[temp]=1;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        //cout<<ans;
         k=0;
        temp=pp,temp1=pp,sum=0;
        while(k==0|| v[temp].size()!=1){
            //312
            if(k%3==0)sum+=p3[temp-1],tval[temp]=3;
            if(k%3==1)sum+=p1[temp-1],tval[temp]=1;
            if(k%3==2)sum+=p2[temp-1],tval[temp]=2;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p3[temp-1],tval[temp]=3;
        if(k%3==1)sum+=p1[temp-1],tval[temp]=1;
        if(k%3==2)sum+=p2[temp-1],tval[temp]=2;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        //cout<<ans;
        k=0;
        temp=pp,temp1=pp,sum=0;
        while(k==0|| v[temp].size()!=1){
            //321
            if(k%3==0)sum+=p3[temp-1],tval[temp]=3;
            if(k%3==1)sum+=p2[temp-1],tval[temp]=2;
            if(k%3==2)sum+=p1[temp-1],tval[temp]=1;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p3[temp-1],tval[temp]=3;
        if(k%3==1)sum+=p2[temp-1],tval[temp]=2;
        if(k%3==2)sum+=p1[temp-1],tval[temp]=1;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        //cout<<ans;
        k=0;
        temp=pp,temp1=pp,sum=0;
        while(k==0|| v[temp].size()!=1){
            //213
            if(k%3==0)sum+=p2[temp-1],tval[temp]=2;
            if(k%3==1)sum+=p1[temp-1],tval[temp]=1;
            if(k%3==2)sum+=p3[temp-1],tval[temp]=3;
            if(v[temp][0]==temp1){
                temp1=temp;temp=v[temp][1];
            }
            else{
                temp1=temp;temp=v[temp][0];
            }
            k++;
        }
        if(k%3==0)sum+=p2[temp-1],tval[temp]=2;
        if(k%3==1)sum+=p1[temp-1],tval[temp]=1;
        if(k%3==2)sum+=p3[temp-1],tval[temp]=3;
        if(ans>sum)fo1(i,n)val[i]=tval[i];
        ans=min(ans,sum);
        cout<<ans<<endl;
        fo1(i,n)cout<<val[i]<<" ";
        
    
    }

    return 0;
}