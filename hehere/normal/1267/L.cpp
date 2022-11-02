#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > pii;
typedef long long LL;
#define mpr make_pair
#define FS first
#define SC second
#define PB push_back
template < typename T > T MAX(T a,T b){return (a>b)?a:b;}
template < typename T > T MIN(T a,T b){return (a<b)?a:b;}
template < typename T > void UMAX(T &a,T b){a=(a>b?a:b);}
template < typename T > void UMIN(T &a,T b){a=(a<b?a:b);}
int readint(){
	char c=getchar();
	int ret=0;
	while(!(c>='0' && c<='9')) c=getchar();
	while(c>='0' && c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void putint(int v){
	if(!v){
		putchar('0');
		return;
	}
	if(v>=10) putint(v/10);
	putchar('0'+(v%10));
}
int n,l,d;
char s[1000005],r[1005][1005];
int main(){
	int i,j,k;
	scanf("%d%d%d",&n,&l,&d);
	scanf("%s",s);
	sort(s,s+n*l);
	int ptr=0,t=0;
	for(i=0;i<l;++i){
		for(j=t;j<d;++j){
			r[i][j]=s[ptr++];
		}
		while(r[i][t]!=r[i][d-1]) ++t;
	}
	for(i=0;i<l;++i){
		for(j=0;j<n;++j){
			if(!r[i][j]) r[i][j]=s[ptr++];
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<l;++j){
			printf("%c",r[j][i]);
		}
		printf("\n");
	}
	return 0;
}