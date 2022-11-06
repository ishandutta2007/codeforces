#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x,tot,Next[105],rd[105],ans[105];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cout<<"? ";
		for(int j=1;j<=n;++j){
			if(i==j){
				cout<<"2 ";
			}
			else cout<<"1 ";
		}
		cout<<endl;
		x=read();
		if(x!=i&&x!=0)Next[i]=x,++rd[x];
		cout<<"? ";
		for(int j=1;j<=n;++j){
			if(i==j){
				cout<<"1 ";
			}
			else cout<<"2 ";
		}
		cout<<endl;
		x=read();
		if(x!=i&&x!=0)Next[x]=i,++rd[i];
	}
	int st=0;
	for(int i=1;i<=n;++i){
		if(rd[i]==0){
			st=i;break;
		}
	}
	while(st){
		++tot;
		ans[st]=tot;
		st=Next[st];
	}
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}