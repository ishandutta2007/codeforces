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
const int N=300005;
ll a[N],b[N];
vector<ll>v[N];
ll tree[4*N];
ll temp[N];

void build(ll mini , ll maxi , ll index){
    if(mini==maxi){tree[index]= a[mini]; return ;}
    ll mid=(mini+maxi)/2;
    build(mini, mid , 2*index);
    build(mid+1 ,maxi,2*index +1);
    tree[index]=min(tree[2*index ] , tree[2*index +1]);
    return ;
}

ll minval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return mod;
    if(l==mini && r== maxi){return tree[index];  }
    ll mid= (mini+maxi)/2;
    return min( minval(mini, mid , l ,min(r,mid) , 2*index) , minval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) );
}

void update(ll mini ,ll maxi, ll treeindex , ll index, ll val){
    if(mini==maxi){tree[treeindex] = val; return ;}
    ll mid=(mini+maxi)/2;
    if(mid>=index){update(mini, mid , 2*treeindex , index , val); }
    else update(mid+1 , maxi , 2*treeindex+1 , index , val);
    tree[treeindex]= min(tree[treeindex*2] , tree[2*treeindex +1]);
}

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
        fo(i,n)cin>>a[i];
        fo(i,n)cin>>b[i];
        fo1(i,n)v[i].clear();
        fo1(i,n)temp[i]=0;
        fo(i,n){
            v[a[i]].pb(i);
        }
        flag=0;
        build(0,n-1, 1);
        //fo1(i,3*n)cout<<tree[i]<<" ";cout<<endl;
        fo(i,n){
            if(temp[b[i]]== v[b[i]].size()){
                //cout<<"fvf";
                flag=1;
                break;
            }
            ll index = v[b[i]][temp[b[i]]];
            temp[b[i]]++;
            if( minval(0,n-1, 0, index , 1 ) != b[i] ){
                //cout<<i<<" "<<minval(0,n-1, 0, index , 1 )<<endl;
                flag=1; 
                break;
            }

            update(0,n-1, 1,index, mod );
            //cout<<i<<" "<<index<<endl; fo1(i,3*n)cout<<tree[i]<<" ";cout<<endl;

        }
        if(flag)cout<<"NO";
        else cout<<"YES";
        cout<<endl;


        
    }

    return 0;
}