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
int T,sumA,sumB,tB;char c[15];
int main(){
	T=read()+1;
	while(--T){
		scanf("%s",c+1);int ans=10;
		sumA=sumB=0;tB=5;
		for(int i=1;i<=10;++i){
			if(i&1){
				if(c[i]=='1'||c[i]=='?')++sumA;
				if(sumA>sumB+tB){
					ans=min(ans,i);break;
				}
			}
			else{
				--tB;
				if(c[i]=='1')++sumB;
				if(sumA>sumB+tB){
					ans=min(ans,i);break;
				}
			}
		}
		sumA=sumB=0;tB=5;
		for(int i=1;i<=10;++i){
			if(!(i&1)){
				if(c[i]=='1'||c[i]=='?')++sumA;
				if(sumA>sumB+tB){
					ans=min(ans,i);break;
				}
			}
			else{
				--tB;
				if(c[i]=='1')++sumB;
				if(sumA>sumB+tB){
					ans=min(ans,i);break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}