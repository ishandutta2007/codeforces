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
int sg[65];
int SG(int n,set<int> v){
	if(n==0)
	return 0;
	if(v.empty()&&sg[n]!=-1)
	return sg[n];
	int val[60];
	memset(val,0,sizeof(val));
	for(int i=1;i<=n;i++)
	{
		if(v.find(i)!=v.end())
		continue;
		if(n-i<i)
		val[SG(n-i,v)]=1;
		else{
			v.insert(i);
			val[SG(n-i,v)]=1;
			v.erase(i);
		}
	}
	for(int i=0;i<60;i++)
	if(val[i]==0)
	return i;
}
int main(){
	set<int> v;
	memset(sg,-1,sizeof(sg));
	for(int i=0,k=0;k<=60;i++){
		for(int j=-1;j<i&&k<=60;j++,k++)
		sg[k]=i;
	}
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans=ans^sg[a];
	}
	if(ans==0)
	printf("YES\n");
	else
	printf("NO\n");
}