#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int T,n,k,d,buc[N],a[N],ans;
int main(){
	T=read();
	while(T--){
		int u=0;
		n=read(),k=read(),d=read();
		ans=k;
		memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=d;i++){
			if(!buc[a[i]])u++;
			buc[a[i]]++;
		}
		ans=u;
		for(int i=d+1;i<=n;i++){
			if(!buc[a[i]])u++;
			buc[a[i]]++;
			if(buc[a[i-d]]==1)u--;
			buc[a[i-d]]--;
			ans=min(ans,u);
		}
		printf("%d\n",ans);
	}
	return 0;
}