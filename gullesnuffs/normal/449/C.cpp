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

bool used[100005];
vector<pair<int, int> > ans;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=n; i > 2; --i){
		vector<int> odd;
		vector<int> even;
		for(int j=i; j <= n; j += i){
			if(used[j])
				continue;
			if(j%2)
				odd.push_back(j);
			else
				even.push_back(j);
		}
		for(int i=0; i+1 < odd.size(); i += 2){
			used[odd[i]]=1;
			used[odd[i+1]]=1;
			ans.push_back(make_pair(odd[i], odd[i+1]));
		}
		if(odd.size()%2 && !even.empty()){
			int a1=odd[odd.size()-1], a2=even[0];
			used[a1]=1;
			used[a2]=1;
			ans.push_back(make_pair(a1, a2));
		}
	}
	vector<int> even;
	for(int i=2; i <= n; i += 2){
		if(used[i])
			continue;
		even.push_back(i);
	}
	for(int i=0; i+1 < even.size(); i += 2){
		used[even[i]]=1;
		used[even[i+1]]=1;
		ans.push_back(make_pair(even[i], even[i+1]));
	}
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}