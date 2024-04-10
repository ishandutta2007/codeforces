#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int main(){
	scanf("%d",&n);
	int mul=1;
	for(int i=1;i<=n;++i){
		if(__gcd(i,n)==1)ans.push_back(i),mul=1LL*mul*i%n;
	}
	if(mul^1){
		ans.erase(lower_bound(ans.begin(),ans.end(),mul));
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	return 0;
}