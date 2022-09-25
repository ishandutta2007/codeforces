#include<bits/stdc++.h>
using namespace std;
#define N 1234
typedef long long ll;
int n,a[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i+=4){
		for(int j=1;j<=n;j+=4){
			for(int k=0;k<4;++k){
				for(int p=0;p<4;++p){
					a[i+k][j+(k+p)%4]=x++;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}