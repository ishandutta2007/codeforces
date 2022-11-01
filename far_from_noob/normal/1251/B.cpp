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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        string s[n];
        fo(i,n)cin>>s[i];
        ll count1=0,count0=0;
        ll c1=0;
        ll siz[n];
        fo(i,n){
            siz[i]=s[i].size();
            if(siz[i]%2==1)c1++;
            //cout<<siz[i];
            fo(j,siz[i]){
                if(s[i][j]=='0')count0++;
                else count1++;
                //cout<<count1<<count0;
            }
        }
        //cout<<count1<<count0;
        sort(siz,siz+n);
        ll count=0;
        if(c1>0||(count1%2==0&&count0%2==0))cout<<n<<endl;
        else cout<<n-1<<endl;
        fo(i,n){
            if(siz[i]%2==0){
                if(min(count0,count1)<siz[i]/2)break;
                else{
                    count++;
                    count0-=siz[i]/2;
                    count1-=siz[i]/2;
                }
            }
            else{
                if(min(count0,count1)<siz[i]/2 || max(count0,count1)<siz[i]/2+1)
                break;
                else{
                    if(count0>count1){
                        count++;
                        count0-=(siz[i]/2+1);
                        count1-=siz[i]/2;
                    }
                    else{
                        count++;
                        count0-=(siz[i]/2);
                        count1-=(siz[i]/2+1);
                    }
                }
            }
        }
        //cout<<count<<endl;
    }

    return 0;
}