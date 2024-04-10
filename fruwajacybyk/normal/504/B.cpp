#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 200005

int N;
int fen[max_n];

void add(int k,int ile){
	while(k <=N){
		fen[k] += ile;
		k += (k & (-k));
	}
}

int quer(int k){
	int sum = 0;
	while(k>0){
		sum += fen[k];
		k -= (k & (-k));
	}
	return sum;
}

VI nr(VI v){
	N = v.size();
	FOR(i,0,N+1) fen[i] = 0;
	FOR(i,1,N+1) add(i,1);
	VI ans;
	FOR(i,0,N){
		ans.pb(quer(v[i]+1)-1);
		add(v[i]+1,-1);
	}
	return ans;
}


int main(){
	make(n);
	makev(v,n);
	makev(w,n);

	VI pov = nr(v);
	VI pow = nr(w);

	//debugv(pov);
	//debugv(pow);

	VI sum(n,0);
	int przen = 0;
	FORD(i,n-1,0){
		sum[i] = pov[i]+pow[i]+przen;
		if(sum[i] > n-1-i){
			sum[i] -= (n-i);
			przen  = 1;
		}
		else przen = 0;
	}

	//debugv(sum);

	N = n;
	FOR(i,0,N+1) fen[i] = 0;
	FOR(i,0,n) add(i+1,1);
	FOR(i,0,n){
		int l = 1; int p = n;
		while( p-l > 1){
			int mid = (l+p)>>1;
			if(quer(mid) < sum[i]+1) l = mid;
			else p = mid;
		}
		int fin = p;
		if(quer(l) >= sum[i]+1) fin = l;
		printf("%d ",fin-1);
		add(fin,-1);
	}
	printf("\n");
}