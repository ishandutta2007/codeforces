#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int Mxdt=100000,del=8001;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
long long read(){
	long long a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,I,J,K;long long Max;
long long check(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	return read();
}
long long C(int n){
	return 1ll*n*(n-1)/2;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();
		Max=check(1,n);
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(1,mid)==Max)r=mid-1;
			else l=mid+1;
		}
		K=r+1;long long tmp=check(1,r);
		J=K-(Max-tmp);Max-=C(K-J+1);
		l=1;r=J;
		while(l<=r){
			int mid=l+r>>1;
			if(C(J-mid)>=Max)l=mid+1;
			else r=mid-1;
		}
		I=l-1;
		cout<<"! "<<I<<" "<<J<<" "<<K<<endl;
	}
	return 0;
}