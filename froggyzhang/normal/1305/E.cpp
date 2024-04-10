#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 23333
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
int n,m,a[N],an;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		if(m>=(i-1)/2){
			m-=(i-1)/2;
			a[++an]=i;
		}
		else break;
	}
	if(an==n&&m>0){
		printf("-1\n");
		return 0;
	}
	if(m){
		int cnt=0;
		for(int i=a[an]+1;;i++){
			if(m==(a[an]-cnt)/2){
				a[++an]=i;
				break;
			}
			++cnt;
		}
	}
	for(int i=1;i<=an;i++){
		printf("%d ",a[i]);
	}
	int res=n-an;
	an=0;
	int pp=1e9-1;
	for(int i=1;i<=res;i++){
		a[++an]=pp;
		pp-=23333;
	}
	sort(a+1,a+an+1);
	for(int i=1;i<=an;i++){
		printf("%d ",a[i]);
	}
	return 0;
}