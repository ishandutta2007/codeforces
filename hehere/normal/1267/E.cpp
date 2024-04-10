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
int n,m,a[105][105];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	int res=m;
	for(i=0;i<n-1;++i){
		int s[105];
		for(j=0;j<m;++j){
			s[j]=a[j][i]-a[j][n-1];
		}
		sort(s,s+m);
		reverse(s,s+m);
		int sum=0;
		for(j=0;j<m;++j){
			sum+=s[j];
			if(sum<0) break;
		}
		UMIN(res,m-j);
	}
	for(i=0;i<n-1;++i){
		pii s[105];
		for(j=0;j<m;++j){
			s[j]=mpr(a[j][i]-a[j][n-1],j);
		}
		sort(s,s+m);
		reverse(s,s+m);
		int sum=0;
		for(j=0;j<m;++j){
			sum+=s[j].FS;
			if(sum<0) break;
		}
		if(m-j==res){
			printf("%d\n",res);
			for(k=j;k<m;++k){
				printf("%d ",s[k].SC+1);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}