#include<iostream>
#include<vector>
using namespace std;
const int m=300000;
int n;
int a[300001];
int f[300001];
int h[300001];
vector<int>pf[300001];
int cnt[300001];
int ans[300001];
int bs[64];
int bc[64];
int num[64];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int g=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		f[a[i]]++;
		g=gcd(g,a[i]);
	}
	for(int i=1; i<=m ;i++){
		for(int j=i; j<=m ;j+=i){
			h[i]+=f[j];
		}
	}
	if(g!=1){
		cout << "-1\n";
		return 0;
	}
	for(int i=2; i<=m ;i++){
		if(!pf[i].empty()) continue;
		for(int j=i; j<=m ;j+=i) pf[j].push_back(i);
	}
	cnt[1]=n;
	for(int i=2; i<=m ;i++){
		int sz=pf[i].size();
		num[0]=1;
		for(int j=0; j<sz ;j++) num[(1<<j)]=pf[i][j];
		bc[0]=0;
		for(int j=0; j<(1<<sz) ;j++){
			if(j!=0) bc[j]=bc[j^(j&-j)]+1;
			if(j!=(j&-j)) num[j]=num[j^(j&-j)]*num[j&-j];
		}
		ans[i]=1e9;
		for(int j=0; j<(1<<sz) ;j++){
			if(bc[j]%2) cnt[i]-=h[num[j]];
			else cnt[i]+=h[num[j]];
			if(j!=0 && cnt[num[j]]!=0) ans[i]=min(ans[i],ans[num[(1<<sz)-1]/num[j]]+1);
		}
	}
	int res=1e9;
	for(int i=1; i<=m ;i++){
		if(f[i]!=0) res=min(res,ans[i]+1);
	}
	cout << res << endl;
}