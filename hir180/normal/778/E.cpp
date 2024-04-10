#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int ord[1005][1005],ran[1005][1005];
string A;
int n;
string B[1005];
ll dp[1005][1005],c[15];
int cur_pos;
bool cmp(const int &a,const int &b){
	int pa = B[a].size() <= cur_pos ? 0 : B[a][cur_pos]-'0';
	int pb = B[b].size() <= cur_pos ? 0 : B[b][cur_pos]-'0';
	
	if(pa == pb) return ran[cur_pos][a] < ran[cur_pos][b];
	else return pa > pb;
}
int curdig[1005];

int main(){
	cin >> A >> n;
	reverse(A.begin(),A.end());
	rep(i,n){
		cin >> B[i];
		reverse(B[i].begin(),B[i].end());
	}
	rep(i,n) ord[0][i] = ran[0][i] = i;
	rep(i,10) cin >> c[i];
	rep(j,1003){
		rep(i,n) ord[j+1][i] = i;
		cur_pos = j;
		sort(ord[j+1]+0, ord[j+1]+n, cmp);
		rep(i,n) ran[j+1][ord[j+1][i]] = i;
	}
	rep(i,1005)rep(j,1005) dp[i][j] = -1e18;
	dp[0][0] = 0;
	rep(i,A.size()){
		int lr,rr;
		if(A[i] == '?'){
			lr = 0, rr = 9;
			if(i+1 == A.size()) lr = 1;
		}
		else lr = rr = A[i]-'0';
		for(int val=lr;val<=rr;val++){
			ll add = 0;
			int up = 0;
			rep(j,n){
				int a = ord[i][j];
				int pos = B[a].size() <= i ? 0: B[a][i]-'0';
				curdig[j] = pos+val;
				add += c[curdig[j]%10];
				if(curdig[j] >= 10) up++;
			}
			rep(j,n+1){
				dp[i+1][up] = max(dp[i+1][up], dp[i][j] + add);
				if(j == n) break;
				add -= c[curdig[j]%10];
				if(curdig[j] >= 10) up --;
				curdig[j]++;
				add += c[curdig[j]%10];
				if(curdig[j] >= 10) up ++;
			}
		}
	}
	ll ans = 0,add = 0;
	rep(x,n){
		int id = ord[A.size()][x];
		if(A.size() >= B[id].size()){
			continue;
		}
		else{
			for(int i=A.size();i<B[id].size();i++){
				add += c[B[id][i]-'0'];
			}
		}
	}
	rep(x,n+1){
		ans = max(ans, dp[A.size()][x]+add);
		if(x == n) break;
		int id = ord[A.size()][x];
		if(A.size() >= B[id].size()){
			add += c[1];
		}
		else{
		    for(int i=A.size();i<B[id].size();i++){
				add -= c[B[id][i]-'0'];
			}
			bool carry = 1;
			for(int i=A.size();i<B[id].size();i++){
				int x = B[id][i]-'0';
				x += carry;
				add += c[x%10];
				if(x >= 10) carry = 1;
				else carry = 0;
			}
			if(carry) add += c[1];
		}
	}
	cout << ans << endl;
}