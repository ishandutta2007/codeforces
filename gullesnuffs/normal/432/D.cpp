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
using namespace std;

char s[100005];
int a[100005];
int occur[100005];

int main(){
	scanf("%s", s);
	a[0]=-1;
	a[1]=0;
	for(int i=2; s[i-1]; ++i){
		int j=a[i-1];
		while(j > -1 && s[i-1] != s[j]){
			j=a[j];
		}
		a[i]=j+1;
		++occur[a[i]];
	}
	int n=strlen(s);
	for(int i=100002; i > 0; --i){
		occur[a[i]] += occur[i];
	}
	vector<pair<int, int> > ans;
	ans.push_back(make_pair(strlen(s), 1));
	int i=a[n];
	//int res=1;
	while(i){
		//res += occur[i];
		ans.push_back(make_pair(i, occur[i]+1));
		i=a[i];
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}