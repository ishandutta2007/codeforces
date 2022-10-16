#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0,n,q,is[100005];
char a[100005];
void Re(int x){
	if(x+2>n||x<1)return ;
	ans-=is[x];
	is[x]=0;
	if(a[x]=='a'&&a[x+1]=='b'&&a[x+2]=='c')is[x]=1,ans++;
}
int main(){
	cin>>n>>q>>a+1;
	for(int i=1;i+2<=n;i++){
		if(a[i]=='a'&&a[i+1]=='b'&&a[i+2]=='c')is[i]=1,ans++;
	}
	for(int i=1;i<=q;i++){
		int x;
		char c;
		cin>>x>>c;
		a[x]=c;
		for(int j=x-2;j<=x;j++)Re(j);
		cout<<ans<<'\n';
	}
}