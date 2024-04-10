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

vector<int> odd;
int c[105];

int main(){
	int n;
	int ans[2]={0, 0};
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int s;
		scanf("%d", &s);
		for(int j=0; j < s; ++j){
			scanf("%d", c+j);
		}
		int l=s/2;
		for(int j=0; j < l; ++j){
			ans[0] += c[j];
			ans[1] += c[s-1-j];
		}
		if(s%2)
			odd.push_back(c[l]);
	}
	sort(odd.begin(), odd.end());
	for(int i=0; i < odd.size(); ++i)
		ans[i%2] += odd[odd.size()-1-i];
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}