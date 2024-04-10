#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,ans[500005],f[500005],is[500005],cnt=1;
int gf(int x){
	return x==f[x]?x:f[x]=gf(f[x]);
}
void U(int x,int y){
	int fx=gf(x),fy=gf(y);
	f[fx]=fy,is[fy]|=is[fx];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)f[i]=i;
	for(int i=1,x,y,k;i<=n;i++){
		cin>>k;
		if(k==1){
			cin>>x;
			if(!is[gf(x)])is[gf(x)]=1,ans[++ans[0]]=i,cnt=2*cnt%mod;
		}
		else {
			cin>>x>>y;
			if(gf(x)!=gf(y)){
				if(is[gf(x)]&&is[gf(y)])continue;
				U(x,y),ans[++ans[0]]=i,cnt=2*cnt%mod;
			}
			/*else {
				if(!is[gf(x)])is[gf(x)]=1,ans[++ans[0]]=i,cnt=2*cnt%mod;
			}*/
		}
	}
	cout<<cnt<<' '<<ans[0]<<endl;
	for(int i=1;i<=ans[0];i++)cout<<ans[i]<<' ';
	return 0;
}