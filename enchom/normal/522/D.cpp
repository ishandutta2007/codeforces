// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

struct quer {
	int z,k,id;

	bool operator<(const quer &Q) const {
		return k < Q.k;}
	};

struct node {
	int z,k,val;
	int son[2];
	};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		if(n.k-n.z == 1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.z+n.k)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T.size()-1);}
		}

	intervalac(int N) {
		node n;
		n.son[0] =n.son[1] =-1;
		n.z =0, n.k =N;
		n.val =OVER9000;
		T.dibs(2*N);
		T.push_back(n);
		constI(0);}

	void put(int akt, int pos, int val) {
		node n =T[akt];
		if(n.z == n.k-1) {
			T[akt].val =val;
			return;}
		if(T[n.son[0]].k > pos) put(n.son[0],pos,val);
		else put(n.son[1],pos,val);
		T[akt].val =min(T[n.son[0]].val,T[n.son[1]].val);}

	int get(int akt, int zac, int kon) { // poziciu s minimom
		node n =T[akt];
		if(n.k <= zac || kon <= n.z) return OVER9000;
		if(n.z == zac && n.k == kon) return n.val;
		return min(get(n.son[0],zac,min(kon,T[n.son[0]].k)),get(n.son[1],max(zac,T[n.son[1]].z),kon));}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	map<int,int> Ma;
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		Ma[a] =0;
		A[i] =a;}
	
	int a =0;
	ALL_THE(Ma,it) it->ss =a++;
	for(int i =0; i < N; i++) A[i] =Ma[A[i]];
	
	vector<quer> Q(M);
	for(int i =0; i < M; i++) {
		cin >> Q[i].z >> Q[i].k; 
		Q[i].id =i;}
	sort(begin(Q),end(Q));
	vector<int> ans(M);

	intervalac I(N+tisic);
	vector<int> last(a+tisic,-1);

	a =0;
	for(int i =0; i < M; i++) {
		while(a < Q[i].k) {
			int x =last[A[a]];
			if(x >= 0) I.put(0,x,a-x);
			last[A[a]] =a;
			a++;}
		ans[Q[i].id] =I.get(0,Q[i].z-1,Q[i].k);
		if(ans[Q[i].id] == OVER9000) ans[Q[i].id] =-1;}

	for(int i =0; i < M; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing