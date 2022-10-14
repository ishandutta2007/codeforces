#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define B inline bool
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
const int N=2e3+1;
int n,a[N],b[N][N],id[N];
V input(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",a+i),id[i]=i;
}
B cmp(const int&x,const int&y){return a[x]>a[y];}
V work(){
	sort(id+1,id+1+n,cmp);
	FOR(i,1,n)FOR(j,i,i+a[id[i]]-1)b[j%(n+1)][id[i]]=1;
	cout<<n+1<<'\n';
	FOR(i,0,n){
		FOR(j,1,n)cout<<b[i][j];
		cout<<'\n';
	}
}
int main(){
	input();
	work();
	return 0;
}