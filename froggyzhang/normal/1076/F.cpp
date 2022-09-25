#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int a[N][2],n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i][0];
	for(int i=1;i<=n;++i)cin>>a[i][1];
	int t[2]={0,0};
	for(int i=1;i<=n;++i){
		int g[2]={0,0};
		for(int j=0;j<=1;++j){
			if(a[i][j]<=a[i][j^1]){
				int w=max(0LL,a[i][j^1]-1LL*m*(a[i][j]-1));
				if(w+(~t[j]?0:t[j^1])<=m)g[j]=1;
				else g[j]=-1;	
			}
			else{
				int w=max(0LL,a[i][j]-(~t[j^1]?m:m-t[j])-1LL*m*(a[i][j^1]-1));
				if(w<=m)g[j]=w;
				else g[j]=-1;	
			}
		}
		if(!~g[0]&&!~g[1]){
			cout<<"NO\n";
			return 0;
		}
		swap(t,g);
	}
	cout<<"YES\n";
	return 0;
}