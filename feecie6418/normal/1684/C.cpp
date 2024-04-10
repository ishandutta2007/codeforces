#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m;
vector<int> a[200005],b[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	int x=0,y=0;
	for(int i=0;i<n;i++){
		a[i].resize(m);
		b[i].resize(m);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]),b[i][j]=a[i][j];
		sort(b[i].begin(),b[i].end());
		int P=-1,Q=-1;
		for(int j=0;j<m;j++){
			if(a[i][j]!=b[i][j]){
				if(P==-1)P=j;
				else if(Q==-1)Q=j;
			}
		}
		if(P!=-1&&Q!=-1)x=P,y=Q;
	}
	for(int i=0;i<n;i++){
		swap(a[i][x],a[i][y]);
		for(int j=1;j<m;j++)if(a[i][j]<a[i][j-1])return puts("-1"),void();
	}
	cout<<x+1<<' '<<y+1<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}