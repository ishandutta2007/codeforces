#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#define rg register
#define il inline
#define vd void
#define ll long long
#define For(i,x,y) for (rg int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (rg int i=(x);i>=(y);i--)
#define cross(i,k) for (rg int i=first[k];i;i=last[i])
using namespace std;
il ll max(ll x,ll y){return x>y?x:y;}
il ll min(ll x,ll y){return x<y?x:y;}
il ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int n,a,b,A,B,ans[1000010];
int main(){
	n=read(),a=read(),b=read();
	int l=n/a;
	For(i,0,l)
		if ((n-i*a)%b==0){
			A=i,B=(n-i*a)/b;
			break;
		}
	if (!A&&!B) return printf("-1"),0;
	For(i,1,A){
		For(j,(i-1)*a+2,i*a) ans[j]=j-1;
		ans[(i-1)*a+1]=i*a; 
	}
	int k=A*a;
	For(i,1,B){
		For(j,k+(i-1)*b+2,k+i*b) ans[j]=j-1;
		ans[k+(i-1)*b+1]=k+i*b; 
	}
	For(i,1,n) printf("%d ",ans[i]);
}