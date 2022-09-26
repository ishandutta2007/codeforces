#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1234
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
int T,n,m;
struct P{
	int t,x,y;
}a[N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int l=m,r=m;
		for(int i=1;i<=n;i++){
			a[i].t=read(),a[i].x=read(),a[i].y=read();
		} 
		bool ok=true;
		for(int i=1;i<=n;i++){
			int qwq=a[i].t-a[i-1].t;
			l-=qwq,r+=qwq;
			if(a[i].y<l||a[i].x>r){
				printf("NO\n");
				ok=false;
				break;
			}
			l=max(l,a[i].x),r=min(r,a[i].y);
		}
		if(ok)printf("YES\n");
	}
	return 0;
}