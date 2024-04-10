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

int a[150000], b[150000], c[150000];
vector<int> as[150000];
set<pii> S;
set<int> done;
int pro[500000];
int score[500000];
bool in[500000];
int r;

int calcScore(int x, int y, int z){
	int ret=r;
	r=(r*r+3*r+5)%17;
	if(x == 9)
		ret -= 100;
	else if(x == 8)
		ret -= 20;
	if(y == 9)
		ret -= 100;
	else if(y == 8)
		ret -= 20;
	if(z == 9)
		ret -= 100;
	else if(z == 8)
		ret -= 20;
	ret -= 10*abs(x-y);
	ret -= 10*abs(x-z);
	ret -= 10*abs(y-z);
	return ret;
}

void up(int ind){
	if(in[ind]){
		in[ind]=0;
		S.erase(make_pair(score[ind], ind));
	}
	if(done.count(ind))
		return;
	int prescore=calcScore(pro[a[ind]],pro[b[ind]],pro[c[ind]]);
	--pro[a[ind]];
	++pro[b[ind]];
	++pro[c[ind]];
	if(pro[b[ind]] > 9 || pro[c[ind]] > 9){
		++pro[a[ind]];
		--pro[b[ind]];
		--pro[c[ind]];
		return;
	}
	int postscore=calcScore(pro[a[ind]],pro[b[ind]],pro[c[ind]]);
	score[ind]=prescore-postscore;
	pair<int, int> p=make_pair(prescore-postscore, ind);
	S.insert(p);
	in[ind]=1;
	++pro[a[ind]];
	--pro[b[ind]];
	--pro[c[ind]];
}

void update(int ind){
	for(int i=0; i < as[ind].size(); ++i)
		up(as[ind][i]);
}

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,4*n){
		scanf("%d%d%d", a+i, b+i, c+i);
		--a[i];--b[i];--c[i];
		as[a[i]].push_back(i);
		as[b[i]].push_back(i);
		as[c[i]].push_back(i);
		pro[i]=4;
	}
	rep(i,0,n){
		vector<int> asnew;
		rep(j,0,as[i].size()){
			bool ok=1;
			rep(k,0,asnew.size())
				if(asnew[k] == as[i][j])
					ok=0;
			if(ok)
				asnew.push_back(as[i][j]);
		}
	}
	rep(i,0,4*n)
		up(i);
	puts("YES");
	while(!S.empty()){
		int cur=S.begin()->second;
		done.insert(cur);
		printf("%d ", cur+1);
		pro[a[cur]]--;
		pro[b[cur]]++;
		pro[c[cur]]++;
		update(a[cur]);
		update(b[cur]);
		update(c[cur]);
	}
	assert(done.size() == 4*n);
}