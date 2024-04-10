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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        ll a[n];
        pair<ll,ll>p[n];
        ll count[n];
        fo(i,n)count[i]=0;
        fo(i,n)cin>>a[i], a[i]=1-a[i];
        vector<ll>v[m];
        fo(i,m){
            ll k;
            cin>>k;
            fo(j,k){
                ll l;
                cin>>l;
                v[i].pb(l-1);
                if(count[l-1] ==0 )p[l-1].fi =(i) , count[l-1]++;
                else p[l-1].se = i ;
            }
        }
        ll state[m];
        fo(i,m)state[i]=-1;
        queue<ll>q;
        //queue<ll>q1;
        ll marked[n];
        fo(i,n)marked[i]=-1;
        
        fo(i,m){
            if(state[i]!=-1 || v[i].size()==0)continue;
            flag=0;
            fo(j,v[i].size())q.push(v[i][j]),marked[v[i][j]]=0;
            state[i]=0;
            //cout<<marked[0];
            while(q.size()>0){
                //fo(j,3)cout<<state[j];cout<<endl;
                ll temp=q.front();
                q.pop();
                ll kk;
                //if(temp==1)cout<<state[p[temp].fi]<<state[p[temp].se]<<endl;
                if(state[p[temp].fi]==-1)kk =p[temp].fi;
                else if(state[p[temp].se]==-1)kk =p[temp].se;
                else if((state[p[temp].se] + state[p[temp].fi])%2==a[temp])continue;
                else {flag=1; break;}
                //cout<<kk<<temp<<" ";
                if(state[kk]==-1){
                    state[kk]=(2+a[temp] - state[p[temp].fi + p[temp].se - kk])%2;
                    //cout<<temp<<kk<<state[kk]<<" ";
                    fo(j,v[kk].size()){
                        if(marked[v[kk][j]]!=0){marked[v[kk][j]]=0; q.push(v[kk][j]) ; }
                    }
                }
            }
            q.empty();
            
            if(flag==1){cout<<"NO"; return 0;}


        }
        cout<<"YES"<<endl;
    }

    return 0;
}
// if(flag==0)continue;

            // flag=0;
            // fo(j,v[i].size())q.push(v[i][j]),marked1[v[i][0]]=i;
            // state[i]=2;
            // //marked1[v[i][0]]=i;
            // while(q.size()>0){
            //     ll temp=q.front();
            //     q.pop();
            //     ll kk = p[temp].fi + p[temp].se - i;
            //     if(state[kk]<2){
            //         state[kk]=(2+a[temp] - state[temp] + 2)%2 + 2;
            //         fo(j,v[kk].size()){
            //             if(marked1[v[kk][j]]!=i){marked1[v[kk][i]]=i; q.push(v[kk][i]) ; }
            //         }
            //     }
            //     else if(state[kk] == (2+a[temp] - state[temp] + 2)%2 + 2);
            //     else {flag=1; break;}
            // }
            // q.empty();