#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],to1[1005],to2[1005];
struct Ans{
	int a,b,c,d;
}ans[2005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],to1[a[i]]=i;// 
	for(int i=1;i<=n;i++)cin>>b[i],to2[b[i]]=i;
	for(int i=1;i<n;i++){
		//for(int j=i;j<=n;j++)cout<<a[j]<<' ';
		//puts("");
		//for(int j=i;j<=n;j++)cout<<b[j]<<' ';
		//puts("");
		int x=to1[i],y=to2[i];
		if(x!=i&&y!=i){
			if(x!=n&&y!=n){
				ans[++m]={x,i,i,n};
				ans[++m]={i,y,n,i};
				int ndn=a[n];
				to1[ndn]=x,a[x]=ndn;
				to1[a[i]]=n,a[n]=a[i];
				ndn=b[n];
				to2[ndn]=y,b[y]=ndn;
				to2[b[i]]=n,b[n]=b[i];
			}
			else if(x!=n){
				ans[++m]={x,i,i,n};
				to1[a[i]]=x,a[x]=a[i];
				to2[b[i]]=n,b[n]=b[i];
			}
			else {
				ans[++m]={i,y,n,i};
				to1[a[i]]=n,a[n]=a[i];
				to2[b[i]]=y,b[y]=b[i];
			}
		}
		else if(x!=i){
			ans[++m]={x,i,i,i};
			to1[a[i]]=x,a[x]=a[i];
		}
		else if(y!=i){
			ans[++m]={i,y,i,i};
			to2[b[i]]=y,b[y]=b[i];
		}
	}
	cout<<m<<'\n';
	for(int i=1;i<=m;i++)cout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<' '<<ans[i].d<<'\n';
}