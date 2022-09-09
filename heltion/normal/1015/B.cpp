#include<bits/stdc++.h>
#define maxn 60
using namespace std;
char s[maxn], t[maxn];
int main(){
	int n;
	scanf("%d %s %s", &n, s, t);
	vector<int> ans;
	for(int i = 0, j; i < n; i += 1){
		for(j = i; j < n; j += 1)
			if(s[j] == t[i]) break;
		if(j == n){
			printf("-1");
			return 0;
		}
		for(; j > i; j -= 1){
			ans.push_back(j - 1);
			swap(s[j], s[j - 1]);
		}
	}
	printf("%d\n", ans.size());
	for(auto u: ans) printf("%d ", u + 1);
}