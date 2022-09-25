#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
const ll lim=1e14;
const int B=1e7;
ll n,k;
int flag[B+233];
gp_hash_table<ll,vector<int> > mp[10][2];
ll Solve(){
	cin>>n>>k;
	if((__int128)n*k>lim)return -1;
	for(int i=1;i<B;++i){
		int x=i/10%10,y=i%10;
		if(x==y)continue;
		int op=x<y?1:-1;
		if(i<100)flag[i]=op;
		else if(flag[i/10]==-op)flag[i]=op;
		if(flag[i]&&i%n==0){if(!--k)return i;}	
	}
	for(int i=B/100;i<B;++i){
		if(flag[i])mp[i/(B/10)][flag[i]==1][i%n].push_back(i);
	}
	for(int i=1;i<B;++i){
		if(flag[i]){
			int op=flag[i]==1;
			ll h=(n-1LL*i*B%n)%n;
			int l=(op||i<10)?0:i%10+1;
			int r=(!op||i<10)?9:i%10-1;
			for(int j=l;j<=r;++j){
				int z=j>i%10;
				if(i==j||mp[j][z].find(h)==mp[j][z].end())continue;
				int sz=mp[j][z][h].size();
				if(sz>=k)return mp[j][z][h][k-1]+1LL*i*B;
				k-=sz;
			}
		}	
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<Solve()<<'\n';
	return 0;
}