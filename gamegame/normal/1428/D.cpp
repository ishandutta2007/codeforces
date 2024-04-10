#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n;
int a[N];
int f[N];
int mg=0;
vector<pair<int,int> >ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	stack<int>s;
	stack<int>t;
	for(int i=n; i>=1 ;i--){
		if(a[i]==1) s.push(i);
		else if(a[i]==2){
			if(s.empty()) return cout << "-1\n",0;
			f[i]=s.top();s.pop();
			t.push(i);
		}
		else if(a[i]==3){
			if(t.empty()){
				if(s.empty()) return cout << "-1\n",0;
				f[i]=s.top();s.pop();
				t.push(i);
			}
			else{
				f[i]=t.top();t.pop();
				t.push(i);
			}
		}
	}
	for(int i=1; i<=n ;i++){
		if(a[i]==0) continue;
		else if(a[i]==1){
			ans.push_back({i,i});
		}
		else if(a[i]==2){
			ans.push_back({f[i],i});
		}
		else{
			ans.push_back({i,i});
			ans.push_back({i,f[i]});
		}
	}
	cout << ans.size() << '\n';
	for(auto c:ans){
		cout << c.fi << ' ' << c.se << '\n';
	}
}