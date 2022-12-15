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
#define max_n 100005

using namespace std;


int main(){
	int n;
	VI v; 
	scanf("%d",&n);
	FOR(i,0,n){
		int a; scanf("%d",&a);
		v.pb(a);
	}
	int pocz[max_n];
	int kon[max_n];

	if(n<3){
		printf("%d\n",n);
		return 0;
	}

	pocz[0] = 0;
	kon[n-1] = n-1;

	FOR(i,1,n){
		if(v[i]>v[i-1]) pocz[i] = pocz[i-1];
		else pocz[i] = i;
	}

	for(int i = n-2;i>=0;i--){
		if(v[i]<v[i+1]) kon[i] = kon[i+1];
		else kon[i] = i;
	}

	int best = 1;

	FOR(i,1,n-1){	
		if(v[i-1]+1<v[i+1]){
			best = max(best,kon[i+1]-pocz[i-1]+1);
		}
		else{
			best = max(best,kon[i+1]-i+1);
			best = max(best,i-pocz[i-1]+1);
		}
	}

	best = max(best,kon[1]+1);
	best = max(best,(n-1)-pocz[n-2]+1);


	printf("%d\n",best);



	

	
	


	return 0;
}