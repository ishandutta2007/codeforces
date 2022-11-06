#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T;long long n,mi[30];
int t1[4]={0,2,3,1},t2[4]={0,3,1,2};
long long solve(long long n){
	int opt=(n%3),t;if(!opt)opt=3;long long ans=0;n=(n+2)/3;
	for(int i=0;i<30;++i){
		if(n>mi[i])n-=mi[i];
		else{
			ans+=opt*mi[i];
			t=i;break;
		}
	}
	for(int i=t-1;~i;--i){
		if(n<=mi[i]){continue;}
		n-=mi[i];
		if(n<=mi[i]){
			ans+=opt*mi[i];continue;
		}
		n-=mi[i];
		if(n<=mi[i]){
			ans+=t1[opt]*mi[i];continue;
		}
		n-=mi[i];
		ans+=t2[opt]*mi[i];
	}
	return ans;
}
int main(){
	T=read()+1;
	mi[0]=1;for(int i=1;i<30;++i)mi[i]=mi[i-1]*4;
	while(--T){
		n=read();cout<<solve(n)<<"\n";
	}
	return 0;
}