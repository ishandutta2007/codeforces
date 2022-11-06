#include<bits/stdc++.h>
using namespace std;
int work(){
	int n;
	string s;
	cin>>n>>s;
	int ans=n+1;
	for(int i=0;i<n;++i){
		int a[3]={0};
		for(int j=i;j<n&&j<i+7;++j){
			++a[s[j]-'a'];
			if(j>i&&a[0]>a[1]&&a[0]>a[2])ans=min(ans,j-i+1);
		}
	}
	return ans>n?-1:ans;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)cout<<work()<<"\n";
}