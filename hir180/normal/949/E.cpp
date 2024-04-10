#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>vec;
vector<int>rec(vector<int>vec){
    SORT(vec); ERASE(vec);
	bool ok = 0;
	set<int>S;
	for(int i=0;i<vec.size();i++){
		if(vec[i]) ok = 1,S.insert(vec[i]);
	}
	if(!ok){
		return vector<int>();
	}
	if(S.size() == 1){
	    int x = *S.begin();
	    if(x == 1) return vector<int>(1,1);
	    else if(x == -1) return vector<int>(1,-1);
	}
	vector<int>ret;
	bool need = 0;
	for(int i=0;i<vec.size();i++){
		if( (vec[i]%2+2)%2 == 1 ){
			need = 1;
		}
	}
	if(!need){
		rep(i,vec.size()) vec[i]/=2;
		ret = rec(vec);
		rep(i,ret.size()) ret[i]*=2;
		return ret;
	}
	else{
		vector<int>zip = vec;
		for(int i=0;i<vec.size();i++){
			if( (vec[i]%2+2)%2 == 1 ){
				vec[i] = (vec[i]-1)/2;
			}
			else vec[i] = vec[i]/2;
		}
		ret = rec(vec);
		rep(i,ret.size()) ret[i]*=2;
		ret.pb(1);
		
		vec = zip;
		for(int i=0;i<vec.size();i++){
			if( (vec[i]%2+2)%2 == 1 ){
				vec[i] = (vec[i]+1)/2;
			}
			else vec[i] = vec[i]/2;
		}
		vector<int>ret2 = rec(vec);
		rep(i,ret2.size()) ret2[i]*=2;
		ret2.pb(-1);
		
		if(ret.size() > ret2.size()) ret = ret2;
		return ret;
	}
}
int main(){
	cin>>n;
	rep(i,n){
		int a; cin>>a;
		vec.pb(a);
	}
	SORT(vec);
	ERASE(vec);
	vector<int>ans = rec(vec);
	cout<<ans.size()<<endl;
	rep(i,ans.size()){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}