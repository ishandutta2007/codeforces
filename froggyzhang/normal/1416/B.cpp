#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<tuple>
using namespace std;
#define N 100010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,a[N];
void Solve(){
	int ave=0;
	for(int i=1;i<=n;++i){
		ave+=a[i];
	}
	if(ave%n)return (void)printf("-1\n");
	ave/=n;
	vector<tuple<int,int,int> > ans;
	for(int i=2;i<=n;++i){
		if(a[i]%i){
			int x=i-a[i]%i;
			ans.emplace_back(1,i,x);
			a[i]+=x,a[1]-=x;
		}
		ans.emplace_back(i,1,a[i]/i);
		a[1]+=a[i],a[i]=0;
	}
	for(int i=2;i<=n;++i){
		ans.emplace_back(1,i,ave);
	}
	printf("%d\n",(int)ans.size());
	for(auto [i,j,k]:ans){
		printf("%d %d %d\n",i,j,k);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		Solve();
	}
	return 0;
}