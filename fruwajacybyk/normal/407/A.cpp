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
	int a,b;
	scanf("%d%d",&a,&b);
	vector<PII> da,db;
	FOR(i,1,a){
		int j = sqrt(a*a-i*i);
		FOR(t,-1,2){
			if((j+t)*(j+t)+i*i==a*a){
				if(j+t>0 && j+t<a){
					da.pb(mp(j+t,i));
					da.pb(mp(i,j+t));
				}
			}
		}
	}
	FOR(i,1,b){
		int j = sqrt(b*b-i*i);
		FOR(t,-1,2){
			if((j+t)*(j+t)+i*i==b*b){
				if(j+t>0 && j+t<b){
					db.pb(mp(j+t,i));
					db.pb(mp(i,j+t));
				}
			}
		}
	}

	bool flaga = false;
	FOR(i,0,da.size()){
		FOR(j,0,db.size()){
			int x,y,z,t;
			x = da[i].st; y = da[i].nd;
			z = db[j].st; t = db[j].nd;
			if(x*z==y*t && y!=t){
				printf("YES\n");
				printf("%d %d\n%d %d\n%d %d\n",-x,y,0,0,z,t);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}