#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 4000200
typedef long long ll;
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
int n,a[N],T,m,dep[N],op[N];
ll ans;
#define ls i<<1
#define rs i<<1|1
void Del(int i){
	if(!a[ls]&&!a[rs]){
		a[i]=0;
		return;
	}
	if(a[ls]>a[rs]){
		a[i]=a[ls];
		Del(ls);
	}
	else{
		a[i]=a[rs];
		Del(rs);
	}
}
int check(int i){
	if(!a[ls]&&!a[rs]){
		return dep[i];
	}
	if(a[ls]>a[rs])return check(ls);
	return check(rs);
}
int main(){
	T=read();
	dep[1]=1;
	for(int i=2;i<=(1<<20);++i){
		dep[i]=dep[i>>1]+1;
	}
	while(T--){
		n=read(),m=read(),ans=0;
		for(int i=1;i<=(1<<n)-1;++i){
			a[i]=read(),ans+=a[i];
		}
		int u=1;
		int tot=(1<<n)-(1<<m);
		for(int i=1;i<=tot;++i){
			while(!u||check(u)<=m)++u;
			ans-=a[u];
			Del(u),op[i]=u;
		}
		printf("%I64d\n",ans);
		for(int i=1;i<=tot;++i){
			printf("%d ",op[i]);
		}
		printf("\n");
		for(int i=1;i<=(1<<n)-1;++i)a[i]=0;
	}
	return 0;
}