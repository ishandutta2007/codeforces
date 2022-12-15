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
	int n,m,x,y,z,p;
	scanf("%d%d%d%d%d%d",&m,&n,&x,&y,&z,&p);
	FOR(i,0,p){
		int a,b;
		scanf("%d%d",&a,&b);
		x = x%4;
		y = y%2;
		z = z%4;
		
		int nloc = n;
		int mloc = m;

		FOR(j,0,x){
			int b1 = mloc+1-a; 
			a = b;
			b = b1;
			swap(nloc,mloc);
		}
		FOR(j,0,y){
			b = nloc+1-b;
		}
		
		FOR(j,0,z){
			int a1 = nloc+1-b;
			b = a;
			a = a1;

			swap(nloc,mloc);
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}