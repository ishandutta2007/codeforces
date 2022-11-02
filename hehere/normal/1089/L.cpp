#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,a[100005],b[100005],cnt;
vector < int > vec[100005],can;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i) {
		scanf("%d",a+i);
		--a[i];
	}
	for(i=0;i<n;++i){
		scanf("%d",b+i);
	}
	for(i=0;i<n;++i){
		vec[a[i]].push_back(b[i]);
	}
	LL res=0ll;
	for(i=0;i<m;++i){
		if(vec[i].empty()) ++cnt;
		sort(vec[i].begin(),vec[i].end());
		for(j=0;j<(int)vec[i].size()-1;++j){
			can.push_back(vec[i][j]);
		}
	}
	sort(can.begin(),can.end());
	for(i=0;i<cnt;++i) res+=(LL)can[i];
	printf("%I64d\n",res);
	return 0;
}