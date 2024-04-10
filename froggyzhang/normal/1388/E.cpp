#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 2020
const double inf=1e20;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
struct Point{
	int xl,xr,y;
	bool operator <(const Point b)const{
		return y>b.y;
	}
}p[N];
vector<pair<double,double> > myh,pre;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].xl=read(),p[i].xr=read(),p[i].y=read();
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(p[i].y==p[j].y)continue;
			double L=-(double)(p[i].xr-p[j].xl)/(p[i].y-p[j].y);
			double R=-(double)(p[i].xl-p[j].xr)/(p[i].y-p[j].y);
			pre.emplace_back(L,R);
		}
	}
	double ans=0;
	sort(pre.begin(),pre.end());
	for(auto now:pre){
		if(myh.empty()||myh.back().second<=now.first){
			myh.push_back(now);
		}
		else{
			myh.back().second=max(myh.back().second,now.second);
		}
	}
	if(myh.empty())myh.emplace_back(0.0,0.0); 
	int l=0,r=(int)myh.size();
	ans=inf;
	while(l<r){
		int mid=(l+r)>>1;
		double L=inf,R=-inf;
		for(int i=1;i<=n;++i){
			L=min(L,p[i].xl+p[i].y*myh[mid].first);
			R=max(R,p[i].xr+p[i].y*myh[mid].first);
		}
		double t1=R-L;
		L=inf,R=-inf;
		for(int i=1;i<=n;++i){
			L=min(L,p[i].xl+p[i].y*myh[mid].second);
			R=max(R,p[i].xr+p[i].y*myh[mid].second);
		}
		double t2=R-L;
		ans=min(ans,min(t1,t2));
		if(t1>t2){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}