#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,a[N];
char s[N];
void Solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
	}
	int ans=n;
	for(int t1=0;t1<=9;++t1){
		for(int t2=0;t2<=9;++t2){
			int p=0,tot=0;
			for(int i=1;i<=n;++i){
				if((p==0&&t1==a[i])||(p==1&&t2==a[i])){
					p^=1;
				}
				else{
					++tot;
				}
			}
			if(t1^t2&&p)++tot;
			ans=min(ans,tot);
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}