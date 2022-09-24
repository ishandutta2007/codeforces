
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,dis[2005][2005],cnt[2];
void Q(int x){
	cout<<"? "<<x<<endl;
	for(int i=1;i<=n;i++)cin>>dis[x][i];
}
int main(){
	scanf("%d",&n),Q(1);
	for(int i=2;i<=n;i++)cnt[dis[1][i]&1]++;
	if(cnt[0]<cnt[1]){
		for(int i=2;i<=n;i++)if(dis[1][i]%2==0)Q(i);
	}
	else {
		for(int i=2;i<=n;i++)if(dis[1][i]%2==1)Q(i);
	}
	cout<<"!"<<endl;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(dis[i][j]==1||dis[j][i]==1)cout<<i<<' '<<j<<endl;
}