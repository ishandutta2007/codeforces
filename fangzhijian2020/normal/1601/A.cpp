#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int T,n,a[200005],h[35];
int main(){
	T=read()+1;
	while(--T){
		memset(h,0,sizeof(h));
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			for(int j=0;j<=30;++j){
				h[j]+=(a[i]>>j)&1;
			}
		}
		for(int i=1;i<=n;++i){
			int opt=1;
			for(int j=0;j<=30;++j){
				if(h[j]%i)opt=0;
			}
			if(opt)cout<<i<<" ";
		}
		puts("");
	}
	return 0;
}