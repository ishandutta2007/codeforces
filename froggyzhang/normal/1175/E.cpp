#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 500020
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,f[N][23];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		int l=read(),r=read();
		f[l][0]=max(f[l][0],r);
	}
	for(int i=1;i<N;i++){
		f[i][0]=max(f[i][0],f[i-1][0]);
	}
	for(int k=1;k<=20;k++){
		for(int i=0;i<N;i++){
			f[i][k]=f[f[i][k-1]][k-1];
		}
	}
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		int ans=0;
		for(int k=20;k>=0;k--){
			if(f[l][k]<r){
				ans+=(1<<k);
				l=f[l][k];
			}
		}
		if(ans>n){
			cout<<-1<<endl;
		}
		else{
			cout<<ans+1<<endl;
		}
	}
	return 0;
}