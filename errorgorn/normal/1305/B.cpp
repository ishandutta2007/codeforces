#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;
vector<int> ans[1005];
int main(){
	cin>>s;
	for (int x=0;x<s.size();x++) v.push_back(x);
	s+='$';
	
	int l,r;
	int idx=0;
	while (!v.empty()){
		l=0,r=v.size()-1;
		while (true){
			while (l<v.size() && s[v[l]]==')') l++;
			while (~r && s[v[r]]=='(') r--;
			if (r<l) break;
			ans[idx].push_back(v[l]);
			ans[idx].push_back(v[r]);
			v.erase(v.begin()+r);
			v.erase(v.begin()+l);
			r-=2;
		}
		if (ans[idx].empty()) break;
		idx++;
	}
	
	printf("%d\n",idx);
	for (int x=0;x<idx;x++){
		printf("%d\n",ans[x].size());
		sort(ans[x].begin(),ans[x].end());
		for (auto &it:ans[x]) printf("%d ",it+1);
		printf("\n");
	}
}