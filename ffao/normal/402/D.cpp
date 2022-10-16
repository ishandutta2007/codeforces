    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
    using namespace std;
     
    typedef long long ll;
    typedef pair<int,int> ii;
    typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
     
    const int mx=32000;
     
    map<int,int> f;
    set<int> bad;
    vector<ll> ps;
     
    inline ll eval2(int x) {
    	return bad.count(x) ? -1 : 1;
    }
     
    ll eval(ll x) {
    	ll y=x;
    	if(f.count(x))
    		return f[x];
    	ll ret=0;
    	for (auto p : ps) {
    		if(x<p*p) break;
    		while(x%p==0) x/=p, ret+=eval2(p);
    	}
    	if(x>1) ret+=eval2(x);
    	return f[y]=ret;
    }
     
    int main() {
    	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    	int n,m; cin>>n>>m;
    	vector<int> a(n+1);
    	for (int i=1; i<=n; i++)
    		cin>>a[i];
    	for (int i=1; i<=m; i++) {
    		int x; cin>>x; bad.insert(x);
    	}
    	vector<int> div;
    	for (int d=1; d*d<=a[1]; d++)
    		if(a[1]%d==0)
    			div.push_back(d), div.push_back(a[1]/d);
    	vector<bool> flag(mx,true);
    	flag[0]=flag[1]=false;
    	for (int i=2; i*i<mx; i++)
    		if(flag[i])
    			for (int j=i; j*i<mx; j++)
    				flag[i*j]=false;
    	for (int i=0; i<mx; i++)
    		if(flag[i])
    			ps.push_back(i);
    	for (auto x : div) {
            ll sdd = eval(x);
    		f[x]=sdd;
        }
     
    	ll ret=0;
    	for (int i=1; i<=n; i++)
    		ret+=eval(a[i]);
    	vector<int> g(n+1);
    	g[1]=a[1];
    	for (int i=2; i<=n; i++)
    		g[i]=__gcd(g[i-1],a[i]);
    	ll used=1;
    	for (int r=n; r>=1; r--) {
    		ll cur=g[r];
    		if(f[cur/used]<0)
    			ret-=r*f[cur/used], used=cur;
    	}
    	cout<<ret<<"\n";
    	return 0;
    }