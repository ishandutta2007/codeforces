#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt[100005],cc[100005];
vector<int> can[100005];
void Solve(){
	cin>>n>>m;
	for(int i=1,s;i<=m;i++){
		cin>>s;
		can[i].resize(s);
		for(int j=0;j<s;j++)cin>>can[i][j];
		if(s==1)cnt[can[i][0]]++;
	}
	int flag=0;
	for(int i=1;i<=n;i++)if(cnt[i]>(m+1)/2)flag=1;
	if(flag)puts("NO");
	else {
		puts("YES");
		for(int i=1;i<=m;i++){
			for(int j:can[i]){
				if(cc[j]+cnt[j]==(m+1)/2&&can[i].size()>1)continue;
				cc[j]++;
				if(can[i].size()==1)cnt[j]--;
				cout<<j<<' ';
				break;
			}
		}
		puts("");
	}
	for(int i=1;i<=n;i++)cnt[i]=cc[i]=0;
	for(int i=1;i<=m;i++)can[i].clear();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}