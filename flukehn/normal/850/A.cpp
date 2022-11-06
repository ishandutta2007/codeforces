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
const int CH=5,N=111;
typedef long long ll;
int n;
struct node{
	int a[CH];
	node operator-(const node&t)const{
		node temp;
		rep(i,0,CH-1)temp.a[i]=a[i]-t.a[i];
		return temp;
	}
	ll operator*(const node&t)const{
		ll ret=0;
		rep(i,0,CH-1)ret+=1LL*a[i]*t.a[i];
		return ret;
	}
}p[N];
bool judge(int x){
	rep(i,1,n)if(i!=x){
		rep(j,1,n)if(j!=x&&j!=i){
			node s1=p[x]-p[i],s2=p[x]-p[j];
			ll tt=s1*s2;
			if(tt>0)return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	if(n>100) {
		puts("0");
		return 0;
	}
	rep(i,1,n){
		rep(j,0,CH-1){
			cin>>p[i].a[j];
		}	
	}
	if(n<=2){
		printf("%d\n",n);
		rep(i,1,n)printf("%d\n",i);
		return 0;
	}
	rep(i,1,n)if(judge(i)){
		puts("1");
		printf("%d\n",i);
		return 0;
	}
	puts("0");
}