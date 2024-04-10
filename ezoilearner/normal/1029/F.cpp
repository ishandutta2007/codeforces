#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll a,b;
struct dd{ll p1,p2;}A[100010],B[100010],C[100010];
int cnt1=0,cnt2=0,cnt3=0;

int main(){
	cin>>a>>b;
	for(ll i=1;i*i<=(a+b);++i)
	if((a+b)%i==0)A[++cnt1]=(dd){i,(a+b)/i};
	for(ll i=1;i*i<=a;++i)
	if(a%i==0)B[++cnt2]=(dd){i,a/i};
	for(ll i=1;i*i<=b;++i)
	if(b%i==0)C[++cnt3]=(dd){i,b/i};
	int at1=0,at2=0;
	ll ans;
	for(register int i=1;i<=cnt1;++i){
		while(at1<cnt2&&B[at1+1].p1<=A[i].p1)at1++;
		while(at2<cnt3&&C[at2+1].p1<=A[i].p1)at2++;
		bool flag=false;
		if(B[at1].p2<=A[i].p2)flag=true;
		if(flag){ans=2*A[i].p1+2*A[i].p2;continue;}
		for(register int j=at2;j>=1;--j)
		if(C[j].p2<=A[i].p2){flag=true;break;}
		if(C[at2].p2<=A[i].p2)flag=true;
		if(flag){ans=2*A[i].p1+2*A[i].p2;continue;}
	}
	cout<<ans<<endl;
}