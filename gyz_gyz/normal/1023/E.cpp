#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 100000
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n;char s[N],ch[9];
void f(int x,int y){
	if(x+y>n)return;
	printf("? %d %d %d %d\n",x,y+1,n,n);
	fflush(stdout);scanf("%s",ch);
	if(ch[0]=='Y'){s[x+y]='R';f(x,y+1);}
	else{s[x+y]='D';f(x+1,y);}
}
void g(int x,int y){
	if(x+y<n+2)return;
	printf("? %d %d %d %d\n",1,1,x-1,y);
	fflush(stdout);scanf("%s",ch);
	if(ch[0]=='Y'){s[x+y-1]='D';g(x-1,y);}
	else{s[x+y-1]='R';g(x,y-1);}
}
int main(){
	scanf("%d",&n);f(1,1);g(n,n);printf("! ");
	rep(i,2,n*2-1)printf("%c",s[i]);
}