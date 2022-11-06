#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,tot,x,p[N];char s[N],t[N],u;
int main(){
	scanf("%d",&n);scanf("%s",s);scanf("%s",t);
	rep(i,0,n-1){x=-1;
		rep(j,i,n-1)if(s[j]==t[i]){x=j;break;}
		if(x<0){printf("-1");return 0;}
		dep(j,x-1,i){
			u=s[j];s[j]=s[j+1];s[j+1]=u;p[++tot]=j+1;
		}
	}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d ",p[i]);
}