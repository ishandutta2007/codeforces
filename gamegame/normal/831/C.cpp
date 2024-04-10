#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
bool dp[2001];
vector<ll>a;
vector<ll>v;
vector<ll>v2,v3;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> k >> n;
	a.resize(k);
	for(int i=1; i<=k ;i++){
		cin >> a[i-1];
		if(i!=1) a[i-1]+=a[i-2];
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i=1; i<=n ;i++){
		ll b;cin >> b;
		if(i==1){
			for(auto aj:a){
				v3.push_back(b-aj);
			}
			reverse(a.begin(),a.end());
		}
		else{
			for(auto aj:a){
				if(v.empty()) break;
				while(!v.empty()){
					if(v.back()+aj==b){
						v3.push_back(v.back());
						break;
					}
					else if(v.back()+aj>b) break;
					else{
						v.pop_back();
					}
				}
			}
		}
		v.swap(v3);v3.clear();
		if(i!=1) reverse(v.begin(),v.end());
	}
	cout << v.size() << '\n';
}