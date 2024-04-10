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

map<int, int> M;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		int a;
		scanf("%d", &a);
		if(M.size() == 0){
			M[a]=0;
			continue;
		}
		auto it=M.lower_bound(a);
		if(it == M.begin()){
			printf("%d ", it->first);
			M[a]=it->second+1;
			continue;
		}
		auto it2=it;
		--it2;
		if(it2->second < it->second){
			printf("%d ", it->first);
			M[a]=it->second+1;
		}
		else{
			printf("%d ", it2->first);
			M[a]=it2->second+1;
		}
	}
	printf("\n");
}