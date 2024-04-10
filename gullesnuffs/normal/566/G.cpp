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

vpi Max, Min;
vpi ch;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int x,y;
	scanf("%d%d", &x, &y);
	int maxx1=0,maxy1=0;
	rep(i,0,n){
		int a,b;
		scanf("%d%d", &a, &b);
		maxx1=max(maxx1,a);
		maxy1=max(maxy1,b);
		Max.push_back(make_pair(a,-b));
	}
	int maxx=0, maxy=0;
	rep(i,0,m){
		int a,b;
		scanf("%d%d", &a, &b);
		maxx=max(maxx,a);
		maxy=max(maxy,b);
		Min.push_back(make_pair(a,-b));
	}
	if(maxx1 >= maxx || maxy1 >= maxy){
		puts("Max");
		return 0;
	}
	Min.push_back(make_pair(maxx,0));
	Min.push_back(make_pair(0,-maxy));
	sort(Min.begin(), Min.end());
	ch.push_back(make_pair(Min[0].first,-Min[0].second));
	ch.push_back(make_pair(Min[1].first,-Min[1].second));
	rep(i,2,Min.size()){
		while(ch.size() > 1){
			pii p1=ch[ch.size()-2];
			pii p2=ch[ch.size()-1];
			ll dx1=p2.first-p1.first;
			ll dy1=p2.second-p1.second;
			ll dx2=Min[i].first-p1.first;
			ll dy2=-Min[i].second-p1.second;
			if(dx1*dy2-dy1*dx2 >= 0)
				ch.pop_back();
			else
				break;
		}
		ch.push_back(make_pair(Min[i].first,-Min[i].second));
	}
	sort(Max.begin(), Max.end());
	int pos=0;
	rep(i,0,Max.size()){
		while(ch[pos].first <= Max[i].first)
			++pos;
		pii p1=ch[pos-1];
		pii p2=ch[pos];
		ll dx1=p2.first-p1.first;
		ll dy1=p2.second-p1.second;
		ll dx2=Max[i].first-p1.first;
		ll dy2=-Max[i].second-p1.second;
		if(dx1*dy2-dy1*dx2 >= 0){
			puts("Max");
			return 0;
		}
	}
	puts("Min");
}