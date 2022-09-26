#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200010
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
ll p[2],now,n,x[N],ans;
int main(){
	n=read();
	now=0;
	for(int i=1;i<=n;i++){
		x[i]=read();
		if(x[i]<0)now^=1;
		p[now]++;
	}
	now=0;
	for(int i=1;i<=n;i++){
		if(x[i]>0){
			ans+=p[now];//p[0]--;
			
		}
		else{
			ans+=p[now];//p[1]--;
			now^=1;
		}
		p[now]--;
	}
	printf("%I64d %I64d\n",n*(n+1)/2-ans,ans);
	return 0;
}