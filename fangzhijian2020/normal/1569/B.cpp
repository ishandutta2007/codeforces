#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,s[1000005],id[100005];char c[1000005];
int main(){
	T=read()+1;
	while(--T){
		n=read();scanf("%s",c+1);
		for(int i=1;i<=n;++i)id[i]=0;
		int tot=0;
		for(int i=1;i<=n;++i){
			if(c[i]=='2')id[i]=++tot;
		}
		if(tot==1||tot==2)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(i==j)putchar('X');
					else{
						if(!id[i]||!id[j])putchar('=');
						else{
							if(id[i]+1==id[j]){
								putchar('+');
							}
							else if(id[j]+1==id[i]){
								putchar('-');
							}
							else if(id[i]==1&&id[j]==tot){
								putchar('-');
							}
							else if(id[i]==tot&&id[j]==1){
								putchar('+');
							}
							else putchar('=');
						}
					}
				}
				puts("");
			}	
		}
	}
	return 0;
}