#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

bool ok(vector<int> v){
	//printf("v.size()=%d\n", v.size());
	vector<int> pos(v.size());
	for(int i=0; i < v.size(); ++i)
		pos[v[i]]=i;
	int left=0, right=0;
	for(int i=0; i < v.size()/2; ++i)
		if(v[i]%2 == 0)
			++left;
	for(int i=v.size()/2; i < v.size(); ++i)
		if(v[i]%2 == 0)
			++right;
	vector<int> wrong[2];
	for(int i=0; i < v.size(); ++i){
		if((v[i]%2==0)^(i<v.size()/2)^(left<right)){
			wrong[v[i]%2].push_back(i);
		}
	}
	random_shuffle(wrong[0].begin(), wrong[0].end());
	random_shuffle(wrong[1].begin(), wrong[1].end());
	for(int k=0; k < 2; ++k){
	//printf("wrong[%d].size()=%d\n", k, wrong[k].size());
	for(int i=0; i < wrong[k].size(); ++i)
		for(int j=0; j < v.size(); ++j){
			int a=wrong[k][i], b=j;
			if(a > b)
				swap(a, b);
			int x=v[a]+2*(v[b]-v[a]);
			if(x >= 0 && x < v.size() && pos[x] > b)
				return 0;
			x=v[b]+2*(v[a]-v[b]);
			if(x >= 0 && x < v.size() && pos[x] < a)
				return 0;
		}
	}
	vector<int> u[2];
	for(int i=0; i < v.size(); ++i){
		u[v[i]%2].push_back(v[i]/2);
	}
	if(u[0].size() > 1 && !ok(u[0]))return 0;
	if(u[1].size() > 1 && !ok(u[1]))return 0;
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v;
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		v.push_back(a-1);
	}
	puts(ok(v)?"NO":"YES");
}