#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,a[2][N],b[2][N]; 
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<2;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	for(int i=0;i<2;++i)
		for(int j=1;j<=n;++j)
			cin>>b[i][j];
	int c0=0,c1=0,op=0;
	for(int i=1;i<=n;++i){
		int t0,t1;
		if(!op){
			c0+=a[0][i];
			c1+=a[1][i];
			t0=b[0][i],t1=b[1][i];
		}
		else{
			c0+=b[0][i];
			c1+=b[1][i];
			t0=a[0][i],t1=a[1][i];
		}
		if(t0&&c0){
			--c0,--t0;
		}
		if(t1&&c1){
			--c1,--t1;
		}
		if(t0&&c1){
			--c1,--t0;
			++ans;
		}
		if(t1&&c0){
			--c0,--t1;
			++ans;
		}
		if(t0||t1){
			op^=1;
			c0=t0,c1=t1;
		}
		ans+=c0+c1;
	}
	if(c0||c1){
		cout<<-1<<'\n';
		return 0;
	}
	cout<<ans<<'\n';
	return 0;
}