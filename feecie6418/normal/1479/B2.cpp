#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005],ans=0,ct[2],lst[2];
vector<int> pos[100005];
void Do(int i){
	int p=upper_bound(pos[lst[0]].begin(),pos[lst[0]].end(),i)-pos[lst[0]].begin();
	if(p>=pos[lst[0]].size())ct[0]=0;
	else ct[0]=1;
	p=upper_bound(pos[lst[1]].begin(),pos[lst[1]].end(),i)-pos[lst[1]].begin();
	if(p>=pos[lst[1]].size())ct[1]=0;
	else ct[1]=1;
}
int Findnext(int x,int i){
	int p=upper_bound(pos[x].begin(),pos[x].end(),i)-pos[x].begin();
	return pos[x][p];
}
void Solve(){
	cin>>n,ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		if(a[i]==lst[0]){
			Do(i);
			continue;
		}
		if(a[i]==lst[1]){
			Do(i);
			continue;
		}
		ans++;
		if(!ct[0])lst[0]=a[i];
		else if(!ct[1])lst[1]=a[i];
		else {
			if(Findnext(lst[0],i)<Findnext(lst[1],i))lst[1]=a[i];
			else lst[0]=a[i];
		}
		Do(i);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)a[i]=0,pos[i].clear();
	lst[0]=lst[1]=0,ct[0]=ct[1]=0;
}
int main(){
	int t=1;
	while(t--)Solve();
}