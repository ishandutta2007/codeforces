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

int a[1000000];
map<int, int> M;
vector<int> ans;

int gcd(int x, int y){
	return x?gcd(y%x, x):y;
}

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n*n){
		scanf("%d", a+i);
		M[a[i]]++;
	}
	while(!M.empty()){
		auto it=M.end();
		--it;
		while(!it->second){
			M.erase(it);
			it=M.end();
			if(it == M.begin())
				break;
			--it;
		}
		if(it == M.end())
			break;
		ans.push_back(it->first);
		rep(i,0,ans.size()){
			if(i == ans.size()-1)
				M[gcd(ans[i], it->first)]--;
			else
				M[gcd(ans[i], it->first)] -= 2;
		}
	}
	rep(i,0,ans.size())
		printf("%d ", ans[i]);
	printf("\n");
}