#include <bits/stdc++.h>

using namespace std;

int score[2];
vector<pair<int, int> > v;

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		score[0]+=3;
		v.push_back(make_pair(a, 0));
	}
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		score[1]+=3;
		v.push_back(make_pair(a, 1));
	}
	sort(v.begin(), v.end());
	pair<int, int> ans=make_pair(-1000000000, 1000000000);
	for(int i=0; i < v.size(); ++i){
		if(!i){if(score[0]-score[1] > ans.first-ans.second || (score[0]-score[1] == ans.first-ans.second && score[0] > ans.first))
			ans=make_pair(score[0], score[1]);
		}
		score[v[i].second]--;
		
		if(i == v.size()-1 || v[i+1].first != v[i].first){
			if(score[0]-score[1] > ans.first-ans.second || (score[0]-score[1] == ans.first-ans.second && score[0] > ans.first))
				ans=make_pair(score[0], score[1]);
		}
	}
	printf("%d:%d\n", ans.first, ans.second);
}