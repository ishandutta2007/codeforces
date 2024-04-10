#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],p[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,j=1;i<=n;++i){
		if(i==n||a[i]^a[i+1]){
			if(i==j){
				cout<<-1<<'\n';
				return;
			}
			for(int k=j;k<i;++k){
				p[k]=k+1;
			}
			p[i]=j;
			j=i+1;
		}
	}
	for(int i=1;i<=n;++i){
		cout<<p[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}