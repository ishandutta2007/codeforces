#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 3030
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
int n,a[N],t,b[N],p,k,ans[N],an;
char s[N];
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='R')a[i]=1;
		else a[i]=-1;
	}
	memcpy(b,a,sizeof(a));
	while(1){
		bool ok=false;
		for(int i=1;i<n;++i){
			if(a[i]==1&&a[i+1]==-1){
				ok=true;
				++t;
				swap(a[i],a[i+1]);
				++i;
			}
		}
		if(!ok)break;
		++p;
	}
	if(t<k||k<p){
		printf("-1\n");
		return 0;
	}
	memcpy(a,b,sizeof(a));
	while(1){
		if(!k)break;
		int i=1;
		for(;i<n;++i){
			if(k==p)break;
			if(a[i]==1&&a[i+1]==-1){
				swap(a[i],a[i+1]);
				--k;
				printf("1 %d\n",i);
				++i;
			}
		}
		an=0;
		for(;i<n;++i){
			if(a[i]==1&&a[i+1]==-1){
				swap(a[i],a[i+1]);
				ans[++an]=i;
				++i;
			}
		}
		if(an){
			--k;
			printf("%d",an);
			for(int i=1;i<=an;++i){
				printf(" %d",ans[i]);
			}
			printf("\n");
		}
		--p;
	}
	return 0;
}