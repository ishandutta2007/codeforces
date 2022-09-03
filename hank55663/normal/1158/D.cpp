#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int vis[2005];
pll operator-(const pll &a,const pll &b){
	return {a.x-b.x,a.y-b.y};
}

LL cross(const pll &a,const pll &b){
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
LL cross(const pll &a,const pll &b,const pll &c){
	return cross(a-c,b-c);
}
#define hypot HYPOT
long double hypot(LL x,LL y){
	return sqrt(x*x+y*y);
}
pdd operator/(const pll &a, long double f ){
	return {a.x/f,a.y/f};
}
long double operator*(const pll &a,const pll &b){
	pdd aa=a/hypot(a.x,a.y);
	pdd bb=b/hypot(b.x,b.y);
	return aa.x*bb.x+aa.y*bb.y;
}
int main(){
	int n;
	scanf("%d",&n);
	pair<pll,int> p[2005];
	for(int i = 0;i<n;i++){
		LL x,y;
		scanf("%lld %lld",&x,&y);
		p[i]=mp(mp(x,y),i+1);
	}
	sort(p,p+n);
	char c[2005];
	scanf("%s",c);
	vector<int> ans;
	ans.pb(p[0].y);
	vis[p[0].y]=1;
	pll last=p[0].x;
	pll now=p[1].x;
	int nowi=p[1].y;
	if(c[0]=='L')
		for(int i = 2;i<n;i++){
			if(cross(now,p[i].x,last)<0){
				now=p[i].x;
				nowi=p[i].y;
			}
		}
	else{
		for(int i = 2;i<n;i++){
			if(cross(now,p[i].x,last)>0){
				now=p[i].x;
				nowi=p[i].y;
			}
		}
	}
	#define ld long double
	vis[nowi]=1;
	ans.pb(nowi);
	for(int i = 1;c[i]!=0;i++){
		pll temp;
		int tempi=-1;
		if(c[i]=='L'){
			for(int j = 0;j<n;j++){
				if(!vis[p[j].y]){
					if(tempi==-1){
						tempi=p[j].y;
						temp=p[j].x;
					}
					else{
						if(cross(temp,p[j].x,now)<0){
							temp=p[j].x;
							tempi=p[j].y;
						}
					}
				}
			}
		}
		else{
			for(int j = 0;j<n;j++){
				if(!vis[p[j].y]){
					if(tempi==-1){
						tempi=p[j].y;
						temp=p[j].x;
					}
					else{
						if(cross(temp,p[j].x,now)>0){
							temp=p[j].x;
							tempi=p[j].y;
						}
					}
				}
			}
		}
		vis[tempi]=1;
		ans.pb(tempi);
		last=now;
		now=temp;
	}
	for(int i= 0;i<n;i++){
		if(!vis[p[i].y])
			ans.pb(p[i].y);
	}
	for(auto it:ans)
	printf("%d ",it);
	printf("\n");
	return 0;
}
/*
n = x*m+x=x*(m+1);

3
-1000000000 -1000000000
0 -1
1000000000 1000000000

*/