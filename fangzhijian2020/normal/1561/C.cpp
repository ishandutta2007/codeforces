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
int T,n,K[100005],x,a[100005];
struct node{
	int K,a;
	bool operator<(const node&b)const{
		return a<b.a;
	}
}t[100005];
bool check(int x){
	for(int i=1;i<=n;++i){
		if(x<t[i].a)return 0;
		x+=t[i].K;
	}
	return 1;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i){
			t[i].K=read();t[i].a=0;
			for(int j=1;j<=t[i].K;++j){
				x=read();t[i].a=max(t[i].a,x-j+2);
			}
		}
		sort(t+1,t+n+1);
		int l=1,r=1e9+1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<r+1<<"\n";
	}
	return 0;
}