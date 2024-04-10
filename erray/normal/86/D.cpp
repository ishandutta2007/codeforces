// author : tunay_kere
#include <bits/stdc++.h>
#define ll long long 
#define ii pair<ll,ll>
#define PB push
#define pb push_back
#define st first 
#define nd second
#define all(a) a.begin(),a.end()
#define iii pair<ii,ll>
#define mid ((l+r)/2)
#define endl "\n"
using namespace std;
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct Query {
	int l, r, idx;
	int64_t ord;
 
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
};
 
inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}
 
vector<ll> ans(200037);
vector<ll> v(200037);
vector<ll> kac(2000037);
vector<iii> que[600];
ll n,t,a,b;
ll sq=2000;
ll cvp;
void cikarma(ll x){
    cvp-=kac[x]*kac[x]*x;
    kac[x]--;
    cvp+=kac[x]*kac[x]*x;
    return;
}
void artirma(ll x){
    cvp-=kac[x]*kac[x]*x;
    kac[x]++;
    cvp+=kac[x]*kac[x]*x;
    return;
}

int main() {    
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    cin>>n>>t;
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }            
    vector<tuple<int, int, int, long long>> qs(t);
    for (int i = 0; i < t; ++i)
    {
        cin>>get<0>(qs[i]) >> get<1>(qs[i]);
        get<0>(qs[i])--;
        get<1>(qs[i])--;
        get<2>(qs[i]) = i;
        get<3>(qs[i]) = gilbertOrder(get<0>(qs[i]), get<1>(qs[i]), 21, 0);
        //que[a/sq].pb({{b,a},i});
    }
    /*
    for (int i = 0; i < 600; ++i)
    {
        sort(all(que[i]));
    }
    */
    sort(qs.begin(), qs.end(), [&](auto x, auto y) {
      return get<3>(x) < get<3>(y);
    });
    ll l=0;
    ll r=0;
     cvp=v[0];
    kac[v[0]]++;
    for (auto[sol, sag, id, foo] : qs) {
       if(l<sol){
          for (int k = l; k <sol ; ++k)cikarma(v[k]);
      }
      else{
          for (int k = sol; k < l; ++k)artirma(v[k]);
      }
     
      if(r>sag){
          
          for (int k = r; k > sag; --k)cikarma(v[k]);
      
      }
      else{
          
          for (int k = sag; k > r ; --k)artirma(v[k]);
      
      }
      ans[id]=cvp;
      l=sol;
      r=sag;
    }
    
    /*
    for (int i = 0; i < 600; ++i)
    {
        for (int j = 0; j < que[i].size(); ++j)
        {
            ll sol=que[i][j].st.nd;
            ll sag=que[i][j].st.st;
        }
    }
    */
    for (int i = 0; i < t; ++i)
    {
        cout<<ans[i]<<endl;
    }
}