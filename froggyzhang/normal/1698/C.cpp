#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N],m;
void Solve(){
	cin>>n;
	int cnt=0;
	m=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i])b[++m]=a[i];
		else ++cnt;
	}
	if(m>=5){
		cout<<"NO\n";
		return;
	}
	for(int i=1;i<=min(3,cnt);++i){
		b[++m]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			for(int k=j+1;k<=m;++k){
				bool ok=0;
				for(int o=1;o<=m;++o){
					if((ll)b[i]+b[j]+b[k]==b[o]){
						ok=1;
						break;
					}
				}
				if(!ok){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}