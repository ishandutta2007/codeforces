#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,Q,a[N];
vector<pair<int,int> > q[N];
template<int P>
struct Data{
	int pos;
	array<int,P> z;
	Data():pos(),z{}{}
	Data(int p,array<int,P> _z):pos(p),z(_z){}
	friend bool operator < (const Data &a,const Data &b){
		return a.pos<b.pos;	
	}
};
Data<3> p3[N],a3[N];
Data<4> p4[N],a4[N];
int ans[N];
void Solve_3(){
	static int st[N],L[N],R[N],top;
	for(int i=1;i<=n;++i){
		L[i]=0,R[i]=n+1;
	}
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]>=a[st[top]])--top;
		if(top)L[i]=st[top];
		st[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;--i){
		while(top&&a[i]>=a[st[top]])--top;
		if(top)R[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		if(L[i]>=1&&R[i]<=n){
			p3[R[i]]=max(p3[R[i]],Data<3>(L[i],{L[i],i,R[i]}));
		}
	}
}
void Solve_4(){
	static int st1[N],top1,st2[N],top2,cnt[N];
	set<int> S;
	S.insert(n+1);
	for(int i=n;i>=1;--i){
		while(top1&&a[i]>a[st1[top1]]){
			int u;
			if(!--cnt[u=st1[top1]]){
				S.insert(u);
			}
			--top1;
		}
		st1[++top1]=i;
		while(top2&&a[i]<a[st2[top2]]){
			int u;
			if(!--cnt[u=st2[top2]]){
				S.insert(u);
			}
			--top2;
		}
		st2[++top2]=i;
		cnt[i]=2;
		int p1=lower_bound(st1+1,st1+top1+1,i,[&](int i,int j){return a[i]>a[j];})-st1-1;
		int p2=lower_bound(st2+1,st2+top2+1,i,[&](int i,int j){return a[i]<a[j];})-st2-1;
		if(!p1||!p2)continue;
		p1=st1[p1],p2=st2[p2];
		int x=*S.upper_bound(max(p1,p2));
		if(x<=n){
			p1=*upper_bound(st1+1,st1+top1+1,x,greater<int>());
			p2=*upper_bound(st2+1,st2+top2+1,x,greater<int>());
			p4[x]=max(p4[x],Data<4>(i,{i,min(p1,p2),max(p1,p2),x}));	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=Q;++i){
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(l,i);	
	}
	Solve_3();
	for(int i=1;i<=n;++i)a[i]=-a[i];
	Solve_3();
	for(int i=1;i<=n;++i)a[i]=-a[i];
	Solve_4();
	Data<3> mx3;
	Data<4> mx4;
	for(int i=1;i<=n;++i){
		mx3=max(mx3,p3[i]);
		mx4=max(mx4,p4[i]);
		for(auto [l,id]:q[i]){
			if(mx4.pos>=l)ans[id]=4,a4[id]=mx4;
			else if(mx3.pos>=l)ans[id]=3,a3[id]=mx3;
			else ans[id]=0;
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
		if(ans[i]==4){
			for(int j=0;j<4;++j){
				cout<<a4[i].z[j]<<' ';	
			}
		}
		else if(ans[i]==3){
			for(int j=0;j<3;++j){
				cout<<a3[i].z[j]<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}