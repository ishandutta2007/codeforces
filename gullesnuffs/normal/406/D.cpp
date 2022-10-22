#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Hill{
	long long x, y;
	int d;
	int index;
	Hill *parent;
	Hill *parents[20];
	bool operator<(const Hill &other) const{
		return x < other.x;
	}
} hills[100005];

struct Edge{
	Hill *A, *B;
	Edge(Hill* a, Hill *b){
		A=a;
		B=b;
	}
	bool operator<(const Edge &other) const{
		long long dy=B->y-A->y;
		long long dx=B->x-A->x;
		long long otherdy=other.B->y-other.A->y;
		long long otherdx=other.B->x-other.A->x;
		return dy*otherdx < otherdy*dx;
	}
};

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%I64d%I64d", &hills[i].x, &hills[i].y);
		hills[i].index=i;
	}
	hills[n-1].d=0;
	vector<Edge*> V;
	for(int i=n-2; i >= 0; --i){
		Edge* search=new Edge(hills+i, hills+(i+1));
		while(!V.empty()){
			Edge *last = V[V.size()-1];
			search->B = last->A;
			if(!(*search < *last))
				break;
			search->B = last->B;
			V.pop_back();
		}
		V.push_back(search);
		hills[i].parent=search->B;
		hills[i].d=hills[i].parent->d+1;
		hills[i].parents[0]=hills[i].parent;
		for(int j=1; j < 20; ++j){
			if(hills[i].d >= (1<<j))
				hills[i].parents[j]=hills[i].parents[j-1]->parents[j-1];
		}
	}
	int m;
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		Hill *A, *B;
		A=hills+a;
		B=hills+b;
		if(A->d > B->d)
			swap(A, B);
		for(int j=19; j >= 0; --j){
			if(B->d-(1<<j) >= A->d)
				B=B->parents[j];
		}
		for(int j=19; j >= 0; --j){
			if(B->d < (1<<j))
				continue;
			if(B->parents[j] != A->parents[j]){
				B=B->parents[j];
				A=A->parents[j];
			}
		}
		if(A != B)
			A=A->parent;
		printf("%d ", A->index+1);
	}
	return 0;
}