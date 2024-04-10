#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n, p;
struct Item{
	int c, h, t;
	bool operator<(const Item &other) const{
		return t < other.t;
	}

}item[4005];
struct Knap{
	int dp[4005];

	void init(){
		for(int i=0; i <= 4000; ++i)
			dp[i]=0;
	}
	
	Knap perform(int c, int h){
		Knap ret;
		for(int i=4000; i >= 0; --i){
			ret.dp[i]=dp[i];
			if(i-c >= 0 && dp[i-c]+h > dp[i])
				ret.dp[i]=dp[i-c]+h;
			//dp[i+c]=max(dp[i+c], dp[i]+h);
		}
		return ret;
	}
	void fix(){
		for(int i=1; i <= 4000; ++i){
			if(dp[i-1] > dp[i])
				dp[i]=dp[i-1];
		}
	}
};

map<int, Knap> knaps;
map<int, Knap> knaps2;

int main(){
	scanf("%d%d", &n, &p);
	rep(i, 0, n){
		scanf("%d%d%d", &item[i].c, &item[i].h, &item[i].t);
	}
	sort(item, item+n);
	for(int i=0; i <= 10000; i += p){
		Knap k;
		k.init();
		knaps[0]=k;
		knaps[20000]=k;
		for(int j=0; j < n; ++j){
			auto it3=knaps.begin();
			if(item[j].t >= i && item[j].t < i+p){
				k=k.perform(item[j].c, item[j].h);
				knaps[item[j].t]=k;
				knaps[item[j].t].fix();
			}
			/*if(j)
				for(int l=item[j-1].t; l < item[j].t-1; ++l)
					knaps[l+1]=knaps[l];*/
		}
	}
	for(int i=0; i <= 10000; i += p){
		Knap k;
		k.init();
		knaps2[0]=k;
		knaps2[20000]=k;
		for(int j=n-1; j >= 0; --j){
			auto it3=knaps.begin();
			if(item[j].t >= i && item[j].t < i+p){
				k=k.perform(item[j].c, item[j].h);
				knaps2[item[j].t]=k;
				knaps2[item[j].t].fix();
			}
			/*if(j < n-1)
				for(int l=item[j+1].t; l > item[j].t+1; ++l)
					knaps2[l-1]=knaps2[l];*/
		}
	}
	int q;
	scanf("%d", &q);
	rep(i, 0, q){
		int a, b;
		scanf("%d%d", &a, &b);
		int ans=0;
		auto it1=knaps.upper_bound(a);
		auto it2=knaps2.lower_bound(a-p+1);
		Knap* k1 = &(knaps.begin()->second);
		auto it3=knaps.begin();
		--it1;
		if(it1->first/p == a/p)
			k1=&(it1->second);
		Knap* k2 = &(knaps2.begin()->second);
		if(it2->first/p == (a/p)-1)
			k2=&(it2->second);
		for(int i=0; i <= b; ++i){
			ans=max(ans, k1->dp[i]+k2->dp[b-i]);
			//ans=max(ans, knaps[a].dp[i]+knaps2[max(0, a-p+1)].dp[b-i]);
		}
		printf("%d\n", ans);
	}
}