#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[105],f[105][105][2][2][2];
//0 1   0Alice/1Bob 
void Solve(){
	cin>>n;
	int c[2]={0};
	for(int i=1;i<=n;i++)cin>>a[i],c[(a[i]%2+2)%2]++;
	if(f[c[0]][c[1]][0][0][0])puts("Alice");
	else puts("Bob");
}
int main(){
	f[0][0][0][0][0]=1;
	f[0][0][0][1][0]=1;
	f[0][0][0][1][1]=1;
	f[0][0][1][1][1]=1;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(i==0&&j==0)continue;
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					for(int p=0;p<2;p++){
						bool win=0;
						if(i){
							if(!f[i-1][j][l][k][p^1])win=1;
						}
						if(j){
							if(!f[i][j-1][l][k^1][p^1])win=1;
						}
						f[i][j][k][l][p]=win;
					}
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--)Solve();
}