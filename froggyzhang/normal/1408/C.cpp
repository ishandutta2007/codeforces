#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const double eps=1e-7;
#define N 100010
inline int read(){
    int x=0,f=1;
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
int T,n,Len,a[N];
inline bool check(double x){
	double L=0,R=Len,res=x,sp=1.0;
	for(int i=1;i<=n;++i){
		if(res>=(a[i]-L)/sp){
			res-=(a[i]-L)/sp;
			sp+=1.0,L=a[i];
		}
		else{
			L+=res*sp;
			res=0;
			break;
		}
	}
	L+=res*sp;
	res=x,sp=1.0;
	for(int i=n;i>=1;--i){
		if(res>=(R-a[i])/sp){
			res-=(R-a[i])/sp;
			sp+=1.0,R=a[i];
		} 
		else{
			R-=res*sp;
			res=0;
			break;
		}
	}
	R-=res*sp;
	return L>=R;
}
void Solve(){
	double ans=0,l=0,r=1e9+1;
	n=read(),Len=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid)){
			r=ans=mid;
		}
		else{
			l=mid;
		}
	}
	printf("%.8lf\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}