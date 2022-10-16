    #include <bits/stdc++.h>
    using namespace std;
     
    #define int long long
     
    bool sgn(int x){
    	return x>0;
    }
     
    signed main(){
    	cin.tie(nullptr)->sync_with_stdio(false);
    	cout<<fixed<<setprecision(10);
    	int n;cin>>n;
    	vector<pair<int,int>> a(n);
    	for(int i=0;i<n;i++){
    		cin>>a[i].first>>a[i].second;
    		if(i){
    			if(sgn(a[i].second)!=sgn(a[i-1].second)){
    				cout<<"-1\n";
    				return 0;
    			}
    		}
    	}
    	if(a[0].second<0){
    		for(auto &pp:a){
    			pp.second=-pp.second;
    		}
    	}
    	auto can=[&](long double r){
    		long double minx=-1e300,maxx=1e300;
    		for(auto [x,y]:a){
    			if(y>r*2)return false;
    			long double dx=sqrt(2*r*y-y*y);
    			minx=max(minx,x-dx);
    			maxx=min(maxx,x+dx);
    		}
    		return minx<=maxx;
    	};
    	long double ans=0;
    	for(long double jp=1e18;jp>=1e-20;jp/=2){
    		if(!can(ans+jp))ans+=jp;
    	}
    	cout<<ans<<"\n";
    }