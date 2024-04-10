#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 111
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
int n,buc[N],mx,ans; 
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		buc[x]=1;
		mx=max(mx,x);
	}
	for(int i=1;i<=mx;i++){
		if(buc[i]){
			ans++;
			for(int j=i;j<=mx;j+=i){
				buc[j]=0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}