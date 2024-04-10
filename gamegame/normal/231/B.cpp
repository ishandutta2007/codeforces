#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
ll n,d,l;
vector<int>ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> l >> d;
	int mn=0,mx=0;
	if(l>0){
		if(n%2==1) l--;
		for(int i=1; i<=n ;i+=2){
			if(i==n){
				if(l>=d) return cout << "-1\n",0;
				//cout << l << endl;
				ans.push_back(l+1);
			}
			else{
				int k=min(d-1,l);
				ans.push_back(k+1);
				ans.push_back(1);
				l-=k;
			}
		}
		if(n%2==0 && l!=0) return cout << "-1\n",0;
	}
	else{
		if(n%2==1) l--;
		for(int i=1; i<=n ;i+=2){
			if(i==n){
				if(l<0) return cout << "-1\n",0;
				ans.push_back(l+1);
			}
			else{
				int k=min((d-1),-l);
				ans.push_back(1);
				ans.push_back(k+1);
				l+=k;
				//cout << l << endl;
			}
		}
		if(n%2==0 && l!=0) return cout << "-1\n",0;
	}
	for(auto cur:ans) cout << cur << ' ';
}