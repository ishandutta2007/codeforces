#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=300011;
struct node{
	int v,id;
	bool operator<(const node&t)const{
		return v<t.v;
	}
};
priority_queue<node> Q;
int tt[N];
typedef long long ll;
ll ans;
int main(){
	int n=rd(),k=rd();
	rep(i,1,k){
		int a=rd();
		Q.push((node){a,i});
	}
	rep(i,k+1,n){
		int a=rd();
		Q.push((node){a,i});
		node x=Q.top();
		Q.pop();
		ans+=1LL*(i-x.id)*x.v;
		tt[x.id]=i;
	}
	rep(i,n+1,n+k){
		node x=Q.top();
		Q.pop();
		ans+=1LL*(i-x.id)*x.v;
		tt[x.id]=i;
	}
	cout<<ans<<endl;
	rep(i,1,n)printf("%d%c",tt[i]," \n"[i==n]);
}