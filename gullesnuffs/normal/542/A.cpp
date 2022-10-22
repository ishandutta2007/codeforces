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

ll ans=0;
int offset=(1<<18);
int bestChannel;
int bestVideo=-1;
map<pair<int, int>, int> toInd;
struct Tree{
	vector<pair<int, int> > p;
	vector<pair<int, int> > t;

	void addVideo(int l, int r){
		p.push_back(make_pair(l, r));
	}

	void consider(ll len, int ind, ll c, int channel){
		if(len*c > ans){
			ans=len*c;
			bestVideo=ind;
			bestChannel=channel;
		}
	}

	void query(int a, int b, ll c, int channel){
		auto it=lower_bound(p.begin(), p.end(), make_pair(a,-1000000005));
		bool dofirst=0;
		if(it == p.begin()){
			dofirst=1;
		}
		else{
			dofirst=0;
			--it;
			ll len=min(b, it->second)-a;
			consider(len, toInd[*it], c, channel);
		}
		int lo=(it-p.begin());
		if(dofirst)
			lo=-1;
		int hi=p.size();
		while(hi-lo > 1){
			int mid=(lo+hi)/2;
			if(p[mid].second > b){
				hi=mid;
			}
			else
				lo=mid;
		}
		int x;
		if(dofirst)
			x=offset;
		else
			x=(it-p.begin())+1+offset;
		int y=hi+offset;
		while(y > x){
			consider(t[x].first, t[x].second, c, channel);
			if(y%2)
				consider(t[y-1].first, t[y-1].second, c, channel);
			x=(x+1)/2;
			y=y/2;
		}
	}

	void fix(){
		vector<pair<int, int> > np;
		sort(p.begin(), p.end());
		np.push_back(p[0]);
		for(int i=1; i < p.size(); ++i){
			if(p[i].first == np.back().first)
				np[np.size()-1]=p[i];
			else if(p[i].second > np.back().second)
				np.push_back(p[i]);
		}
		p=np;
		t.resize(offset*2);
		for(int i=0; i < np.size(); ++i){
			t[offset+i]=make_pair(p[i].second-p[i].first, toInd[p[i]]);
		}
		for(int i=offset-1; i >= 0; --i){
			t[i]=max(t[2*i], t[2*i+1]);
		}
	}
} tree1, tree2;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,n){
		int l, r;
		scanf("%d%d", &l, &r);
		tree1.addVideo(l, r);
		tree2.addVideo(-r, -l);
		toInd[make_pair(l, r)]=i;
		toInd[make_pair(-r, -l)]=i;
	}
	tree1.fix();
	tree2.fix();
	rep(i,0,m){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tree1.query(a, b, c, i);
		tree2.query(-b, -a, c, i);
	}
	if(bestVideo == -1){
		puts("0");
	}
	else{
		printf("%I64d\n%d %d\n", ans, bestVideo+1, bestChannel+1);
	}
}