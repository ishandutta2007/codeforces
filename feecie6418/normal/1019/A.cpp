#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
const int mod=1e9+7;
int n,m,a[3005],b[3005],used[3005];
ll ans=1e18;
vector<pr> t[3005];
pr c[3005];
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)cin>>x>>y,t[x].push_back(pr(y,i)),c[i]=pr(y,i),a[i]=x,b[i]=y;
	sort(c+1,c+n+1);
	for(int i=1;i<=m;i++)sort(t[i].begin(),t[i].end());
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		int cnt=t[1].size();
		ll sum=0;
		for(int j=2;j<=m;j++){
			int o=max((int)t[j].size()-i+1,0);
			for(int k=0;k<o;k++)sum+=t[j][k].first,used[t[j][k].second]=1;
			cnt+=o;
		}
		cnt=max(i-cnt,0);
		for(int j=1;j<=n;j++){
			if(cnt){
				if(used[c[j].second])continue;
				if(a[c[j].second]==1)continue;
				cnt--;
				sum+=c[j].first;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}