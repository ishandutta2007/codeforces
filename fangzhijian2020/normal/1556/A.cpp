#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,c,d;
int main(){
	T=read()+1;
	while(--T){
		c=read();d=read();
		if(c==0&&d==0){
			puts("0");
		}
		else{
			if(c==d){
				puts("1");
			}
			else{
				if(!(abs(c-d)&1))puts("2");
				else puts("-1");
			}
		}
	}
	return 0;
}