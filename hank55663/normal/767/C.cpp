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
vector<int> v[1000006];
int light[1000006];
int ssum[1000006];
int Sum=0;
int ook=0;
int ansa,ansb;
pair<int,bool> dfs(int n,int f){
	//printf("%d",n);
	int sum=light[n];
	int ok=0;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(*it!=f){
			pair<int,bool> p=dfs(*it,n);
			sum+=p.x;
			ok=ok|p.y;
			if(ook)
			return mp(0,0);
		}
	}
	if(ok&&sum==2*Sum&&f!=0){
		ook=1;
		ansb=n;
		return mp(0,0);
	}
	if(sum==Sum&&f!=0){
		if(ok==0&&ansa!=0)
		{
			ansb=n;
			ok=1;
			ook=1;
			return mp(0,0);
		}
		else
		ansa=n,ok=1;
		
	}//printf("%d %d",n,sum);
	return mp(sum,ok);
} 
int main(){
	int n;
	ansa=0,ansb=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d %d",&a,&light[i]);
		v[a].pb(i);
		//printf("%d",a,light[i]);
		Sum+=light[i];
	}
	if(Sum%3!=0)
	printf("-1\n");
	else{
		Sum/=3;
		dfs(0,0);
		if(ook)
		printf("%d %d\n",ansa,ansb);
		else
		printf("-1\n");
	}
}