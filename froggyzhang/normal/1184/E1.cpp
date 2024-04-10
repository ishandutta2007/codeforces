#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
struct edge{
	int s,t,d;
	bool operator<(const edge& y)const{
		return d<y.d;
	}
}e[MAXN];
int n,m,i,f[MAXN];
int get(int x){
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].d);
	sort(e+1,e+m);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<m;i++)
	if(get(e[i].s)!=get(e[i].t)){
		f[get(e[i].s)]=get(e[i].t);
		if(get(e[0].s)==get(e[0].t)){
			cout<<e[i].d<<endl;
			return 0;
		}
	}
	cout<<1000000000<<endl;
	return 0;
}