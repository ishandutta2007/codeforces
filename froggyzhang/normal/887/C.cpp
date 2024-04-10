#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ok !printf("YES\n")
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
int a[7][5];
inline bool samef(int x){
	for(int i=1;i<=4;++i){
		if(a[x][i]^a[x][1])return false;
	}
	return true;
}
inline bool same(int a,int b,int c,int d){
	return a==b&&a==c&&a==d;
}
int main(){
	for(int i=1;i<=6;++i){
		for(int j=1;j<=4;++j){
			a[i][j]=read();
		}
	}
	if(samef(4)&&samef(5)){
		if(same(a[1][1],a[1][3],a[2][2],a[2][4])&&same(a[2][1],a[2][3],a[3][2],a[3][4])&&same(a[3][1],a[3][3],a[6][1],a[6][3])&&same(a[6][2],a[6][4],a[1][2],a[1][4]))return ok;
		if(same(a[1][1],a[1][3],a[6][1],a[6][3])&&same(a[2][1],a[2][3],a[1][2],a[1][4])&&same(a[3][1],a[3][3],a[2][2],a[2][4])&&same(a[6][2],a[6][4],a[3][2],a[3][4]))return ok;
	}
	else if(samef(1)&&samef(3)){
		if(same(a[4][1],a[4][2],a[2][3],a[2][4])&&same(a[2][1],a[2][2],a[5][3],a[5][4])&&same(a[5][1],a[5][2],a[6][3],a[6][4])&&same(a[6][1],a[6][2],a[4][3],a[4][4]))return ok;
		if(same(a[4][1],a[4][2],a[6][3],a[6][4])&&same(a[2][1],a[2][2],a[4][3],a[4][4])&&same(a[5][1],a[5][2],a[2][3],a[2][4])&&same(a[6][1],a[6][2],a[5][3],a[5][4]))return ok;
	}
	else if(samef(2)&&samef(6)){
		if(same(a[1][1],a[1][2],a[5][1],a[5][3])&&same(a[5][2],a[5][4],a[3][1],a[3][2])&&same(a[3][3],a[3][4],a[4][2],a[4][4])&&same(a[4][1],a[4][3],a[1][3],a[1][4]))return ok;
		if(same(a[1][1],a[1][2],a[4][2],a[4][4])&&same(a[5][2],a[5][4],a[1][3],a[1][4])&&same(a[3][3],a[3][4],a[5][1],a[5][3])&&same(a[4][1],a[4][3],a[3][1],a[3][2]))return ok;
	}
	printf("NO\n");
	return 0;
}