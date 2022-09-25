#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,pre[N],Q;
string s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>s[i];	
	}
	for(int i=1;i<n;++i){
		for(int j=2;j<=m;++j){
			if(s[i-1][j-1]=='X'&&s[i][j-2]=='X')++pre[j];
		}
	}
	for(int j=2;j<=m;++j){
		pre[j]+=pre[j-1];
	}
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<(pre[r]-pre[l]?"NO\n":"YES\n");
	}
	return 0;
}