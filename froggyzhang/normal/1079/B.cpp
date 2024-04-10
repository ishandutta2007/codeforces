#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 233
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
char s[N];
bool Solve(int x,int y){
	if(x*y<n)return false;
	int p=1;
	printf("%d %d\n",x,y);
	int t=(x-n%x)%x;
	for(int i=1;i<=x;++i){
		if(i<=t)putchar('*');
		else putchar(s[p++]);
		for(int j=2;j<=y;++j){
			putchar(s[p++]);
		}
		putchar('\n');
	}
	return true;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=5;++i){
		for(int j=1;j<=20;++j){
			if(Solve(i,j))return 0;
		}
	}
	return 0;
}