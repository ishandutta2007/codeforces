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

int n,m;
vector<PII> v;
bool moze[max_n];
int napoczatku[max_n];
VI pos;

bool check(int x){
	if(moze[x]==false) return false;
	int ilu = 0;
	int ja = 0;
	FOR(i,0,n) if(napoczatku[i]==1) ilu++;
	ja = napoczatku[x];
	if(ilu>0 && ja<0) return false;
	
	FOR(i,0,m){
		int kto = v[i].nd;
		int co = v[i].st;
		if(co==-1){
			ilu--;
			if(kto==x) ja = -1;
		}
		if(co==1){
			ilu++;
			if(kto==x) ja = 1;
		}
		if(ilu>0 && ja == -1) return false;
	}
	return true;

}

void wypisz(){
	sort(pos.begin(),pos.end());
	printf("%d\n",pos.size());
	if(pos.size()>0){
	FOR(i,0,pos.size()){
		printf("%d ",pos[i]+1);
	}
	printf("\n");
	}
}

int main(){

	scanf("%d%d\n",&n,&m);
	FOR(i,0,n) napoczatku[i] = 0;
	FOR(i,0,n) moze[i] = true;

	FOR(i,0,m){
		char C; int d;
		scanf("%c%d\n",&C,&d);
		d--;
		if(C=='+') v.pb(mp(1,d)); 
		else if(C=='-') v.pb(mp(-1,d));
		if(napoczatku[d]==0){
			if(C=='+') napoczatku[d] = -1;
			else napoczatku[d] = 1;
		}
	}
	int ilu = 0;
	FOR(i,0,n) if(napoczatku[i]==1) ilu++;

	FOR(i,0,n) if(napoczatku[i]==0) pos.pb(i);

	if(ilu>0){
		FOR(i,0,n) if(napoczatku[i]==-1) moze[i] = false;
	}

	FOR(i,0,m){
		int kto = v[i].nd;
		int co = v[i].st;
		if(co==-1){
			ilu--;
			if(ilu>0) moze[kto] = false;
		}
		if(co==1){
			if(ilu>0) moze[kto] = false;
			ilu++;
			if(ilu==1){
				if(check(kto)) pos.pb(kto);
				wypisz();
				return 0;
			}
		}
	}

	

	FOR(i,0,n) if(napoczatku[i]!=0 && moze[i]) pos.pb(i);
	wypisz();
	
	return 0;
}