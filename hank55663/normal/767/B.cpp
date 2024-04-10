#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include<assert.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	LL ts,tf,t;
	scanf("%I64d %I64d %I64d",&ts,&tf,&t);
	int n;
	scanf("%d",&n);
	LL a[100005];
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i]);
	a[n]=tf-t+1;
	sort(a,a+n+1);
	LL min=1e15,mina;
	for(int i=0;i<=n;i++){
		
		if(ts+t>tf)
		break;//printf("%d %d\n",a[i],ts);
		if(max(ts-a[i]+1,0ll)<min){
			min=max(ts-a[i]+1,0ll);
			mina=a[i]-1;
		}
		ts+=t;
		ts=max(ts,a[i]+t);
	}
	printf("%I64d\n",mina);
}