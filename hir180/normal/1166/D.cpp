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

int q;
ll a,b,m;
vector<ll>ans;
bool check(vector<ll>vec){
    if(vec[vec.size()-1] == b) return true;
	ll S = 0;
	rep(i,vec.size()){
		S += vec[i];
	}
	ll L = S, R = S;
	ll lb = S+1;
	ll ub = S+m;
	while(ub < b){
		ll nL = L+lb;
		ll nR = R+ub;
		lb = L+lb+1;
		ub = R+ub+m;
		L = nL;
		R = nR;
	}
	//cout << lb << " " << ub << endl;
	//for(int i=0;i<vec.size();i++) cout << vec[i] << "=====" << i << endl;
	return lb <= b;
}
bool rec(){
    if(ans[ans.size()-1] == b) return true;
	if(check(ans) == false) return false;
	ll sum = 0;
	rep(i,ans.size()) sum += ans[i];
	if(sum+1 <= b && b <= sum+m){
	    ans.push_back(b);
	    return true;
	}
	ans.push_back(sum+1);
	if(check(ans) == true){
		rec();
		return true;
	}
	ans.pop_back();
	ans.push_back(sum+m);
	assert(check(ans));
	rec();
	return true;
}
int main(){
	cin>>q;
	while(q--){
		cin>>a>>b>>m;
		ans.clear();
		ans.push_back(a);
		bool flag = rec();
		if(flag == false){
			puts("-1");
		}
		else{
			printf("%d",ans.size());
			for(int i=0;i<ans.size();i++) printf(" %lld",ans[i]);
			puts("");
		}
	}
}