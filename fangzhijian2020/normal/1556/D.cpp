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
int n,k,t1,p1,t2,p2,t3,p3,a[10005],t,p;
int main(){
	n=read();k=read();
	cout<<"or 1 2\n";fflush(stdout);t1=read();
	cout<<"and 1 2\n";fflush(stdout);p1=read();
	cout<<"or 2 3\n";fflush(stdout);t2=read();
	cout<<"and 2 3\n";fflush(stdout);p2=read();
	cout<<"or 1 3\n";fflush(stdout);t3=read();
	cout<<"and 1 3\n";fflush(stdout);p3=read();
	for(int i=0;i<30;++i){
		int op1=0,op2=0,op3=0;
		if(p1&(1<<i))op1=op2=1;
		if(p2&(1<<i))op2=op3=1;
		if(p3&(1<<i))op1=op3=1;
		if(!op1&&!op2&&!op3){
			if((t1&(1<<i))&&(t3&(1<<i)))op1=1;
			if((t1&(1<<i))&&(t2&(1<<i)))op2=1;
			if((t2&(1<<i))&&(t3&(1<<i)))op3=1;
		}
		a[1]+=op1<<i;a[2]+=op2<<i;a[3]+=op3<<i;
	}
	for(int i=4;i<=n;++i){
		cout<<"or 1 "<<i<<"\n";fflush(stdout);t=read();
		cout<<"and 1 "<<i<<"\n";fflush(stdout);p=read();
		for(int j=0;j<30;++j){
			int op=0;
			if(p&(1<<j))op=1;
			else{
				if(!(a[1]&(1<<j))&&(t&(1<<j)))op=1;
			}
			a[i]+=op<<j;
		}
	}
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<"\n";fflush(stdout);
	return 0;
}