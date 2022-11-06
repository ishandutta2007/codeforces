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
#define N 131072
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,l,r,q,x1,y1,x2,y2;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&l,&r,&q);
	rep(i,1,q){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if((y1<l)&&(y2<l)&&(x1!=x2))printf("%d\n",abs(x1-x2)+l*2-y1-y2);
		else if((y1>r)&&(y2>r)&&(x1!=x2))printf("%d\n",abs(x1-x2)+y1+y2-r*2);
		else printf("%d\n",abs(x1-x2)+abs(y1-y2));
	}
}