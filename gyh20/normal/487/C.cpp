#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t;
inline bool check(re int x){
	re int xx=sqrt(x);
	for(re int i=2;i<=xx;++i)if(x%i==0)return 1;
	return 0;
}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*x*ans%n;
		x=1ll*x*x%n,y>>=1;
	}
	return ans;
}
int main(){
//	freopen("perm.in","r",stdin);
//	freopen("perm.out","w",stdout);
	t=1;
	while(t--){
		n=read();/*
		if(read()==1){
			if(n==1){
				puts("YES");
				puts("1");
				continue;
			}
			if(n&1)puts("NO");
			else{
				puts("YES");
				re int a=n,b=1;
				for(re int i=1;i<=(n>>1);++i){
					printf("%d %d",a,b);
					if(i!=(n>>1))putchar(' ');
					a-=2,b+=2;
				}
				puts("");
			}
		}
		else{*/
			if(n==4){
				puts("YES");
				puts("1 3 2 4");
				continue;
			}
			else if(n==1){
				puts("YES");
				puts("1");
				continue;
			}
			else if(n==2){
				puts("YES");
				puts("1 2");
				continue;
			}
			else if(check(n))puts("NO");
			else{
				puts("YES");
				re int sum=1;
				for(re int i=1;i<=n;++i){
					re int xx=1ll*i*ksm(sum,n-2)%n;
					if(xx==0)xx+=n;
					printf("%d",xx);
					if(i!=n)putchar(' ');
					sum=1ll*xx*sum%n;
				}
				puts("");
			}
		}
}