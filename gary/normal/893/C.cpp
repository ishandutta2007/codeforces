//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int c[100000+10];
int min_cost[100000+10];
int boss[100000+10];
int find_(int x){
	if(boss[x]==x){
		return x;
	}
	return boss[x]=find_(boss[x]);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		scanf("%d",&c[i]);
		boss[i]=i;
		min_cost[i]=c[i];
	}
	rb(i,1,m){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		if(find_(xi)!=find_(yi)){
			min_cost[find_(yi)]=min(min_cost[find_(yi)],min_cost[find_(xi)]);
			boss[find_(xi)]=find_(yi);
		}
	}
	LL res=0;
	rb(i,1,n){
		if(boss[i]==i){
			res+=min_cost[i];
		}
	}
	cout<<res<<endl;
	return 0;
}