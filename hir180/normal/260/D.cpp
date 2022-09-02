#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
struct V{
	int n,col,sum;
};
struct edge{
	int u,v,co;
};
bool comp(V n1,V n2){
	return n1.sum>n2.sum;
}
vector<edge> go;
vector<V> b,w;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,aa;
		scanf("%d%d",&a,&aa);
		if(!a){
			V c;
			c.n=i+1;
			c.col=0;
			c.sum=aa;
			w.push_back(c);
		}
		else{
			V c;
			c.n=i+1;
			c.col=1;
			c.sum=aa;
			b.push_back(c);
		}
	}
	sort(w.begin(),w.end(),comp);
	sort(b.begin(),b.end(),comp);
	int x=0,y=0;
	while(x<w.size() && y<b.size()){
		int pi=min(w[x].sum,b[y].sum);
		edge r;
		r.u=w[x].n;
		r.v=b[y].n;
		r.co=pi;
		go.push_back(r);
		w[x].sum-=pi;
		b[y].sum-=pi;
		if(x==w.size()-1 && y==b.size()-1) break;
		if(w[x].sum==0 && x!=w.size()-1) x++;
		else if(b[y].sum==0 && y!=b.size()-1) y++;
	}
	for(int i=0;i<n-1;i++){
		printf("%d %d %d\n",go[i].u,go[i].v,go[i].co);
	}
	scanf("\n");
}