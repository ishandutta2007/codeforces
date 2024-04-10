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
pair<ll,ll>a[N],d[N];
pair<ll, pair<ll,ll> >mon[N];
map<ll,ll>m1;
multiset<ll>s;
ll tree[3*N];
ll lazy[3*N];

void push(ll index){
    tree[2*index]+=lazy[index];
    lazy[2*index]+=lazy[index];
    tree[2*index+1]+=lazy[index];
    lazy[2*index+1]+=lazy[index];
    lazy[index]=0;
}

void build(ll mini, ll maxi , ll index ){
    if(mini==maxi){tree[index]=d[mini].se; return ;}
    ll mid=(mini+maxi)/2;
    build(mini,mid, 2*index);
    build(mid+1,maxi,2*index +1);
    tree[index]=min(tree[2*index] , tree[2*index+1]);
}

void update(ll mini, ll maxi , ll l , ll r, ll val, ll index){
    if(l>r)return;
    if(l==mini && r==maxi ){
        tree[index]+=val;
        lazy[index]+=val;
        return;
    }
    push(index);
    ll mid=(mini+maxi)/2;
    update( mini ,mid, l ,min(r,mid) , val, 2*index );
    update( mid+1, maxi , max(l,mid+1), r,val, 2*index+1 );
    tree[index]= min(tree[2*index], tree[2*index+1]);

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
        ll p;
        cin>>n>>m>>p;
        fo(i,n){
            ll a1,b1;
            cin>>a1>>b1;
            a[i]=mp(a1,b1);
        }
        sort(a,a+n);
        fo(i,m){
            ll a1,b1;
            cin>>a1>>b1;
            d[i]=mp(a1,b1);
        }
        sort(d,d+m);
        fo(i,m){
            if(m1[d[i].fi] == 0)m1[d[i].fi]=i+1;
            s.insert(d[i].fi);
        }
        fo(i,p){
            ll a1,b1,c1;
            cin>>a1>>b1>>c1;
            mon[i]=mp(a1,mp(b1,c1));
        }
        sort(mon,mon+p);

        fo(i,3*N)lazy[i]=0;
        build(0,m-1,1);

        ll temp=0;
        s.insert(mod);
        multiset<ll>::iterator it;
        ll ans=-10*mod;
        //cout<<tree[1];
        fo(i,n){
            ll attack=a[i].fi;
            for( ; mon[temp].fi < attack && temp<p; temp++){
                //cout<<233;
                ll val =mon[temp].se.se;
                it=s.upper_bound(mon[temp].se.fi);
                //cout<<*it<<val;
                if(*it ==mod)continue;
                ll index=m1[(*it)]-1;
                //cout<<index<<" ";
                update(0,m-1 , index , m-1 , -val,1);
            }
            //cout<<tree[1]<<endl;
            ll mini = tree[1];

            ans=max(ans, -a[i].se - mini);


        }
        cout<<ans;

        
    }

    return 0;
}