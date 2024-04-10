#include<bits/stdc++.h>
using namespace std;
#define N 2005
typedef long long ll;
int n,id[N][N],t[N][N],jb[N];
char mp[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n&1){
		cout<<"NONE\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>(mp[i]+1);
	}
	for(int i=1;i<=n;i+=2){
		for(int j=0;i-j>=1;++j){
			t[j+1][i-j]=j&1;
			id[j+1][i-j]=(i+1)/2;
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=0;i+j<=n;++j){
			t[i+j][j+1]=j&1;
			id[i+j][j+1]=i/2;
		}	
	}
	for(int i=2;i<=n;i+=2){
		for(int j=0;i+j<=n;++j){
			t[j+1][i+j]=j&1;
			id[j+1][i+j]=i/2;	
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=0;i+j<=n;++j){
			t[i+j][n-j]=j&1;
			id[i+j][n-j]=(n-i)/2+1;	
		}
	}
	for(int i=1;i<=n/2;++i)jb[i]=-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(mp[i][j]^'.'){
				int w=t[i][j]^(mp[i][j]=='G');
				if(~jb[id[i][j]]&&jb[id[i][j]]^w){
					cout<<"NONE\n";
					return 0;
				}
				jb[id[i][j]]=w;
			}	
		}
	}
	for(int i=1;i<=n/2;++i){
		if(!~jb[i]){
			cout<<"MULTIPLE\n";
			return 0;		
		}
	}
	cout<<"UNIQUE\n";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<(t[i][j]^jb[id[i][j]]?'G':'S');		
		}
		cout<<'\n';
	}
	return 0;
}