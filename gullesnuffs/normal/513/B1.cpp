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

int main(){
	long long n, m;
	queue<int> q;
	stack<int> s;
	cin >> n >> m;
	--m;
	for(int i=n-2; i >= 0; --i){
		if(m >= (1<<i)){
			m -= (1<<i);
			s.push(n-i-1);
		}
		else{
			q.push(n-i-1);
		}
	}
	q.push(n);
	while(!q.empty()){
		printf("%d ", q.front());
		q.pop();
	}
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
}