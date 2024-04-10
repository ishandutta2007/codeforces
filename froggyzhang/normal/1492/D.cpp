#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int a,b,k,ans1[200020],ans2[200020];
int main(){
	a=read(),b=read(),k=read();
	if(b==1||!a){
		printf(k?"No\n":"Yes\n");
		if(!k){
			for(int i=1;i<=b;++i)putchar('1');
			for(int i=1;i<=a;++i)putchar('0');
			putchar('\n');
			for(int i=1;i<=b;++i)putchar('1');
			for(int i=1;i<=a;++i)putchar('0');
			putchar('\n');
		}
	}
	else{
		printf(k>=a+b-1?"No\n":"Yes\n");
		if(k<a+b-1){
			ans1[k+1]=ans2[1]=1;
			for(int j=1,i=a+b;j<b;++j,--i){
				if(i==k+1){--j;continue;}
				ans1[i]=1;
			}
			for(int j=1,i=a+b;j<b;++j,--i){
				if(i==k+1){--j;continue;}
				ans2[i]=1;
			}
			for(int i=a+b;i>=1;--i){
				putchar(ans1[i]+'0');
			}
			putchar('\n');
			for(int i=a+b;i>=1;--i){
				putchar(ans2[i]+'0');
			}
			putchar('\n');
		}
	}
	return 0;
}