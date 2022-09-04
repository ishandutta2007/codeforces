#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
struct skill{
	LL a,i;
};
bool operator<(const skill &a,const skill &b){
	return a.a<b.a;
}
bool cmp(const skill &a,const skill &b){
	return a.i<b.i;
}
int main(){
	LL n,A,cf,cm,m;
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&A,&cm,&cf,&m);
	skill a[N];
	LL need[N];
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i].a),a[i].i=i;
	{
		LL sum=0;
		for(int i=0;i<n;i++)
		sum+=A-a[i].a;
		if(sum<=m){
			printf("%I64d\n",cf*A+cm*n);
			printf("%I64d",A);
			for(int i=1;i<n;i++)
			printf(" %I64d",A);
			printf("\n");
			return 0;
		}
		
	}
	sort(a,a+n);
	need[0]=0;
	for(int i=1;i<n;i++)
	need[i]=(a[i].a-a[i-1].a)*i+need[i-1];
	LL fir=0;
	for(fir=0;fir<n;fir++)
	if(need[fir]>m)
	break;
	fir--;
	LL ans=((m-need[fir])/(fir+1)+a[fir].a)*cf,ansa=0,ansfir=fir,ansl=(m-need[fir])/(fir+1)+a[fir].a;
	LL sum=0;
	for(int i=1;i<=n;i++){
		sum+=A-a[n-i].a;
	//	printf("%I64d\n",sum);
		if(sum>m){
			break;
		}
		for(;need[fir]+sum>m;fir--);
		fir=min(fir,n-i-1);
		LL compu=((m-need[fir]-sum)/(fir+1)+a[fir].a)*cf+i*cm;
	//	printf("%I64d %d\n",compu,i);
		if(compu>ans){
			ans=compu;
			ansa=i;
			ansfir=fir;
			ansl=(m-need[fir]-sum)/(fir+1)+a[fir].a;
		}
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=ansa;i++)
	a[n-i].a=A;
	for(int i=0;i<=ansfir;i++)
	a[i].a=ansl;
	sort(a,a+n,cmp);
	printf("%I64d",a[0].a);
	for(int i=1;i<n;i++)
	printf(" %I64d",a[i].a);
	printf("\n");
}