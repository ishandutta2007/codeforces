#include<bits/stdc++.h>
using namespace std;
const int N=1011;
double ex[N],ey[N],r;
int n;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>r;
	for(int i=0;i<n;++i){
		cin>>ex[i];
		double y=r;
		for(int j=0;j<i;++j){
			if(abs(ex[i]-ex[j])>2*r)continue;
			double ly=ey[j];
			double ry=ly+4*r;
			for(int t=0;t<30;++t){
				double my=(ly+ry)*0.5;
				double d=sqrt((ex[i]-ex[j])*(ex[i]-ex[j])+(my-ey[j])*(my-ey[j]));
				if(d>=2*r){
					ry=my;
				}else{
					ly=my;
				}
			}
			y=max(y,ly);
		}
		ey[i]=y;
		printf("%.12f%c",y," \n"[i+1==n]);
	}
}