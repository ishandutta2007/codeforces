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
int T,n,h[105];char c[1005];
int main(){
	T=read()+1;
	while(--T){
		n=read();scanf("%s",c+1);
		memset(h,0,sizeof(h));int opt=1;
		for(int i=1;i<=n;++i){
			if(c[i]!=c[i-1]&&h[c[i]-'A']){
				puts("NO");opt=0;break;
			}
			h[c[i]-'A']=1;
		}
		if(opt)puts("YES");
	}
	return 0;
}