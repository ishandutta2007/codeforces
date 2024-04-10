#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
typedef unsigned long long ull;
const int N = 100000 + 5,mod=1e9+9;
const ull base = 163;
char s[N];
int h1[N],h2[N],p[N];
int n;
void init(){
    p[0] = 1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*base;
		h1[i]=h1[i-1]*base+s[i]-'a';
	}
	for(int i=n;i;i--){
		h2[i]=h2[i+1]*base+s[i]-'a';
	}
}
ull get1(int l, int r){
    return h1[r] - h1[l - 1] * p[r - l + 1];
}
ull get2(int l, int r){
    return h2[l] - h2[r + 1] * p[r - l + 1];
}
int f[N];
inline int solve(int l,int r){
	if(l==r)return 1;
	int mid=l+r>>1;
	if((r-l+1)&1){
		if(get1(l,mid-1)==get2(mid+1,r))
			return 1+solve(l,mid-1);
		else return 0;
	}
	else {
		if(get1(l,mid)==get2(mid+1,r))
			return 1+solve(l,mid);
		else return 0;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	init();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			f[solve(i,j)]++;
	}
	for(int i=n-1;i>=1;i--)
		f[i]+=f[i+1];
	for(int i=1;i<=n;i++)
		printf("%d%c",f[i]," \n"[i==n]);
}