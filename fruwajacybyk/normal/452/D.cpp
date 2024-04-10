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

#define max_n 100005


using namespace std;


int main(){
	int k,n1,n2,n3,t1,t2,t3;
	scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);
	multiset<int> q1,q2,q3,qr1,qr2,qr3;
	

	FOR(i,0,n1) q1.insert(0);
	FOR(i,0,n2) q2.insert(0);
	FOR(i,0,n3) q3.insert(0);
	qr1 = q1;
	qr2 = q2;
	qr3 = q3;
	

	int T = 0;
	int wrzucone = 0;
	while(1){
		T = max(T, *q1.begin());
		T = max(T, *q2.begin()-t1);
		T = max(T, *q3.begin()-t1-t2);
		
		q1.erase(q1.begin());
		q2.erase(q2.begin());
		q3.erase(q3.begin());
		
		q1.insert(T+t1);
		q2.insert(T+t1+t2);
		q3.insert(T+t1+t2+t3);
		wrzucone++;
		if(wrzucone==k){
			printf("%d\n",T+t1+t2+t3);
			return 0;
		}
	}




	return 0;
}