#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
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
char s[2010];
int main(){
	scanf("%s",s+1);int n=strlen(s+1);
	printf("%s",s+1);
	For(i,n+1,n*2) printf("%c",s[n-(i-n)+1]);
}