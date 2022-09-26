#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,a[N],ans,cnt[55],mx;
void Insert(int x){
	for(int i=0;i<=30;i++){
		if((x>>i)&1)cnt[i]++;
	}
}
void Del(int x){
	for(int i=0;i<=30;i++){
		if((x>>i)&1)cnt[i]--;
	}
}
int main(){
	n=read();mx=-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		Insert(a[i]);
	}
	for(int i=1;i<=n;++i){
		Del(a[i]);
		int tmp=0;
		for(int j=0;j<=30;j++){
			if(((a[i]>>j)&1)&&!cnt[j]){
				tmp+=(1<<j);
			}
		}
		if(tmp>mx){
			mx=tmp,ans=i;
		}
		Insert(a[i]);
	}
	printf("%d ",a[ans]);
	for(int i=1;i<=n;i++){
		if(ans==i)continue;
		printf("%d ",a[i]);
	}
	return 0;
}