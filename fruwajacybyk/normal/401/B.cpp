#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

int f2(PII p, PII q){
	return q.st-p.nd-1;
}

int f1(PII p, PII q){
	return (q.st-p.nd)/2;
}




int main(){
	int x,k;
	scanf("%d%d",&x,&k);
	vector<PII> v;
	FOR(i,0,k){
		int u,vv,w;
		scanf("%d",&u);
		if(u==1){
			scanf("%d%d",&vv,&w);
			v.pb(mp(vv,w));
		}
		if(u==2){
			scanf("%d",&vv);
			v.pb(mp(vv,vv));
		}
	}
	v.pb(mp(0,0));
	v.pb(mp(x,x));
	sort(v.begin(),v.end());
	int mini = 0;
	int maxi = 0;
	
	PII p = v[0];
	FOR(i,1,v.size()){
		mini += f1(p,v[i]);
		maxi += f2(p,v[i]);
		p = v[i];
	}

	printf("%d %d\n",mini,maxi);




	return 0;
}