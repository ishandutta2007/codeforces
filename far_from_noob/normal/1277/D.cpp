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
        cin>>n;
        string s[n];
        ll c00=0,c11=0,c10=0,c01=0;
        vector<ll>v01,v10;
        map<string ,ll>m1;
        fo(i,n){
            cin>>s[i];
            if(s[i][0]=='0'&&s[i][s[i].size()-1]=='0')c00++;
            if(s[i][0]=='0'&&s[i][s[i].size()-1]=='1')c01++,m1[s[i]]++,v01.pb(i);
            if(s[i][0]=='1'&&s[i][s[i].size()-1]=='0')c10++,m1[s[i]]++,v10.pb(i);
            if(s[i][0]=='1'&&s[i][s[i].size()-1]=='1')c11++;
        }
        //cout<<c10<<c01<<c00<<c11<<endl;
        if(c10+c01==0){
            if(c11>0&&c00>0){cout<<-1<<endl;}
            else cout<<0<<endl;
            continue;
        }
        else{
            vector<ll>ans;
            if(abs(c01-c10)<=1){
                cout<<0<<endl<<endl;
            continue;
            }
            if(c01>c10)fo(i,v01.size()){
                //cout<<"ff ";
                reverse(all(s[v01[i]]));
                //fo(j,s[v01[i]].size())cout<<s[v01[i]][j];
                if(m1[s[v01[i]]]==1);
                else{
                    c01--;
                    c10++;
                    ans.pb(v01[i]+1);
                }
                if(abs(c01-c10)<=1){
                break;
                }
            }
            if(c10>c01)fo(i,v10.size()){
                if(abs(c01-c10)<=1){
                break;
                }
                reverse(all(s[v10[i]]));
                if(m1[s[v10[i]]]==1);
                else{
                    c10--;
                    c01++;
                    ans.pb(v10[i]+1);
                }
            }
            if(abs(c01-c10)>1){
                cout<<-1<<endl;
                continue;
            }
            cout<<ans.size()<<endl;
            fo(i,ans.size())cout<<ans[i]<<" ";cout<<endl;


        }

        
    }

    return 0;
}