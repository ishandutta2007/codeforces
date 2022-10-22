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

int p[100005];
pair<int, int> a[100005];
bool isPrime[100005];

void sw(int i, int j){
	swap(p[a[i].first], p[a[j].first]);
	swap(a[i], a[j]);
	/*int I=a[i].first;
	int J=a[j].first;
	swap(p[I], p[J]);
	swap(a[i], a[j]);*/
}

int main(){
	for(int i=2; i < 100005; ++i){
		isPrime[i]=1;
		for(int j=2; j*j <= i; ++j){
			if(i%j == 0)
				isPrime[i]=0;
		}
	}
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int b;
		scanf("%d", &b);
		--b;
		a[i]=make_pair(b, i);
	}
	for(int i=0; i < n; ++i){
		p[a[i].first]=i;
	}
	vector<pair<int, int> > ans;
	for(int i=0; i < n; ++i){
		while(p[i] != i){
			int j;
			for(j=p[i]-i+1; !isPrime[j]; --j);
			ans.push_back(make_pair(p[i]-j+1, p[i]));
			sw(p[i], p[i]-j+1);
		}
	}
	assert(ans.size() <= 5*n);
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first+1, ans[i].second+1);
	return 0;
}