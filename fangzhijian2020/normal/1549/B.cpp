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
int T,n,ans,a[200005],b[200005];char c[200005];
int main(){
	T=read()+1;
	while(--T){
		n=read();ans=0;
		scanf("%s",c+1);for(int i=1;i<=n;++i)a[i]=c[i]=='1';
		scanf("%s",c+1);for(int i=1;i<=n;++i)b[i]=c[i]=='1';
		a[n+1]=b[n+1]=0;
		for(int i=1;i<=n;++i){
			if(b[i]==1){
				if(a[i]==0)++ans;
				else if(a[i-1]==1)++ans;
				else if(a[i+1]==1){
					++ans;a[i+1]=2;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}