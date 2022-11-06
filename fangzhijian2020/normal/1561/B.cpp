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
int T,a,b,p1,p2,del,ans[400005],tot;
int main(){
	T=read()+1;
	while(--T){
		tot=0;
		a=read();b=read();
		p1=(a+b)/2;p2=a+b-p1;
		for(int i=0;i<=p1;++i){
			int j=a-p1+i;
			if(j>=0&&j<=p2){
				ans[++tot]=i+j;
			}
		}
		p2=(a+b)/2;p1=a+b-p1;
		for(int i=0;i<=p1;++i){
			int j=a-p1+i;
			if(j>=0&&j<=p2){
				ans[++tot]=i+j;
			}
		}
		sort(ans+1,ans+tot+1);tot=unique(ans+1,ans+tot+1)-ans-1;
		cout<<tot<<"\n";
		for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";puts("");
	}
	return 0;
}