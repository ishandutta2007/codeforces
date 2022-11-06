#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,ans,tp[205];char c[105];
int main(){
	T=read()+1;
	while(--T){
		ans=0;scanf("%s",c+1);
		for(int i=1;i<=26;++i)tp[c[i]]=i;
		scanf("%s",c+1);n=strlen(c+1);
		for(int i=1;i<n;++i){
			ans+=abs(tp[c[i+1]]-tp[c[i]]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}