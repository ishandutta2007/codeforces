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

//Pohlig Hellman algorithmW
typedef unsigned long long ull;
ull M[65][65];
vector<ll>pr;
ull multiply_powers_of_2(ull a, ull b);
ull multiply(ull a, ull b){
	ull ans = 0;
	for(int i=0;i<64;i++){
		if(((a>>i)&1ull) == 0) continue;
		for(int j=0;j<64;j++){
			if(((b>>j)&1ull) == 0) continue;
			
			ans ^= multiply_powers_of_2(1ull<<i, 1ull<<j);
		}
	
	}
	return ans;
}
ull multiply_powers_of_2(ull a, ull b){
	if(a == 1 || b == 1) return a * b;
	
	ull n = 32;
	while( (1ull<<n) > max(a,b) ) n /= 2;
	
	ull pwer = (1ull << n);
	
	if(a >= pwer && b >= pwer){
		return multiply(pwer * 3 / 2, multiply_powers_of_2(a / pwer, b / pwer));
	}
	else if(a >= pwer){
		return multiply_powers_of_2(a / pwer, b) * pwer;
	}
	else{
		return multiply_powers_of_2(a, b / pwer) * pwer;
	}
}
void prepare_nimber(){
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			M[i][j] = multiply_powers_of_2((1ull<<i), (1ull<<j));
		}
	}
}
ull mul(ull a,ull b){
	ull ans = 0;
	for(int i=0;i<64;i++){
		if(((a>>i)&1ull) == 0) continue;
		for(int j=0;j<64;j++){
			if(((b>>j)&1ull) == 0) continue;
			
			ans ^= M[i][j];
		}
	}
	return ans;
}
ull zip[65];
void specific_set(ull a){
    rep(i,64) zip[i] = 0;
    rep(i,64){
        if(((a>>i)&1ull) == 0) continue;
        rep(j,64){
            zip[j] ^= M[i][j];
        }
    }
}
ull specific_mul(ull a,ull b){
    ull ret = 0;
    rep(i,64){
        if(((a>>i)&1ull)) ret ^= zip[i];
    }
    return ret;
}
ull pw(ull a, ull b){
	ull ret = 1;
	rep(i,64){
		if(((b>>i)&1ull)) ret = mul(ret,a);
		a = mul(a,a);
	}
	return ret;
}
ull solve_discrete(ull a, ull step, ull goal){
	if(goal == 1ull) return 0ull;
	
	int sz = (int)sqrt((double)(step));
	sz = max(sz,1);
	unordered_map<ull, int>sm;
	ull cur = 1;
	specific_set(a);
	for(int i=0;i<sz;i++){
		sm[goal] = i;
		goal = specific_mul(goal,a);
		cur = specific_mul(cur,a);
	}
	ull curr = 1;
	for(int i=0;i<step/sz+5;i++){
		curr = mul(curr,cur);
		if(sm.find(curr) != sm.end()){
			return (ull)(i+1)*sz - sm[curr];
		}
	}
	return (ull)(-1);
}

ull do_crt(vector<pair<ull,ull>>query){
	ull cur = query[0].sc;
	ull sum = query[0].fi;
	for(int i=1;i<query.size();i++){
	    while(cur%query[i].fi != query[i].sc) cur += sum;
	    sum *= query[i].fi;
	}
	return cur;
}
int main(){
	//2^64-1
	pr = {3, 5, 17, 257, 641, 65537, 6700417};
	reverse(pr.begin(),pr.end());
	prepare_nimber();
	int t; cin >> t;
	//srand((unsigned)(614));
	rep(i,t){
		ull a,b,ret; cin >> a >> b;
		//a = 1ull * rand() * rand() * rand() * rand() * rand() * rand() ;
		//b = 1ull * rand() * rand() * rand() * rand() * rand() * rand() ;
		//throw for CRT
		vector<pair<ull,ull>>query;
		rep(j,pr.size()){
			ull p = pr[j];
			ull A = pw(a, ((ull)(-1)) / p);
			ull B = pw(b, ((ull)(-1)) / p);
			ull ret = solve_discrete(A, p, B);
			
			if(ret >= p){
				puts("-1"); goto bad;
			}
			else query.push_back(mp(pr[j],ret));
		}
		ret = do_crt(query);
		rep(i,query.size()){
		    assert(ret%query[i].fi == query[i].sc);
		}
		assert(pw(a,ret) == b);
		cout << ret << endl;
		bad:;
	}
	return 0;
}