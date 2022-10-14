#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e4+1;
struct vec{
	int x,y;
	int sgn()const{return x?x>0:y>0;}
	void input(){scanf("%d%d",&x,&y);}
	vec operator-(const vec&u)const{return (vec){x-u.x,y-u.y};}
	ll operator^(const vec&u)const{return 1ll*x*u.y-1ll*y*u.x;}
	int operator<(const vec&u)const{
		if(sgn()!=u.sgn())return sgn()<u.sgn();
		else return (*this^u)<0;
	}
}a[N],b[N];
ll C(int n,int m){return !m?1:C(n,m-1)*(n-m+1)/m;}
ll ans;int n,p;
int main(){
	scanf("%d",&n);
	FOR(i,1,n)a[i].input();
	FOR(i,1,n){
		FOR(j,1,n)b[j-(j>i)]=a[j]-a[i];
		sort(b+1,b+n),p=1;
		FOR(j,1,n-1)b[j+n-1]=b[j];
		FOR(j,1,n-1){
			while(p<n+j-1&&(b[j]^b[p+1])<0)p++;
			ans+=C(p-j,2),p+=p<=j;
		}
	}
	cout<<(C(n,3)*(n-3)-ans)*(n-4)/2;
	return 0;
}