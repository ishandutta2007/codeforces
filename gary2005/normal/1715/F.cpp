#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define mp pair<int,int>
using namespace std;
int n,m;
double Query(vector<mp> v){
	cout<<"? "<<v.size()<<endl;
	for(auto it:v) cout<<it.first<<' '<<it.second<<endl;
	fflush(stdout);
	double res;
	cin>>res;
	return res;
}
int main(){
	cin>>n>>m;
	vector<mp> ve;
	ve.emplace_back(0,0);
	rb(i,0,n-1) ve.emplace_back(i,1),ve.emplace_back(i,m);
	ve.emplace_back(n,1);
	ve.emplace_back(n,0);
	double X=Query(ve);
	ve.clear();
	ve.emplace_back(0,0);
	rb(i,0,m-1) ve.emplace_back(1,i),ve.emplace_back(n,i);
	ve.emplace_back(1,m);
	ve.emplace_back(0,m);
	double Y=Query(ve);
	double x,y;
	double l=0,r=m-1;
	if(l<r)
	rb(i,1,60){
		double mid=(l+r)/2;
		double D,U;
		D=(m-mid)/(m-1);
		U=(m-mid-1)/(m-1);
		D=min(D,1.0);
		double H=(D-U)*(m-1);
		if((U+D)*H/2+1-H>X) l=mid;
		else r=mid;
	}
	y=l;
	l=0,r=n-1;
	if(l<r)
	rb(i,1,60){
		double mid=(l+r)/2;
		double D,U;
		D=(n-mid)/(n-1);
		U=(n-mid-1)/(n-1);
		D=min(D,1.0);
		double H=(D-U)*(n-1);
		if((U+D)*H/2+1-H>Y) l=mid;
		else r=mid;
	}
	x=l;
	cout<<"! "<<fixed<<setprecision(15)<<x<<" "<<y<<endl;
	fflush(stdout);
	return 0;
}