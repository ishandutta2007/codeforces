#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int n,x,k;
	scanf("%d %d %d",&n,&x,&k);
	int a[100005];
	map<int,int> m;
	map<int,vector<int> >m1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		//a[i]=3;
		m1[(a[i]-1)/x].pb(a[i]);
	}
	for(auto it=m1.begin();it!=m1.end();it++){
		sort(it->y.begin(),it->y.end());
	}
	LL res=0;
	for(int i=0;i<n;i++){
		res+=upper_bound(m1[a[i]/x-k].begin(),m1[a[i]/x-k].end(),a[i])-m1[a[i]/x-k].begin(); 
	}
	/*for(auto it=m.begin();it!=m.end();it++){
		res+=(LL)it->y*;
	//	printf("%d %d\n",it->x,m1[it->x+k]);
	}*/
	printf("%I64d\n",res);
}/*
int prime[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67}
int main(){
	int n;
	scanf("%d",&n);
	int cnt[71];
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	
}*/