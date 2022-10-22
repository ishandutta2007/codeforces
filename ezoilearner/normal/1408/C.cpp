#include<bits/stdc++.h>
using namespace std;
int n,l;
#define Maxn 100010
int a[Maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&l);double ans=0.0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);a[n+1]=l;
		int at1=0,sp1=1,at2=n+1,sp2=1;
		double t1=0.0,t2=0.0;
		while(at1<at2-1){
			double tmp1=t1+1.0*(a[at1+1]-a[at1])/sp1;
			double tmp2=t2+1.0*(a[at2]-a[at2-1])/sp2;
			if(tmp1<tmp2){
				t1=tmp1;
				sp1++;
				at1++;
			}else{
				t2=tmp2;
				sp2++;
				at2--;
			}
		}
		double dis=a[at2]-a[at1];
		if(t1<t2)dis-=1.0*(t2-t1)*sp1;
		else dis-=1.0*(t1-t2)*sp2;
		ans=max(t1,t2)+dis/(sp1+sp2);
		printf("%.9lf\n",ans);
	}
	return 0;
}