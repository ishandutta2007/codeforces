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
        string s1,s2,s3,s4;
        
        cin>>s1>>s2;
        s3=s1;
        s4=s2;
        map<ll,ll>m1;
        map<ll,ll>m2;
        fo(i,n)m1[s1[i]-'a']++;
        fo(i,n)m1[s2[i]-'a']++;
        flag=0;
        fo(i,26){
            if(m1[i]%2==0);
            else flag=1;
        }
        ll ans=0;
        if(flag==1)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            fo(i,n){
                ll kk=0;
                if(s1[i]==s2[i])kk=1;
                if(kk==0)for(int j=i+1;j<n;j++){
                    if(s1[j]==s1[i]){
                        s1[j]=s2[i];
                        ans++;
                        kk=1;
                        break;
                    }
                }
                if(kk==0)for(int j=i;j<n;j++){
                    if(s1[i]==s2[j]){
                        s2[j]=s1[n-1];
                        s1[n-1]=s2[i];
                        ans+=2;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
            s1=s3;s2=s4;
            fo(i,n){
                ll kk=0;
                if(s1[i]==s2[i])kk=1;
                if(kk==0)for(int j=i+1;j<n;j++){
                    if(s1[j]==s1[i]){
                        s1[j]=s2[i];
                        cout<<j+1<<" "<<i+1<<endl;
                        kk=1;
                        break;
                    }
                }
                if(kk==0)for(int j=i;j<n;j++){
                    if(s1[i]==s2[j]){
                        s2[j]=s1[n-1];
                        s1[n-1]=s2[i];
                        ans+=2;
                        cout<<n<<" "<<j+1<<endl;
                        cout<<n<< " "<<i+1<<endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}