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
const int N=200005;
vector<ll>v[N];
ll intime[N],outtime[N], height[N],parent[N];
ll time1;
void findtime(ll node,ll root, ll h){
    parent[node]=root;
    height[node]=h;
    intime[node]=time1;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        else{
            time1++;
            findtime(v[node][i], node , h+1);
            time1++;
        }
    }
    outtime[node]=time1;
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>q;
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        time1=0;
        findtime(1,1,0);
        //fo(i,n)cout<<height[i+1]<<" ";
        fo(i,q){
            cin>>k;
            vector<ll>temp(k);
            fo(i,k)cin>>temp[i];
            ll mh=-1,index;
            fo(j,k){
                if(height[temp[j]]>mh){
                    mh=height[temp[j]];
                    index=temp[j];
                }
            }
            flag=0;
            fo(j,k){
                if(intime[parent[index]] >= intime[parent[temp[j]]]  && outtime[parent[index]]<= outtime[parent[temp[j]]]);
                else flag=1;
            }
            if(flag)cout<<"NO";
            else cout<<"YES";
            cout<<endl;


        }


        
    }

    return 0;
}