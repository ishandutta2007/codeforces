#include<bits/stdc++.h>
using namespace std;
const int N=55;
char s[N];
char ans[N][N];
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>s+1){
		vector<int> a,b;
		for(int i=1;i<=n;++i){
			if(s[i]=='2') a.push_back(i);
			else b.push_back(i);
		}
		if(a.size() == 1 || a.size() == 2){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;++i)ans[i][i]='X',ans[i][n+1]=0;
		for(int i=0;i<a.size();++i){
			int j=(i+1)%a.size();
			ans[a[i]][a[j]]='+';
			ans[a[j]][a[i]]='-';
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)if(!ans[i][j])ans[i][j]='=';
		for(int i=1;i<=n;++i)cout<<ans[i]+1<<"\n";
	}
}