#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int T,x,y;
ll ans,c[7];
int main(){
	T=read();
	while(T--){
		x=read(),y=read();
		for(int i=1;i<=6;++i)c[i]=read();
		for(int k=1;k<=10;++k){
			for(int i=1;i<=6;++i){
				int l=(i==1?6:i-1),r=(i==6?1:i+1);
				c[i]=min(c[i],c[l]+c[r]);
			}
		}
		ans=0;
		if(x>=0&&y>=0){
			ans=c[1]*min(x,y)+(x>y?c[6]*(x-y):c[2]*(y-x));
		}
		else if(x<=0&&y<=0){
			ans=(x<y?-y*c[4]-(x-y)*c[3]:-x*c[4]-(y-x)*c[5]);
		}
		else if(x<=0&&y>=0){
			ans=c[3]*(-x)+c[2]*y;
		}
		else{
			ans=c[6]*x+c[5]*(-y);
		}
		printf("%lld\n",ans);
	}
	return 0;
}