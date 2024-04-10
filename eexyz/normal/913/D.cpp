#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct node{
	int a,t;
}b[N];
inline bool cmp(node aa,node bb){
	return aa.t<bb.t;
}
int tt[N],tot,t,n;
bool check(int x){
	tot=0;int i;long long sum=0;
	for(i=1;i<=n;++i)if(b[i].a>=x)tt[++tot]=b[i].t;
	sort(tt+1,tt+tot+1);
	if(tot<x)return 0;
	for(i=1;i<=x;++i)sum+=tt[i];
	return sum<=t;
}
void CHECK(int x){
	tot=0;int i;
	for(i=1;i<=n;++i)if(b[i].a>=x){
		b[++tot].t=b[i].t;
		b[tot].a=i;
	}
	sort(b+1,b+tot+1,cmp);
	cout<<x<<"\n"<<x<<"\n";
	for(i=1;i<=x;++i){
		cout<<b[i].a<<" ";
	}
}int l,r,i,mid;
int main(){
	cin>>n>>t;
	for(i=1;i<=n;++i)cin>>b[i].a>>b[i].t;
	l=0;r=n;
	while(l<r){
		mid=r-(r-l>>1);
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	CHECK(l);
}