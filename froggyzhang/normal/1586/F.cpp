#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,k,a[N][N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	int p=0;
	for(int i=k;;i*=k){
		++p;
		for(int j=1;j<=n;j+=i){
			for(int x=j;x<=min(n,j+i-1);++x){
				for(int y=x+1;y<=min(n,j+i-1);++y){
					if(!a[x][y])a[x][y]=p;		
				}
			}
		}
		if(i>=n)break;
	}
	cout<<p<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cout<<a[i][j]<<' ';
		}
	}
	return 0;
}