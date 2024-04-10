#include<bits/stdc++.h>
using namespace std;
int n,tests;
int main(){
	for(scanf("%d",&tests);tests;tests--){
		scanf("%d",&n);	
		vector<int>ans;
		int cnt=0,k=-1;
		while(n){
			int x=n%10;
			k++;
			if(x){
				cnt++;
				for(int i=1;i<=k;i++)
				x*=10;
				ans.push_back(x);
			}
			n/=10;
		}
		printf("%d\n",cnt);
		for(unsigned int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}