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
int drink[2000007];
int f[2000007];
int num=0;
int ans[2000007];
int Find(int n){
	if(f[n]==n)
	return n;
	return f[n]=Find(f[n]);
}
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=2e6+6;i++)
	f[i]=i;
	int ok=1;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		a++;
		if(a>2e6)
		a=2e6;
		int fa=Find(a);
		if(fa==0)
		ok=0;
		else{
		drink[fa]++;
		if(drink[fa]==k)
		f[fa]=fa-1;
		}
	}
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		a++;
		if(a>2e6)
		a=2e6;
		int fa=Find(a);
		if(fa!=0){
			ans[num]=i+1;
			num++;
			drink[fa]++;
			if(drink[fa]==k)
			f[fa]=fa-1;
		}
	}
	if(ok==0)
	printf("-1\n");
	else
	{
		printf("%d\n",num);
		if(num>0){
		printf("%d",ans[0]);
		for(int i=1;i<num;i++)
		printf(" %d",ans[i]);
		printf("\n");
		}
	}
}