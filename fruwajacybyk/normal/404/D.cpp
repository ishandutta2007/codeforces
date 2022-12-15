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

#define max_n 1000005


using namespace std;

int mod = 1e9+7;
char s[max_n];
int n;

int bomba[max_n];
int oczek[max_n];
int puste[max_n];




int main(){
	s[0] = '0';
	scanf("%s",s+1);
	n = strlen(s);
	bomba[0] = 0; oczek[0] = 1; puste[0] = 1;
	FOR(i,1,n){
		if(s[i]=='0'){
			oczek[i] = 0; 
			puste[i] = puste[i-1];
			bomba[i] = 0;
		}
		if(s[i]=='1'){
			oczek[i] = puste[i-1];
			puste[i] = bomba[i-1];
			bomba[i] = 0;
		}
		if(s[i]=='2'){
			oczek[i] = bomba[i-1];
			puste[i] = 0;
			bomba[i] = 0;
		}
		if(s[i]=='*'){
			oczek[i] = 0;
			puste[i] = 0;
			bomba[i] = (oczek[i-1]+bomba[i-1])%mod;
		}
		if(s[i]=='?'){
			oczek[i] = (bomba[i-1]+puste[i-1])%mod;
			puste[i] = (puste[i-1]+bomba[i-1])%mod;
			bomba[i] = (oczek[i-1]+bomba[i-1])%mod;
		}
	}
	int ans = (puste[n-1]+bomba[n-1])%mod;
	cout<<ans<<endl;

}