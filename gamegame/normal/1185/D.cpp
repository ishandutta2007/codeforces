#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
pair<ll,int>b[200001];
ll c[200001];
int mi=1,ma=1;
map<ll,int>mp;
bool vis[200001];
bool check(int id){
	int p=0,pp=0;
	for(int i=1; i<=n ;i++){
		if(i==id) continue;
		if(pp!=0 && b[i].fi-b[p].fi!=b[p].fi-b[pp].fi) return false;
		pp=p;p=i;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> b[i].fi;b[i].se=i;
	}
	sort(b+1,b+n+1);
	for(int i=2; i<=n ;i++){
		c[i]=b[i].fi-b[i-1].fi;
	}
	if(check(1)) return cout << b[1].se,0;
	if(check(n)) return cout << b[n].se,0;
	for(int i=3; i<=n ;i++){
		if(c[i]!=c[i-1]){
			if(check(i)) return cout << b[i].se << '\n',0;
			if(check(i-1)) return cout << b[i-1].se << '\n',0;
			cout << "-1\n";return 0;
		}
	}
}