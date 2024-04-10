#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
map<tuple<int,int,int>,int>m;
int query(int a,int b,int c){
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(m.count(make_tuple(a,b,c))) return m[{a,b,c}];
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    int temp;
    cin>>temp;
    return m[{a,b,c}]=temp;
}
bool check(vi vals,int w){
    rep(i,w,w+5){
        rep(j,i+1,w+5){
            rep(k,j+1,w+5){
                if(query(i,j,k)!=min({vals[i-w],vals[j-w],vals[k-w]})+max({vals[i-w],vals[j-w],vals[k-w]})){
                    return 0;
                }
            }
        }
    }
    return 1;
}
vi get(int l){
    vi v;
    rep(i,l,l+5){
        rep(j,i+1,l+5){
            rep(k,j+1,l+5){
                v.pb(query(i,j,k));
            }
        }
    }
    sort(all(v));
    assert((v[0]+v[4]-v[9])%2==0);
    int a = (v[0]+v[4]-v[9])/2;
    int c = (v[0]-a);
    int d = (v[1]-a);
    int e = (v[4]-a);
    int b = (v[7]-e);
    v={a,b,c,d,e};
    do{
        if(check(v,l)) return v;
    }while(next_permutation(all(v)));
    return vi();
}
void solve(){
    cin>>n;
    vi ans(n+1);
    for(int i=1;i<=n;i+=5){
        int l=min(n,i+4)-4;
        vi v=get(l);
        rep(j,l,l+5) ans[j]=v[j-l];
    }
    cout<<"! ";
    rep(i,1,n+1) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}