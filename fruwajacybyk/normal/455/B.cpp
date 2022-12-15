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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define max_n 100005


using namespace std;

int akt= 1;
int synowie[max_n][30];
char s[max_n];

int dfs1(int u){
	FOR(i,0,28){
		if(synowie[u][i]!=-1){
			if(dfs1(synowie[u][i])==0) return 1;
		}
	}
	return 0;
}

int dfs2(int u){
	int dzieci = 0;
	FOR(i,0,28){
		if(synowie[u][i]!=-1){
			if(dfs2(synowie[u][i])==0) return 1;
			dzieci++;
		}
	}
	if(dzieci==0) return 1;
	return 0;
}


int main(){
	int n,k; scanf("%d%d",&n,&k);
	FOR(i,0,max_n) FOR(j,0,30) synowie[i][j] = -1;

	FOR(i,0,n){
		scanf("%s",s);
		int u = strlen(s);
		int ja = 0;
		FOR(k,0,u){
			if(synowie[ja][s[k]-'a']!= -1)
				ja = synowie[ja][s[k]-'a'];
			else{
				synowie[ja][s[k]-'a'] = akt; 
				ja = akt;
				akt++;
			}
		}
	}

	int g1 = dfs1(0);
	int g2 = dfs2(0); 

	if(g1==1 && g2==1){
		cout<<"First"<<endl;
	}
	else if(g1==1 && g2==0){
		if(k%2==1) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	else if(g1==0){
		cout<<"Second"<<endl;
	}

			
}