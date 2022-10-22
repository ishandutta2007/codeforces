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

vector<int> L[1000005], R[1000005];
char s[10];
int last[1000005], lastL[1000005];
set<int> S;
int Rchild[1000005];
bool added[1000005];

int main(){
	int n, c;
	scanf("%d%d", &n, &c);
	rep(i,0,c){
		int a, b;
		scanf("%d%d%s", &a, &b, s);
		--a;--b;
		if(s[0] == 'L')
			L[a].push_back(b);
		else
			R[a].push_back(b);
		if(b <= a){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	rep(i,0,n){
		S.insert(i);
		last[i]=i;
	}
	rrep(i,n,0){
		rep(j,0,L[i].size()){
			//last[i]=max(last[i],last[L[i][j]]);
			for(auto it=S.upper_bound(i); it != S.end() && *it <= L[i][j]; ){
				S.erase(it);
				it=S.upper_bound(i);
			}
		}
		int stop;
		auto it=S.upper_bound(i);
		if(it == S.end())
			stop=n;
		else
			stop=*it;
		Rchild[i]=stop;
		//lastL[i]=last[i];
		rep(j,0,R[i].size()){
			if(R[i][j] < Rchild[i]){
				puts("IMPOSSIBLE");
				return 0;
			}
			//last[i]=max(last[i],last[R[i][j]]);
			for(auto it=S.upper_bound(i); it != S.end() && *it <= R[i][j]; ){
				S.erase(it);
				it=S.upper_bound(i);
			}
		}
	}
	stack<int> s;
	s.push(0);
	while(!s.empty()){
		int cur=s.top();
		s.pop();
		if(cur < 0){
			printf("%d ", -cur);
			continue;
		}
		if(cur >= n)
			continue;
		//printf("%d ", cur+1);
		if(!added[Rchild[cur]]){
			added[Rchild[cur]]=1;
			s.push(Rchild[cur]);
		}
		s.push(-cur-1);
		if(Rchild[cur] > cur+1){
			s.push(cur+1);	
		}
	}
}