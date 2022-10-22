#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define pil pair<int, long long>
#define INF make_pair(1000000001, 0)
using namespace std;

vector<int> v[2];
int n, m;
vector<pair<int, int> > u;
long long nC3(long long N){
	return (N*(N-1)*(N-2))/6;
}
pil best(pil p1, pil p2){
	if(!p1.second)
		return p2;
	if(!p2.second)
		return p1;
	if(p1.first < p2.first)
		return p1;
	if(p1.first > p2.first)
		return p2;
	return make_pair(p1.first, p1.second+p2.second);
}

pil test(vector<int> v1, vector<int> v2, bool type){
	u.clear();
	for(int i=0; i < v1.size(); ++i)
		u.push_back(make_pair(v1[i], 0));
	for(int i=0; i < v2.size(); ++i)
		u.push_back(make_pair(v2[i], 1));
	sort(u.begin(), u.end());
	if(type){
		long long n1=0, n2=0;
		long long ans=0;
		long long current=0;
		for(int i=0; i < u.size(); ++i){
			pair<int, int> p = u[i];
			if(p.second){
				if(i && p.first == u[i-1].first)
					current += 0;
				else
					current=0;
				++n2;
				ans += n1*(v1.size()-n1+current);
				ans -= (current*(current+1))/2;
			}
			else{
				++n1;
				if(i && p.first == u[i-1].first)
					++current;
				else
					current=1;
			}
		}
		if(ans)
			return make_pair(0, ans);
		return INF;
	}
	else{
		sort(v1.begin(), v1.end());
		if(v1.empty())
			return INF;
		long long t1, t2;
		for(int i=0; i < v1.size() && v1[i] == v1[0]; ++i)
			t1=i+1;
		for(int i=v1.size()-1; i >= 0 && v1[i] == v1[v1.size()-1]; --i)
			t2=v1.size()-i;
		long long tot=v1.size();
		pil ans=INF;
		for(int i=0; i < v2.size(); ++i){
			if(v2[i] < v1[0])
				ans=best(ans, make_pair(v1[0]-v2[i], t1*(tot-t1)+(t1*(t1-1))/2));
			else if(v2[i] > v1[v1.size()-1])
				ans=best(ans, make_pair(v2[i]-v1[v1.size()-1], t2*(tot-t2)+(t2*(t2-1))/2));
		}
		return ans;
	}
}

pil test(vector<int> v1){
	sort(v1.begin(), v1.end());
	if(v1.empty())
		return INF;
	long long t1, t2;
	for(int i=0; i < v1.size() && v1[i] == v1[0]; ++i)
		t1=i+1;
	for(int i=v1.size()-1; i >= 0 && v1[i] == v1[v1.size()-1]; --i)
		t2=v1.size()-i;
	if(t1 == v1.size())
		return make_pair(n, nC3(t1));
	long long tot=v1.size();
	long long left=tot-t1-t2;
	return make_pair(n-v1[v1.size()-1]+v1[0], nC3(tot)-nC3(tot-t1)-nC3(tot-t2)+nC3(left));
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < m; ++i){
		int s, f;
		scanf("%d%d", &s, &f);
		v[s].push_back(f);
	}
	pil ans=make_pair(n+1, 0);
	for(int i=0; i < 2; ++i)
		for(int j=0; j < 2; ++j)
			ans=best(ans, test(v[i], v[1-i], j));
	for(int i=0; i < 2; ++i)
		ans=best(ans, test(v[i]));
	printf("%I64d\n", ans.second);
	return 0;
}