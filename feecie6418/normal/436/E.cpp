#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Heap{
 
priority_queue<int> s1;
priority_queue<int,vector<int>,greater<int> > s2;
int K;
ll sum=0;
void Do(){
	while(s1.size()>K){
		int u=s1.top();
		s1.pop(),s2.push(u),sum-=u;
	}
	while(s1.size()<K&&s2.size()){
		int u=s2.top();
		s2.pop(),s1.push(u),sum+=u;
	}
}
void Ins(int x){
	s1.push(x),sum+=x,Do();
}
void Makek(int k){
	K=k,Do();
}
ll Query(){
	if(s1.size()<K)return 1e18;
	return sum;
}
void Clear(){
	priority_queue<int> t1;
	priority_queue<int,vector<int>,greater<int> > t2;
	swap(s1,t1),swap(s2,t2),sum=0;
}
 
}a1,a2;
int n,w,ans[300005];
ll f[300005];
struct Thing{
	int a,b,id;
}a[300005];
ll Get(int i,bool is=0){
	int j=w-2*i;
	a1.Clear(),a2.Clear();
	a1.Makek(i),a2.Makek(j);
	ll mn=1e18;
	int pos=0;
	for(int k=n+1;k>=1;k--){
		if(k<=n)a2.Ins(a[k].a);
		f[k]=a2.Query();
	}
	for(int k=0;k<=n;k++){
		if(k)a1.Ins(a[k].b);
		ll w=a1.Query()+f[k+1];
		if(w<mn)mn=w,pos=k;
	}
	if(is){
		cout<<mn<<'\n';
		vector<Thing> tmp;
		for(int k=1;k<=pos;k++)tmp.push_back(a[k]);
		sort(tmp.begin(),tmp.end(),[](Thing x,Thing y){return x.b<y.b;});
		for(int k=0;k<i;k++)ans[tmp[k].id]=2;
		tmp.clear();
		for(int k=pos+1;k<=n;k++)tmp.push_back(a[k]);
		sort(tmp.begin(),tmp.end(),[](Thing x,Thing y){return x.a<y.a;});
		for(int k=0;k<j;k++)ans[tmp[k].id]=1;
		for(int k=1;k<=n;k++)cout<<ans[k];
	}
	return mn;
}
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b),a[i].id=i;
	sort(a+1,a+n+1,[](Thing x,Thing y){return x.b-x.a<y.b-y.a;});
	int L=-1,R;
	for(int i=0;i<=n;i++){
		int j=w-2*i;
		if(j<0||i+j>n)continue;
		if(L==-1)L=i;
		R=i;
	}
	while(L<R){
		int mid=(L+R)/2;
		if(Get(mid)<Get(mid+1))R=mid;
		else L=mid+1;
	}
	Get(L,1);
}