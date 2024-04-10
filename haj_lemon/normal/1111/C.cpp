#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int ls,rs,su;ll an;}t[10000010];
int n,k,x,ro,num;
ll b,a;
ll que(ll nu){if (nu==0) return a;return t[nu].an;}
void build(int &nu,int l,int r,int we){
	if (nu==0) nu=++num;t[nu].su++;
	if (l!=r){
		if (we<=(l+r)/2) build(t[nu].ls,l,(l+r)/2,we);
		else build(t[nu].rs,(l+r)/2+1,r,we);
		t[nu].an=min(que(t[nu].ls)+que(t[nu].rs),b*t[nu].su*(r-l+1));
	}else{
		t[nu].an=b*t[nu].su;
	}
}
int main(){
	read(n);read(k);read(a);read(b);
	for (int i=1;i<=k;i++){read(x);build(ro,1,(1<<n),x);}
	cout<<que(ro)<<endl;
	return 0;
}