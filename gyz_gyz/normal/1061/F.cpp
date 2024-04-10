#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
struct pr{int l,r,x;};
int n,k,t;map<pr,bool>mp;
bool operator <(pr x,pr y){
	if(x.l!=y.l)return x.l<y.l;
	if(x.r!=y.r)return x.r<y.r;
	return x.x<y.x;
}
bool qs(int l,int r,int x){
	if(l==x||r==x)return 1;
	if(l==r)return 0;
	if(l>r)swap(l,r);pr pp={l,r,x};
	if(!mp.count(pp)){string str;
		printf("? %d %d %d\n",l,x,r);
		fflush(stdout);cin>>str;
		mp[pp]=str[0]=='Y';
	}
	return mp[pp];
}
int cp(int x,int y){int r=0;
	rep(i,1,n)if(qs(y,i,x))r++;
	if(r==t){
		printf("! %d\n",x);exit(0);
	}return r;
}
void ck(int x,int y){
	rep(i,1,n)if(i!=x&&i!=y&&qs(x,y,i)){
		int r=cp(i,x);
		if(r>t)x=i;else y=i;
	}
	cp(x,y);cp(y,x);
}
int main(){srand(time(0));
	scanf("%d%d",&n,&k);t=n-(n-1)/k;
	for(;;)ck(rand()%n+1,rand()%n+1);
}