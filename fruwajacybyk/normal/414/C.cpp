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




int main(){
	int k;
	lint n;
	scanf("%d",&k);
	n = (1LL<<k);
	VI a;
	FOR(i,0,n) {
		int b; scanf("%d",&b);
		a.pb(b);
	}
	
	lint inv[25];
	lint row[25];
	FOR(i,0,25) inv[i] = 0;
	FOR(i,0,25) row[i] = 0;

	int step = 1;
	int log = 0;
	while(step!=n){
		for(int i=0;i<=n-2*step;i+=2*step){
			VI v;
			FOR(j,i,i+step) v.pb(a[j]);
			FOR(j,i+step,i+step+step){
				VI::iterator it = lower_bound(v.begin(),v.end(),a[j]);
				VI::iterator it2 = upper_bound(v.begin(),v.end(),a[j]);
				row[log]+=(it2-it);
				inv[log]+=(v.end()-it2);
			}
			sort(a.begin()+i,a.begin()+(i+2*step));
		}
		step*=2;
		log++;
	}


	int m;
	scanf("%d",&m);
	
	FOR(i,0,m){
		int q;
		scanf("%d",&q);
		FOR(j,0,q) inv[j] = ((1LL<<j)*n)/2-row[j]-inv[j]; 
		lint res = 0;
		FOR(j,0,k) res+=inv[j];
		printf("%I64d\n",res);
	//	cout<<res<<endl;
	}

		



	return 0;
}