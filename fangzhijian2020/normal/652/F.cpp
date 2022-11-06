#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,tmp[300005],ans[300005];long long T;char c[10];
struct node{
	int x,opt,id;
	bool operator<(const node&a)const{
		if(x==a.x)return opt<a.opt;
		return x<a.x;
	}
}t[300005];
int main(){
	n=read();m=read();T=read();
	for(int i=0;i<n;++i){
		t[i].x=read()-1;scanf("%s",c+1);
		t[i].opt=c[1]=='R';t[i].id=i;
		tmp[i]=(t[i].x+(t[i].opt?T%m:m-T%m))%m;
	}
	sort(t,t+n);sort(tmp,tmp+n);
	int id=0;
	for(int i=1;i<n;++i){
		if(t[0].opt!=t[i].opt){
			if(t[0].opt==1){
				id=(id+((T<<1)-(t[i].x-t[0].x)+m)/m)%n;
			}
			else{
				id=(id-(((T<<1)-(m-(t[i].x-t[0].x))+m-1)/m)%n+n)%n;
			}
		}
	}
	int now=(t[0].x+(t[0].opt?T%m:m-T%m))%m;
	int ID=-1;
	for(int i=n-1;~i;--i){
		if(now==tmp[i]){
			ID=i;break;
		}
	}
	id=(ID-id+n)%n;
	for(int i=0;i<n;++i){
		ans[t[i].id]=tmp[id]+1;id=(id+1)%n;
	}
	for(int i=0;i<n;++i)cout<<ans[i]<<" ";
	return 0;
}