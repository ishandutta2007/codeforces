#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
char a[55][55],b[55][55];
int n,m,o;
pr ans[1000005];
void Do(int x,int y){
	ans[++o]=pr(x,y);
	if(a[x][y]=='L'){
		a[x][y]='U';
		a[x][y+1]='U';
		a[x+1][y]='D';
		a[x+1][y+1]='D';
	}
	else {
		a[x][y]='L';
		a[x][y+1]='R';
		a[x+1][y]='L';
		a[x+1][y+1]='R';
	}
}
bool Check(int x,int y){
	return (a[x][y]=='L'&&a[x][y+1]=='R'&&a[x+1][y]=='L'&&a[x+1][y+1]=='R')
		 ||(a[x][y]=='U'&&a[x][y+1]=='U'&&a[x+1][y]=='D'&&a[x+1][y+1]=='D');
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++)cin>>b[i]+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int done[55][55]={0};
			while(a[i][j]!=b[i][j]){
				int mn=1e9,mn1=0,mn2=0;
				for(int k=i;k<n;k++){
					for(int l=1;l<m;l++){
						if(k>i||(k==i&&l>=j)){
							if(!done[k][l]&&Check(k,l)){
								if(abs(i-k)+abs(j-l)<mn){
									mn=abs(i-k)+abs(j-l);
									mn1=k,mn2=l;
								}
							}
						}
					}
				}
				if(!mn1){
					memset(done,0,sizeof(done));
					continue;
				}
				done[mn1][mn2]=1;
				Do(mn1,mn2);
			}
		}
	}
	cout<<o<<'\n';
	for(int i=1;i<=o;i++)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}