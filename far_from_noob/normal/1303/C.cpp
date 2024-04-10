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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>t;
    //t=1;
    while(t--){
        string s;
        cin>>s;
        ll a[26][26];
        fo(i,26)fo(j,26)a[i][j]=0;
        fo(i,s.size()){
            if(i==0);
            else{
                a[s[i]-'a'][s[i-1]-'a']=1;
                a[s[i-1]-'a'][s[i]-'a']=1;
            }
        }
        flag=0;
        ll c1=0,c2=0;
        ll temp;
        ll b[26];
        fo(i,26){
            ll count=0;
            fo(j,26){
                if(a[i][j]==1)count++;
            }
            b[i]=count;
            if(count==1)c1++,temp=i;
            else if(count==2)c2++;
            else if(count>2)flag=1;
        }
        if((flag==1 || c1!=2) &&  s.size()!=1)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            ll last=-1;
            while(s.size()>1){
                char c='a'+temp;
                cout<<c;
                if(b[temp]==1 && last!=-1)break;
                fo(i,26){
                    if(a[temp][i]==1 && i!= last){
                        last= temp;
                        temp=i;
                        break;
                    }
                }   
                
            }
            fo(i,26)if(b[i]==0){char c='a'+i;
                cout<<c; }
            cout<<endl;
        }

        
    }

    return 0;
}