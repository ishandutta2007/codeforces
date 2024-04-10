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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,cnt[26];
string s,t;
vector<int>ans;
void func(int x){
	if(x==0)return;
	ans.pb(x);
	string r;
	for(int i=n-1;i>=n-x;i--){
		r.pb(s[i]);
	}
	for(int i=0;i<n-x;i++){
		r.pb(s[i]);
	}
	s = r;
}
int main(){
	cin>>n>>s>>t;
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
		cnt[t[i]-'a']--;
	}
	rep(i,26) if(cnt[i] != 0){
		puts("-1");
		return 0;
	}
	int beg;
	for(int i=0;i<n;i++){
		if(s[i] == t[0]){
			beg = i;
		}
	}
	for(int i=2;i<=n;i++){
		char c = t[i-1];
		int pt;
		for(int x=(beg+n-1)%n;;x=(x+n-1)%n){
			if(s[x] == c){
				pt = x;
				break;
			}
		}
		//cout<<beg<<" "<<pt<<endl;
		if(beg+i-2<n){
			if(pt<beg){
				func(n-1-pt); //cout<<s<<endl;
				func(beg); //cout<<s<<endl;
				func(i-1); //cout<<s<<endl;
				beg = 0;
			}
			else{
				func(n-1-pt);
				func(pt-beg+1-(i-1));
				beg = n-i+1;
			}
		}
		else{
			func(n-1-pt);
			func(pt+1);
			func(beg-pt-1+i-1);
			beg = beg-pt-1;
		}
		//cout<<beg<<" "<<s<<endl;
	}
	func(n-beg);
	func(beg);
	func(n);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}