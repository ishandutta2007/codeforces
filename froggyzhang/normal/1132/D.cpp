#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll; 
#define N 200200
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,k;
ll a[N],b[N],l,r,ans;
struct laptop{
	ll elec,cost,w;
	bool operator <(const laptop b)const{
		return w^b.w?w>b.w:cost<b.cost;
	}
};
inline bool check(ll x){
	priority_queue<laptop> q;
	for(register int i=1;i<=n;++i){
		if(a[i]/b[i]<k){
			q.push((laptop){a[i],b[i],a[i]/b[i]});
		}
	}
	for(register int i=0;i<k;++i){
		if(q.empty())return true;
		laptop t=q.top();
		q.pop();
		if(t.w<i)return false;
		t.elec+=x,t.w=t.elec/t.cost;
		if(t.w<k)q.push(t);
	}
	return true;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	ans=-1;
	l=0,r=2e12+1;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}