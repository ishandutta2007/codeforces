#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[5005][5005];
ll g[5005];
struct A{
	int t,x;
}a[5005];
int main(){
	cin>>n,memset(g,0x3f,sizeof(g)),g[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i].t>>a[i].x;
	sort(a+1,a+n+1,[](A x,A y){return x.t<y.t;});
	for(int i=1;i<=n;i++)if(a[i].x==0)f[0][i]=1;
	for(int i=0;i<n;i++){
		//cout<<i<<' '<<g[i]<<'\n';
		//cout<<"F:"<<f[3][5]<<'\n';
		if(g[i]<=a[i].t){
			g[i+1]=min(g[i+1],max(g[i]+abs(a[i].x-a[i+1].x),(ll)a[i].t));
			for(int j=i+2;j<=n;j++)if(max((ll)a[i].t,g[i]+abs(a[i].x-a[j].x))+abs(a[j].x-a[i+1].x)<=a[i+1].t)f[i+1][j]=1;
		}
		//cout<<"F:"<<f[3][5]<<'\n';
		for(int j=i+2;j<=n;j++)if(abs(a[i].x-a[i+1].x)<=a[i+1].t-a[i].t)f[i+1][j]|=f[i][j];
		//cout<<"F:"<<f[3][5]<<'\n';
		if(f[i][i+1]){
			if(i+2>n)goto u;
			//cout<<i<<' '<<i+1<<'\n';
			g[i+2]=max((ll)a[i].t+abs(a[i+2].x-a[i].x),(ll)a[i+1].t);
			for(int j=i+3;j<=n;j++)if(a[i].t+abs(a[i].x-a[j].x)+abs(a[j].x-a[i+2].x)<=a[i+2].t&&a[i].t+abs(a[i].x-a[j].x)>=a[i+1].t&&a[i+1].t+abs(a[j].x-a[i+2].x)<=a[i+2].t)f[i+2][j]=1;
		}
		u://for(int j=i+1;j<=n;j++)cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
		if(!f[i][i+1]&&g[i+1]>a[i+1].t)return puts("NO"),0;
	}
	puts("YES");
}
/*
5
7 2
9 1
11 -3
12 -4
14 0

5
2 -1
4 2
6 3
10 7
11 1
*/