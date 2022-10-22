#include <cstdio>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

pair<double, double> s[100005];
bool ans=1;
struct UF{
	int a[100005];
	bool c[100005];

	void init(){
		for(int i=0; i < 100005; ++i){
			a[i]=-1;
			c[i]=0;
		}
	}

	int find(int x){
		if(a[x]== -1)
			return x;
		int p=a[x];
		a[x]=find(a[x]);
		c[x]^=c[p];
		return a[x];
	}

	void join(int x, int y, bool change){
		if(find(x) == find(y)){
			if(change^c[x]^c[y])
				ans=0;
			return;
		}
		change ^= c[y]^c[x];
		x=find(x), y=find(y);
		a[y]=x;
		c[y]=change;
	}
} uf;

vector<int> removed, added;
vector<pair<double, int> > ev;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		double l, r;
		scanf("%lf%lf", &l, &r);
		l -= 0.1;
		r += 0.1;
		s[i]=make_pair(l, r);
		ev.push_back(make_pair(l, i));
		ev.push_back(make_pair(r, i));
	}
	uf.init();
	sort(ev.begin(), ev.end());
	for(int i=0; i < ev.size(); ++i){
		pair<double, int> p=ev[i];
		int j=p.second;
		bool add=(p.first-0.01 < s[j].first);
		if(add)
			added.push_back(j);
		else
			removed.push_back(j);
		if((added.size()+removed.size())%2 == 0){
			vector<int> v;
			for(int k=0; k < added.size(); ++k)
				v.push_back(added[k]);
			for(int k=0; k < removed.size(); ++k)
				v.push_back(removed[k]);
			uf.join(v[0], v[1], added.size() != removed.size());
			added.clear();
			removed.clear();
		}
	}
	if(!ans){
		assert(0);
		puts("-1");
	}
	else{
		for(int i=0; i < n; ++i){
			uf.find(i);
			if(uf.c[i])
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}