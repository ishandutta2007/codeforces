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

#define max_n 200005


using namespace std;

char s[max_n];
char t[max_n];

int A[max_n];
int B[max_n];

int main(){
	scanf("%s",s);
	scanf("%s",t);
	
	int u = strlen(s);
	FOR(i,0,u) B[u-1-i] = s[i]-'0';
	
	int v = strlen(t);
	FOR(i,0,v) A[v-1-i] = t[i]-'0';



	int n = max(u,v);

	FOR(i,0,n) if(A[i]==B[i]) A[i]=B[i] = 0;

	int akt = 0;
	int ileA = 0;
	int ileB = 0;
	int kto = 0;
	
	FORD(i,n,0){
		if(A[i]==1 && i >=2){
			if(B[i-1]==0){
				cout<<"<"<<endl;
				return 0;
			}
			if(A[i-1]==1 || A[i-2]==1){
				cout<<"<"<<endl;
				return 0;
			}
			A[i]=0;
			A[i-1] = 1;
			A[i-2] = 1;
			if(A[i-1]==B[i-1]) A[i-1]=B[i-1]=0;
			if(B[i-2]==A[i-2]) A[i-2]=B[i-2]=0; 
		}
		if(B[i]==1 && i >=2){
			if(A[i-1]==0){
				cout<<">"<<endl;
				return 0;
			}
			if(B[i-1]==1 || B[i-2]==1){
				cout<<">"<<endl;
				return 0;
			}
			B[i]=0;
			B[i-1] = 1;
			B[i-2] = 1;
			if(A[i-1]==B[i-1]) A[i-1]=B[i-1]=0;
			if(B[i-2]==A[i-2]) A[i-2]=B[i-2]=0; 
		}
	}

	PII p1 = mp(A[1],A[0]);
	PII p2 = mp(B[1],B[0]);
	if(p1==p2){
		cout<<"="<<endl;
	}
	if(p1>p2){
		cout<<"<"<<endl;
	}
	if(p2>p1){
		cout<<">"<<endl;
	}




	
	

	


	return 0;
}