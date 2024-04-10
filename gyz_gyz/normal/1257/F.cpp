#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int m=(1<<15)-1;
int a[110],ct[m+1];
map<vector<int>,int>mp;
int main(){int n;
	rep(i,1,m)ct[i]=ct[i>>1]+(i&1);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	dep(i,m,0){
		vector<int>v;int t0=ct[(a[1]>>15)^i];
		rep(j,2,n)v.pb(ct[(a[j]>>15)^i]-t0);
		mp[v]=i;
	}
	rep(i,0,m){
		vector<int>v;int t0=ct[(a[1]&m)^i];
		rep(j,2,n)v.pb(t0-ct[(a[j]&m)^i]);
		if(mp.count(v)){
			printf("%d\n",(mp[v]<<15)^i);return 0;
		}
	}
	printf("-1\n");
}