#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int k, n;

int grundy(int a){
	if(!a)
		return 0;
	if(a == 1)
		return 1;
	if(k%2){
		if(a == 2)
			return 0;
		if(a == 3)
			return 1;
		if(a == 4)
			return 2;
		if(a%2)
			return 0;
		int res=grundy(a/2);
		if(res == 1)
			return 2;
		return 1;
		/*int ret=1;
		while(a){
			a/=2;
			ret=3-ret;
		}
		return ret;*/
	}
	if(a == 2)
		return 2;
	if(a%2)
		return 0;
	return 1;
}

map<int, int> cache;

int bruteforce(int a){
	if(cache.count(a))
		return cache[a];
	if(a == 0)
		return 0;
	set<int> cando;
	cando.insert(bruteforce(a-1));
	if(a%2 == 0){
	if(k%2)
		cando.insert(bruteforce(a/2));
	else
		cando.insert(0);
	}
	if(!cando.count(0)){
		printf("g(%d) = %d\n", a, 0);
		cache[a]=0;
		return 0;
	}
	if(!cando.count(1)){
		printf("g(%d) = %d\n", a, 1);
		cache[a]=1;
		return 1;
	}
		printf("g(%d) = %d\n", a, 2);
	cache[a]=2;
	return 2;
}

int main(){
	scanf("%d%d", &n, &k);
	/*k=1;
	int b=bruteforce(16);
	rep(i,0,2000){
		printf("g(%d) = %d (%d)\n", i, bruteforce(i), grundy(i));
		assert(bruteforce(i) == grundy(i));
	}
	cache.clear();
	k=2;
	rep(i,0,2000){
		printf("g(%d) = %d (%d)\n", i, bruteforce(i), grundy(i));
		assert(bruteforce(i) == grundy(i));
	}
	return 0;*/
	int ans=0;
	rep(i,0,n){
		int a;
		scanf("%d", &a);
		ans ^= grundy(a);
	}
	puts(ans?"Kevin":"Nicky");
}