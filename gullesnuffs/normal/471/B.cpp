#include <bits/stdc++.h>

using namespace std;

pair<int, int> h[2005];
vector<vector<int> > ans;
int n;

void rec(int pos, vector<int> v){
	if(pos == n){
		ans.push_back(v);
		return;
	}
	for(int i=pos; h[i].first == h[pos].first; ++i){
		if(ans.size() >= 3)
			break;
		v.push_back(h[i].second);
		swap(h[i], h[pos]);
		rec(pos+1, v);
		swap(h[i], h[pos]);
		v.pop_back();
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int H;
		scanf("%d", &H);
		h[i]=make_pair(H, i+1);
	}
	sort(h, h+n);
	rec(0, vector<int>());
	if(ans.size() < 3)
		puts("NO");
	else{
		puts("YES");
		for(int i=0; i < 3; ++i){
			for(int j=0; j < ans[i].size(); ++j){
				printf("%d", ans[i][j]);
				if(j < ans[i].size()-1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
}