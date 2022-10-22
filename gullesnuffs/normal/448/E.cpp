#include <cstdio>
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
#include <cassert>
using namespace std;

map<long long, vector<long long> > divisors;
long long X;

vector<long long> getDiv(long long x){
	if(!divisors[x].empty()){
		return divisors[x];
	}
	if(x != X){
		vector<long long> ans;
		vector<long long> test=divisors[X];
		for(int i=0; i < test.size(); ++i)
			if(x%test[i] == 0)
				ans.push_back(test[i]);
		divisors[x]=ans;
		return ans;
	}
	vector<long long> ans;
	for(long long i=1; i*i <= x; ++i){
		if(x%i == 0){
			ans.push_back(i);
			if(i*i != x)
				ans.push_back(x/i);
		}
	}
	sort(ans.begin(), ans.end());
	divisors[x]=ans;
	return ans;
}

int printedN;

void rec(long long x, int depth){
	if(!depth){
		printf("%I64d ", x);
		++printedN;
		return;
	}
	vector<long long> d=getDiv(x);
	for(int i=0; i < d.size(); ++i){
		if(printedN == 100000)
			return;
		rec(d[i], depth-1);
	}
}

int main(){
	long long x, k;
	scanf("%I64d%I64d", &x, &k);
	X=x;
	if(k > 100005)
		k=100005;
	stack<pair<long long, int> > S;
	S.push(make_pair(x, k));
	while(!S.empty()){
		if(printedN == 100000)
			break;
		int depth=S.top().second;
		x=S.top().first;
		S.pop();
		if(!depth || x == 1){
			printf("%I64d ", x);
			++printedN;
			continue;
		}
		vector<long long> d=getDiv(x);
		for(int i=d.size()-1; i >= 0; --i){
			//rec(d[i], depth-1);
			S.push(make_pair(d[i], depth-1));
		}

	}
	//rec(x, k);
	return 0;
}