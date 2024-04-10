#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[200005],b[200005];
vector<int>za;
//dp[i]...i, i+way
struct seg{
    P seg[(1<<20)];
    P mergee(P a, P b){
        if(a.fi < b.fi) return a;
        if(a.fi > b.fi) return b;
        return mp(a.fi,(a.sc+b.sc)%mod);
    }
    void init(){ fill(seg,seg+(1<<20),mp(2*INF,0)); }
    void update(int pos,P p){
        pos += (1<<19)-1; seg[pos] = mergee(seg[pos],p); //cout << pos << " " << p.fi << " " << p.sc << " " << seg[pos].sc << endl;
        while(pos){
            pos = (pos-1)/2;
            seg[pos] = mergee(seg[pos*2+1],seg[pos*2+2]);
        }
    }
    P query(int a,int b,int k,int l,int r){
        if(r < a || b < l) return mp(2*INF,0);
        if(a <= l && r <= b) return seg[k];
        return mergee(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2+1,r));
    }
}kaede;

int main(){
    cin >> n; kaede.init();
    vector<P>vec;
    rep(i,n) {cin>>a[i]>>b[i];za.pb(a[i]); za.pb(b[i]); vec.pb(P(a[i],b[i]));}
    SORT(za); ERASE(za);
    SORT(vec); reverse(vec.begin(),vec.end());
    rep(i,n){
        int x = POSL(za,vec[i].fi); int y = POSL(za,vec[i].sc); //xin yout
        P a = kaede.query(x,za.size()-1,0,0,(1<<19)-1);
        if(a.fi == 2*INF){
            kaede.update(y,mp(vec[i].sc,1));
        }
        else{
            kaede.update(y,mp(a.fi-vec[i].fi+vec[i].sc,a.sc));
        }
    }
    //cout << kaede.seg[0].fi << endl;
    cout << kaede.seg[0].sc << endl;
}