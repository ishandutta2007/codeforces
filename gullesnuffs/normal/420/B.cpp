#include <cstdio>
#include <set>
using namespace std;

bool type[100005];
int ind[100005];

set<int> haveInBeg;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < m; ++i){
		char inp[2];
		scanf("%s%d", inp, ind+i);
		--ind[i];
		if(inp[0] == '+'){
			type[i]=1;
		}
		else{
			type[i]=0;
		}
	}
	for(int i=m-1; i >= 0; --i){
		if(type[i]){
			haveInBeg.erase(ind[i]);
		}
		else{
			haveInBeg.insert(ind[i]);
		}
	}
	set<int> ans;
	for(int i=0; i < n; ++i)
		ans.insert(i);
	for(int i=0; i < m; ++i){
		if(type[i]){
			if(i && ind[i-1] != ind[i])
				ans.erase(ind[i]);
			if(!haveInBeg.empty())
				ans.erase(ind[i]);
			haveInBeg.insert(ind[i]);
		}
		else{
			if(i < m-1 && ind[i+1] != ind[i])
				ans.erase(ind[i]);
			haveInBeg.erase(ind[i]);
			if(!haveInBeg.empty())
				ans.erase(ind[i]);
		}
	}
	printf("%d\n", ans.size());
	for(auto it = ans.begin(); it != ans.end(); ++it)
		printf("%d ", *it+1);
}