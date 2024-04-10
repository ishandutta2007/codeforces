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
#define max_n 1005

using namespace std;


int main(){
	int n;
	int mod = 1000*1000*1000+7;
	int pow[max_n];
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&pow[i]);
	FOR(i,0,n) pow[i]--;
	int f[max_n];
	f[0] = 1;
	FOR(i,1,n){
		f[i] = 1;
		FOR(j,pow[i],i) {
			f[i]+=(1+f[j]);
			f[i]%=mod;
		}
	}
	int res = 0;
	FOR(i,0,n){
		res+=f[i]+1;
		res%=mod;
	}
	printf("%d\n",res);

	return 0;
}