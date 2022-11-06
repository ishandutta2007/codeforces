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
int T,n,p[10]={0,1,11,111,1111,11111,111111,1111111,11111111,111111111};
int main(){
	T=read()+1;
	while(--T){
		n=read();int ans=0;
		for(int i=1;i<=9;++i){
			long long tmp=p[i];
			for(int j=1;j<=9;++j){
				if(j*tmp<=n)++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}