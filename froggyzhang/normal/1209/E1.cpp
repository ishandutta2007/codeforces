#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int T,n,m,ans;
int c[13];
struct Num{
	int p[13];
	int mx;
}a[2010];
bool cmp(Num x,Num y){
	return x.mx>y.mx;
}
int b[2010][13];
void dfs(int now,int c[]){
	if(now==min(n,m)+1){
		int tp=0;
		for(int i=1;i<=n;i++){
			tp+=c[i];
		}
		ans=max(ans,tp);
		return ;
	}
	int tmp[13]={};
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			tmp[j]=max(c[j],b[now][(i+j)%n+1]);
		} 
		dfs(now+1,tmp);
	}
}
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=m;i++){
			a[i].mx=0;
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[j].p[i]=read();
				a[j].mx=max(a[j].mx,a[j].p[i]);
			} 
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=min(n,m);i++){
			for(int j=1;j<=n;j++){
				b[i][j]=a[i].p[j];
			}
		}
		for(int i=1;i<=n;i++){
			c[i]=0;
		} 
		dfs(1,c);
		printf("%d\n",ans);
	}
	return 0;
}