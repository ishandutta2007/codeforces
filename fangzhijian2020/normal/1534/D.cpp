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
int n,dis[2005],tmp,s[2005],top,opt,tot,x[2005],y[2005];
int main(){
	n=read();
	cout<<"? "<<1<<endl;
	for(int i=1;i<=n;++i)dis[i]=read();
	for(int i=2;i<=n;++i)tmp+=(dis[i]&1);
	if(tmp>(n-1)/2)opt=0;else opt=1;
	for(int i=2;i<=n;++i){
		if(dis[i]==1){
			++tot;x[tot]=1;y[tot]=i;
		}
		if((dis[i]&1)==opt)s[++top]=i;
	}
	for(int i=1;i<=top;++i){
		cout<<"? "<<s[i]<<endl;
		for(int j=1;j<=n;++j){
			dis[j]=read();
			if(j!=1&&dis[j]==1)++tot,x[tot]=s[i],y[tot]=j;
		}
	}
	cout<<"!"<<endl;
	for(int i=1;i<=tot;++i)cout<<x[i]<<" "<<y[i]<<"\n";
	fflush(stdout);
	return 0;
}