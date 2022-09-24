#include<bits/stdc++.h>
using namespace std;
int f[80][80],g[80][80],n,m,is[80];
struct T{
	int a,b,id;
}a[80];
void Solve(){
	cin>>n>>m,memset(f,0xc0,sizeof(f)),f[0][0]=0;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b,a[i].id=i,is[i]=0;
	sort(a+1,a+n+1,[](T i,T j){return i.b<j.b;});
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			int t1=(j?f[i-1][j-1]+a[i].a+a[i].b*(j-1):-1e9),t2=f[i-1][j]+a[i].b*(m-1);
			f[i][j]=max(t1,t2),g[i][j]=(t1>t2);//i=>1
		}
	}
	for(int i=n,t=m;i&&t;i--)if(g[i][t])is[i]=1,t--;
	cout<<n*2-m<<endl;
	int pos=0;
	for(int i=1,t=0;i<=n;i++){
		if(!is[i])continue;
		if((++t)==m){
			pos=a[i].id;
			break;
		}
		cout<<a[i].id<<' ';
	}
	for(int i=1;i<=n;i++)if(!is[i])cout<<a[i].id<<' '<<-a[i].id<<' ';
	cout<<pos<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}