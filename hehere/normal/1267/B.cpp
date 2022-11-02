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
int n;
char s[300005];
pii a[300005];
int main(){
	int i,j,k;
	scanf("%s",s);
	n=strlen(s);
	int cnt=0;
	for(i=0;i<n;){
		for(j=i;j<n;++j){
			if(s[j]!=s[i]) break;
		}
		a[cnt++]=mpr(s[i]-'A',j-i);
		i=j;
	}
	if(!(cnt&1)){
		printf("0\n");
		return 0;
	}
	int d=cnt/2;
	if(a[d].SC<2){
		printf("0\n");
		return 0;
	}
	for(i=1;i<=d;++i){
		if(a[d-i].FS!=a[d+i].FS || a[d-i].SC+a[d+i].SC<3){
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n",a[d].SC+1);
	return 0;
}