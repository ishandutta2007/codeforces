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

char s[50005];
map<string, vector<int> > M;
map<pair<string, string>, int> cache;
int getMinDiff(string as, string bs){
	if(cache[make_pair(as, bs)])
		return cache[make_pair(as, bs)];
	vector<int> a=M[as];
	vector<int> b=M[bs];
	int alen=as.size();
	int blen=bs.size();
	int i=0, j=0;
	int ret=99999999;
	while(i < a.size() && j < b.size()){
		ret=min(ret, max(a[i]+alen, b[j]+blen)-min(a[i], b[j]));
		if(a[i] < b[j])
			++i;
		else
			++j;
	}
	cache[make_pair(as, bs)]=ret;
	cache[make_pair(bs, as)]=ret;
	return ret;
}

int main(){
	scanf("%s", s);
	for(int i=0; s[i]; ++i){
		string t;
		for(int j=0; j < 4 && s[i+j]; ++j){
			t += s[i+j];
			M[t].push_back(i);
		}
	}
	/*vector<string> longOnes;
	for(auto it=M.begin(); it != M.end(); ++it){
		if(it->second.size() < 1000)
			continue;
		longOnes.push_back(it->first);
	}*/
	int q;
	scanf("%d", &q);
	for(int i=0;i  < q; ++i){
		string a, b;
		cin >> a >> b;
		int res=getMinDiff(a, b);
		printf("%d\n", res > 100000?-1:res);	
	}
	return 0;
}