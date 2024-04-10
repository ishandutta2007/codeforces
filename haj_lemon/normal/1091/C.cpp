#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int n,nf;
ll f[200010];
ll que(int x){return 1ll*x*(1+n-n/x+1)/2;}
int main(){
	read(n);
	for (int i=1;i*i<=n;i++){
		if (n%i==0){f[++nf]=que(i);if (i*i!=n)f[++nf]=que(n/i);}
	}
	sort(f+1,f+nf+1);
	for (int i=1;i<=nf;i++)printf("%lld ",f[i]);
	puts("");
	return 0;
}