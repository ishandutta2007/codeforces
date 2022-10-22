#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
long long n, k, d;

void rec(vector<int> inp, int depth){
	if(depth == 0){
		ans.push_back(inp);
	}
	else{
		for(int i=1; i <= k; ++i){
			if(ans.size() == n)
				return;
			inp.push_back(i);
			rec(inp, depth-1);
			inp.pop_back();
		}
	}
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &k, &d);
	rec(vector<int>(), d);
	if(ans.size() == n){
		for(int i=0; i < d; ++i){
			for(int j=0; j < n; ++j){
				printf("%d", ans[j][i]);
				if(j < n-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	else
		puts("-1");
}