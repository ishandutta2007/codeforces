#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000
#define M 80000000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
pair<int,int>a[4];
int main(){
	rep(i,1,3)scanf("%d%d",&a[i].fr,&a[i].sc);
	sort(a+1,a+4);
	int tt=max(max(a[1].sc,a[2].sc),a[3].sc),ss=min(min(a[1].sc,a[2].sc),a[3].sc);
	printf("%d\n",a[3].fr-a[1].fr+tt-ss+1);
	rep(i,ss,tt)printf("%d %d\n",a[2].fr,i);
	rep(i,a[1].fr,a[2].fr-1)printf("%d %d\n",i,a[1].sc);
	rep(i,a[2].fr+1,a[3].fr)printf("%d %d\n",i,a[3].sc);
}