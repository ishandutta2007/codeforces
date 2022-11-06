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
const int N=2e5+11;
int B[N],n;
struct Ni{
	int a,id;
	bool operator<(const Ni&t)const{
		return a<t.a;
	}
}A[N];
int ans[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	n=rd();
	rep(i,1,n)B[i]=rd();
	rep(i,1,n)A[i].a=rd(),A[i].id=i;
	sort(B+1,B+n+1,cmp);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++){
		ans[A[i].id]=B[i];
	}
	rep(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
}