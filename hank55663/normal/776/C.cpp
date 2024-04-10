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
int main(){
	LL n,k;
	scanf("%I64d %I64d",&n,&k);
	LL power[100],num=0;
	if(k!=1&&k!=-1)
	for(LL i=1;i<1e16&&i>-1e16;i*=k,num++) 
	power[num]=i;
	else if(k==1){
		power[0]=1;
		num=1;
	}
	else if(k==-1){
		power[0]=1;
		power[1]=-1;
		num=2;
	}
	LL a[N];
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i]);
	map<LL,int> m;
	m[0]=1;
	LL sum=0;
	LL ans=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		for(int j=0;j<num;j++)
		ans+=m[sum-power[j]];
		m[sum]++;
	}
	printf("%I64d\n",ans);
}