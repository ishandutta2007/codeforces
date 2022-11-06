#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n,m;
char s[N];
int a[N][3][3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				a[i][j][k]=a[i-1][j][k]+(s[i]-'a'==j&&i%3==k);
	}
	while(m--){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		int p[3];
		for(int i=0;i<3;++i)p[i]=i;
		int ans=len;
		do{
			int tmp=0;
			for(int i=0;i<3;++i)
				tmp+=a[r][i][p[i]]-a[l-1][i][p[i]];
			ans=min(ans,len-tmp);
		}while(next_permutation(p,p+3));
		cout<<ans<<"\n";
	}
}