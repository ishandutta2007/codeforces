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
int T,n,a[3005],opt,ans[100005],tot;
void rev(int k){
	ans[++tot]=k;for(int i=1;i<=k/2;++i)swap(a[i],a[k-i+1]);
}
int main(){
	T=read()+1;
	while(--T){
		n=read();opt=0;
		for(int i=1;i<=n;++i){
			a[i]=read();if((a[i]&1)!=(i&1))opt=1;
		}	
		if(opt==1)puts("-1");
		else{
			tot=0;
			for(int i=n;i>1;i-=2){
				int tmp1=0,tmp2=0;
				for(int j=1;j<=i;++j){
					if(a[j]==i){
						tmp2=j;
						break;
					}
				}
				rev(tmp2);
				for(int j=1;j<=i;++j){
					if(a[j]==i-1){
						tmp1=j-1;
						break;
					}
				}
				rev(tmp1);rev(tmp1+2);
				rev(3);rev(i);
			}
			cout<<tot<<"\n";
			for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";puts("");
		}
	}
	return 0;
}