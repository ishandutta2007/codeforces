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
int T,n;
int main(){
	T=read()+1;
	while(--T){
		n=read();
		if(n%3==0){
			cout<<n/3<<" "<<n/3<<"\n";
		}
		else if(n%3==1){
			cout<<n/3+1<<" "<<n/3<<"\n";
		}
		else{
			cout<<n/3<<" "<<n/3+1<<"\n";
		}
	}
	return 0;
}