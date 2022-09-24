#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],used[100005],to[100005];
vector<int> ans[100005],lef[4];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!a[i])continue;
		if(a[i]==1){
			lef[1].push_back(i);
			continue;
		}
		if(a[i]==2){
			if(!lef[1].size())return puts("-1"),0;
			to[i]=lef[1].back(),lef[1].pop_back(),lef[2].push_back(i);
			continue;
		}
		if(lef[3].size())to[i]=lef[3].back(),lef[3].pop_back();
		else if(lef[2].size())to[i]=lef[2].back(),lef[2].pop_back();
		else if(lef[1].size())to[i]=lef[1].back(),lef[1].pop_back();
		else return puts("-1"),0;
		lef[3].push_back(i);
	}
	for(int i=1,now=1;i<=n;i++){
		if(used[i]||!a[i])continue;
		int p=i;
		while(p){
			if(a[p]==1)ans[p].push_back(now++);
			else if(a[p]==2)ans[p].push_back(now);
			else ans[p].push_back(now),ans[to[p]].push_back(now++);
			used[p]=1,p=to[p];
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		s+=ans[i].size();
		for(int j:ans[i])if(j>n)return puts("-1"),0;
	}
	cout<<s<<endl;
	for(int i=1;i<=n;i++){
		for(int j:ans[i])cout<<j<<' '<<i<<endl;
	}
	return 0;
}