#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,q,opt,x,y,z,prime[7005],tot,mul[7005];bool vis[7005];
bitset<7005>f[100005],g[7005],t[7005];
int main(){
	n=read();q=read();mul[1]=1;
	for(int i=2;i<=7000;++i){
		if(!vis[i])prime[++tot]=i,mul[i]=1;
		for(int j=1;j<=tot;++j){
			if(i*prime[j]>7000)break;
			vis[i*prime[j]]=1;mul[i*prime[j]]=mul[i];
			if(i%prime[j]==0){
				mul[i*prime[j]]=0;break;
			}
		}
	}
	for(int i=1;i<=7000;++i){
		for(int j=1;j<=i;++j){
			if(i%j==0)g[i][j]=1;
		}
	}
	for(int i=1;i<=7000;++i){
		for(int j=i;j<=7000;j+=i){
			t[i][j]=mul[j/i];
		}
	}
	for(int i=1;i<=q;++i){
		opt=read();x=read();y=read();
		if(opt==1)f[x]=g[y];
		if(opt==2){z=read();f[x]=f[y]^f[z];}
		if(opt==3){z=read();f[x]=f[y]&f[z];}
		if(opt==4)cout<<((f[x]&t[y]).count()&1);
	}
	return 0;
}