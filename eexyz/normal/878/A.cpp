#include<bits/stdc++.h>
using namespace std;
#define N 1000005
char ch[N],s[10];
int x[N],c[5],n,i,j,f0,f1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s%d",s,&x[i]);
		ch[i]=s[0];
	}
	for(i=0;i<10;++i){
		f0=0;f1=1;
		for(j=1;j<=n;++j){
			if(ch[j]=='|'){
				f0|=(x[j]>>i)&1;
				f1|=(x[j]>>i)&1;
			}if(ch[j]=='&'){
				f0&=(x[j]>>i)&1;
				f1&=(x[j]>>i)&1;
			}if(ch[j]=='^'){
				f0^=(x[j]>>i)&1;
				f1^=(x[j]>>i)&1;
			}
		}
		if(f0==1&&f1==1){
			c[2]|=(1<<i);c[1]|=(1<<i);
		}
		if(f0==0&&f1==1){
			c[1]|=(1<<i);
		}
		if(f0==1&&f1==0){
			c[1]|=(1<<i);
			c[3]|=(1<<i);
		}
	}
	cout<<"3\n";
	cout<<"& "<<c[1]<<"\n";
	cout<<"| "<<c[2]<<"\n";
	cout<<"^ "<<c[3]<<"\n";
}