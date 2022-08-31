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
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
typedef array<int,65536> ar;
const int mod = 1000000007;

ar and_merge(ar a, ar b){
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(!((j>>i)&1)){
				a[j] += a[j^(1<<i)];
				if(a[j] >= mod) a[j] -= mod;
			}
		}
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(!((j>>i)&1)){
				b[j] += b[j^(1<<i)];
				if(b[j] >= mod) b[j] -= mod;
			}
		}
	}
	
	rep(i,(1<<16)){
		ll c = 1LL*a[i]*b[i]%mod;
		a[i] = (int)(c);
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(!((j>>i)&1)){
				a[j] -= a[j^(1<<i)];
				if(a[j] < 0) a[j] += mod;
			}
		}
	}
	return a;
}
ar or_merge(ar a, ar b){
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(((j>>i)&1)){
				a[j] += a[j^(1<<i)];
				if(a[j] >= mod) a[j] -= mod;
			}
		}
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(((j>>i)&1)){
				b[j] += b[j^(1<<i)];
				if(b[j] >= mod) b[j] -= mod;
			}
		}
	}
	
	rep(i,(1<<16)){
		ll c = 1LL*a[i]*b[i]%mod;
		a[i] = (int)(c);
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<(1<<16);j++){
			if(((j>>i)&1)){
				a[j] -= a[j^(1<<i)];
				if(a[j] < 0) a[j] += mod;
			}
		}
	}
	return a;
}
string str;
int n;
int need[16];
bool ok[(1<<16)];
ar fr,o[2][4];
ar rec(int lb,int ub){
	//cout << lb << " " << ub << endl;
	if(lb == ub){
		if('A' <= str[lb] && str[lb] <= 'D') return o[0][str[lb]-'A'];
		if('a' <= str[lb] && str[lb] <= 'd') return o[1][str[lb]-'a'];
		assert(str[lb] == '?');
		return fr;
	}
	assert(str[lb] == '(');
	int dep = 0;
	for(int i=lb;i<=ub;i++){
		if(str[i] == '(') dep++;
		else if(str[i] == ')') dep--;
		else if(dep == 0){
			//cout << i << endl;
			//cout << lb+1 << " " << i-2 << endl;
			ar le = rec(lb+1,i-2);
			ar ri = rec(i+2,ub-1);
			if(str[i] == '&') return and_merge(le,ri);
			else if(str[i] == '|') return or_merge(le,ri);
			else{
				assert(str[i] == '?');
				ar A = and_merge(le,ri);
				ar B = or_merge(le,ri);
				rep(i,65536){
					A[i] += B[i];
					if(A[i] >= mod) A[i]-=mod;
				}
				return A;
			}
		}
	}
	assert(false);
}
int main(){
	cin >> str;
	n = str.size();
	int q ; cin >> q;
	memset(need,-1,sizeof(need));
	rep(i,q){
		int a[4];
		rep(ii,4) cin >> a[ii];
		int b;  cin >> b;
		int num = 0;
		rep(ii,4) if(a[ii]) num ^= (1<<ii);
		need[num] = b;
	}
	rep(i,65536){
		rep(j,16){
			int v = ((i>>j)&1);
			if(need[j] != -1 && need[j] != v) goto fail;
		}
		ok[i] = 1; fail:;
	}
	//make fr & o
	rep(i,65536){
		bool fail[4]={};
		rep(j,16){
			int a[4]={};
			rep(k,4) a[k] = ((j>>k)&1);
			//'A' - 'D'
			int ev = ((i>>j)&1);
			rep(look, 4){
				if(a[look] == 1 && ev);
				else if(a[look] == 0 && !ev);
				else{
					fail[look] = 1;
				}
			}
		}
		rep(ii,4){
			if(!fail[ii]){
				//cout << 0 << " " << ii << endl;
				o[0][ii][i] ++;
			}
		}
		memset(fail, 0, sizeof(fail));
		rep(j,16){
			int a[4]={};
			rep(k,4) a[k] = ((j>>k)&1);
			//'a' - 'd'
			int ev = ((i>>j)&1);
			rep(look, 4){
				if(a[look] == 0 && ev);
				else if(a[look] == 1 && !ev);
				else{
					fail[look] = 1;
				}
			}
		}
		rep(ii,4){
			if(!fail[ii]){
				//cout << 1 << " " << ii << endl;
				o[1][ii][i] ++;
			}
		}
		rep(ii,4){
			fr[i] += o[0][ii][i] + o[1][ii][i];
		}
	}
	auto ret = rec(0,n-1);
	ll ans = 0;
	rep(i,65536){
		if(ok[i]==false) continue;
		ans += ret[i];
	}
	cout << (ans%mod+mod)%mod << endl;
}