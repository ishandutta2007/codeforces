#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,f[65][2][2][2];
//<m parityxor +n 
void Solve(){
	cin>>n>>m;
	memset(f,0,sizeof(f));
	f[0][0][0][0]=1;
	for(int i=0;i<62;i++){
		ll vn=(n>>i)&1,vm=(m>>i)&1;
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					for(int p=0;p<2;p++){
						ll nj=(p==vm?j:(p<vm?1:0));
						ll nk=k^p^((p+vn+l)&1);
						ll nl=(p+vn+l)>>1;
						f[i+1][nj][nk][nl]+=f[i][j][k][l];
					}
				}
			}
		}
	}
	ll sum=f[62][1][1][0]+f[62][1][1][1];
	cout<<sum<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}