#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,m,A,B;
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();A=read();B=n*m/2-A;
		if(n&1){
			A-=m/2;
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
			}
			else puts("NO");
		}
		if(m&1){
			B-=n/2;
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
			}
			else puts("NO");
		}
		if(!(n&1)&&!(m&1)){
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
			}
			else puts("NO");
		}
	}
	return 0;
}