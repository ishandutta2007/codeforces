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
int k,F[6],q;long long f[1000005];
void solve(int num,int v,int w){
	for(int i=1;i<=22;++i){
		if(num>=(1<<i)-1){
			long long V=v*(1ll<<i-1),W=w*(1ll<<i-1);
			for(int j=999999;j>=V;--j)f[j]=max(f[j],f[j-V]+W);
		}
		else{
			long long V=v*(num-(1ll<<i-1)+1),W=w*(num-(1ll<<i-1)+1);
			for(int j=999999;j>=V;--j)f[j]=max(f[j],f[j-V]+W);
			break;
		}
	}
}
int main(){
	k=read();for(int i=0;i<6;++i)F[i]=read();
	for(int i=0;i<=999999;++i){
		int now=i;long long tmp=0;
		for(int j=0;j<6;++j){
			int x=now%10;now/=10;
			if(x==3||x==6||x==9){
				tmp+=1ll*(x/3)*F[j];
			}
		}
		f[i]=tmp;
	}
	int num=3*(k-1),v=3;
	for(int i=0;i<6;++i){solve(num,v,F[i]);v*=10;}	
	q=read()+1;while(--q)cout<<f[read()]<<"\n";
	return 0;
}