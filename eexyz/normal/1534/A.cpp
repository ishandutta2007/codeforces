#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 105
int n,i,j,T,f[3],m,x,y,v,a[N]; 
char s[N][N];
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		f[0]=f[1]=0;
		for(i=1;i<=n;++i){
			scanf("%s",s[i]+1);
			for(j=1;j<=m;++j){
				if(s[i][j]=='W')f[(i+j)&1]|=1;
				if(s[i][j]=='R')f[(i+j)&1]|=2;
			}
		}
		if(f[0]==3||f[1]==3||(f[0]==1&&f[1]==1)||(f[0]==2&&f[1]==2))cout<<"NO\n";
		else{
			cout<<"YES\n";
			if(!f[0]&&!f[1])f[0]=1,f[1]=2;
			else if(!f[0])f[0]=3-f[1];
			else if(!f[1])f[1]=3-f[0];
			for(i=1;i<=n;++i){
				for(j=1;j<=m;++j){
					if(f[(i+j)&1]==1)cout<<"W";
					else cout<<"R"; 
				}
				cout<<"\n";
			}
		}
	}
}