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
        cin>>n>>q;
        ll a[2][n];
        fo(i,n)a[0][i]=0,a[1][i]=0;
        set<pair<ll,ll> >s;
        s.insert(mp(0,0));
        fo(i,q){
            ll r,l;
            cin>>r>>l;
            if(a[r-1][l-1]==0){
                if(a[2-r][l-1]==1){
                    if(r==1)s.insert(mp((r-1)*n + l-1, (2-r)*n + l-1 ));
                    else s.insert(mp( (2-r)*n + l-1 ,(r-1)*n + l-1));
                }
                if(l>1)if(a[2-r][l-2]==1){
                    if(r==1)s.insert(mp((r-1)*n + l-1, (2-r)*n + l-2 ));
                    else s.insert(mp( (2-r)*n + l-2 ,(r-1)*n + l-1));
                }
                if(l<n)if(a[2-r][l]==1){
                    if(r==1)s.insert(mp((r-1)*n + l-1, (2-r)*n + l ));
                    else s.insert(mp( (2-r)*n + l ,(r-1)*n + l-1));
                }
                a[r-1][l-1]=1;
                if(s.size()>1)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else if(a[r-1][l-1]==1){
                if(a[2-r][l-1]==1){
                    set<pair<ll,ll> >::iterator it;
                    if(r==1)it=s.lower_bound(mp((r-1)*n + l-1, (2-r)*n + l-1 ));
                    else it=s.lower_bound(mp( (2-r)*n + l-1,(r-1)*n + l-1 )); 
                    s.erase(it);
                }
                if(l>1){if(a[2-r][l-2]==1){
                    set<pair<ll,ll> >::iterator it;
                    if(r==1)it=s.lower_bound(mp((r-1)*n + l-1, (2-r)*n + l-2 ));
                    else it=s.lower_bound(mp( (2-r)*n + l-2,(r-1)*n + l-1 )); 
                    s.erase(it);
                }}
                if(l<n){if(a[2-r][l]==1){
                    set<pair<ll,ll> >::iterator it;
                    if(r==1)it=s.lower_bound(mp((r-1)*n + l-1, (2-r)*n + l ));
                    else it=s.lower_bound(mp( (2-r)*n + l,(r-1)*n + l-1 )); 
                    s.erase(it);
                    
                }}
                a[r-1][l-1]=0;
                if(s.size()>1)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }

        }
        
    }

    return 0;
}