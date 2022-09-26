#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
int n,tmp[N],Fmin[N][22],Fmax[N][22];
struct lec{
	int al,ar,bl,br;
}a[N];
bool cmpa(lec x,lec y){
	return x.al<y.al;
}
bool Solve(){
	sort(a+1,a+n+1,cmpa);
	for(int i=1;i<=n;i++){
		tmp[i]=a[i].al;
		Fmin[i][0]=a[i].br,Fmax[i][0]=a[i].bl;
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			Fmin[i][j]=min(Fmin[i][j-1],Fmin[i+(1<<(j-1))][j-1]);
			Fmax[i][j]=max(Fmax[i][j-1],Fmax[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		int pos=upper_bound(tmp+1,tmp+n+1,a[i].ar)-tmp-1;
		if(pos<=i)continue;
		int k=log2(pos-i+1);
		int mx=max(Fmax[i][k],Fmax[pos-(1<<k)+1][k]);
		int mn=min(Fmin[i][k],Fmin[pos-(1<<k)+1][k]);
		if(mx>a[i].br||mn<a[i].bl){
			printf("NO\n");
			return false;
		}
	}
	return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].al=read(),a[i].ar=read(),a[i].bl=read(),a[i].br=read();
	}
	if(!Solve())return 0;
	for(int i=1;i<=n;i++){
		swap(a[i].al,a[i].bl);
		swap(a[i].ar,a[i].br);
	}
	if(!Solve())return 0;
	printf("YES\n");
	return 0;
}