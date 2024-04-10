#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt[100005],pl[100005],b[1505][1505];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&cnt[i]),pl[i]=i;
	sort(pl+1,pl+m+1,[](int x,int y){return cnt[x]>cnt[y];});
	int ans=1;
	while(ans*((ans+1)/2)<cnt[pl[1]]||3*(ans/2)*(ans/2)+(ans%2)*(2*ans-1)<n)ans++;
	cout<<ans<<'\n';
	int cnt1=0,p=2;
	for(int i=1;i<=ans;i+=2)for(int j=1;j<=ans;j++)b[i][j]=pl[1],cnt1++;
	for(int i=2;i<=ans;i+=2)for(int j=1;j<=ans;j+=2)b[i][j]=pl[1],cnt1++;
	for(int j=1;j<=ans;j+=2)
		for(int i=2;i<=ans;i+=2){
			while(p<=m&&!cnt[pl[p]])p++;
			if(p>m)break;
			if(b[i][j]==pl[1])cnt1--;
			cnt[pl[p]]--,b[i][j]=pl[p];
		}
	for(int j=1;j<=ans;j+=2)
		for(int i=1;i<=ans;i+=2){
			while(p<=m&&!cnt[pl[p]])p++;
			if(p>m)break;
			if(b[i][j]==pl[1])cnt1--;
			cnt[pl[p]]--,b[i][j]=pl[p];
		}
	for(int i=2;i<=ans;i+=2)
		for(int j=1;j<=ans;j+=2){
			if(b[i][j]==pl[1]){
				while(p<=m&&!cnt[pl[p]])p++;
				if(p<=m)cnt1--,cnt[pl[p]]--,b[i][j]=pl[p];
				else if(cnt1>cnt[pl[1]])cnt1--,b[i][j]=0;
			}
		}
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=ans;j++){
			if(b[i][j]==pl[1]){
				while(p<=m&&!cnt[pl[p]])p++;
				if(p<=m)cnt1--,cnt[pl[p]]--,b[i][j]=pl[p];
				else if(cnt1>cnt[pl[1]])cnt1--,b[i][j]=0;
			}
		}
	}
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=ans;j++)printf("%d ",b[i][j]);
		puts("");
	}
	for(int i=1;i<=ans;i++)for(int j=1;j<=ans;j++)b[i][j]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}