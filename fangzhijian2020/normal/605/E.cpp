#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,num,vis[1005];double f[1005],t[1005],p[1005][1005],Max;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			p[i][j]=read()/100.0;
		}
		f[i]=t[i]=1;
	}
	f[n]=t[n]=0;
	for(int i=1;i<=n;++i){
		Max=1e18;num=0;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&t[j]!=1&&f[j]/(1-t[j])<Max){
				Max=f[j]/(1-t[j]);num=j;
			}
		}
		if(!num)break;
		f[num]=f[num]/(1-t[num]);vis[num]=1;
		for(int j=1;j<=n;++j){
			if(!vis[j]){
				f[j]+=t[j]*p[j][num]*f[num];
				t[j]*=(1-p[j][num]);
			}
		}
	}
	printf("%.10lf\n",f[1]);
	return 0;
}