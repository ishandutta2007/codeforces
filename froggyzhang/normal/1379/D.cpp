#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int n,H,M,k;
struct Train{
	int h,m,id;
	bool operator <(const Train b)const{
		return m<b.m;
	}
}a[N];
int main(){
	n=read(),H=read(),M=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i].h=read(),a[i].m=read(),a[i].id=i;
		a[i+n]=a[i];
		a[i+n].m+=(a[i+n].m>=M/2?-M/2:M/2);
	}
	sort(a+1,a+(n<<1)+1);
	n<<=1;
	int mn=n+1,pos=1,anst=0,qwq=0;
	int i=1;
	while(a[i].m<k)++i;
	for(;i<=n;++i){
		while(a[pos].m<=a[i].m-k)++pos;
		if(mn>i-pos){
			mn=i-pos;
			anst=a[i].m;
			qwq=pos;
		}
	}
	printf("%d %d\n",mn,anst>=M/2?anst-M/2:anst);
	for(int i=qwq;i<=qwq+mn-1;++i){
		printf("%d ",a[i].id);
	}
	printf("\n");
	return 0;
}