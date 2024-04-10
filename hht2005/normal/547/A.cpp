#include<bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x=1;
		y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y=(y-a/b*x);
	return t;
}
int T1[1000010],T2[1000010];
signed main() {
	//	freopen("water.in","r",stdin);
	//	freopen("water.out","w",stdout);
	int M,H1,A1,x1,y1,H2,A2,x2,y2,p1=0,p2=0,q1=0,q2=0,t1,t2;
	cin>>M;
	cin>>H1>>A1>>x1>>y1;
	cin>>H2>>A2>>x2>>y2;
	T1[t1=H1]=1,T2[t2=H2]=1;
	int s1,s2;
	for(int i=2;; i++) {
		t1=(1ll*t1*x1+y1)%M;
		if(t1==A1&&!p1)p1=i;
		if(T1[t1]) {
			q1=i-T1[t1];
			s1=T1[t1];
			break;
		}
		T1[t1]=i;
	}
	for(int i=2;; i++) {
		t2=(1ll*t2*x2+y2)%M;
		if(t2==A2&&!p2)p2=i;
		if(T2[t2]) {
			s2=T2[t2];
			q2=i-T2[t2];
			break;
		}
		T2[t2]=i;
	}
	if(p1==p2) {
		cout<<p1-1<<endl;
		return 0;
	}
	if(p1<s1&&p2<s2) {
		puts("-1");
		return 0;
	} else if(p1<s1) {
		if(p1>p2&&(p1-p2)%q2==0)printf("%lld\n",p1-1);
		else puts("-1");
		return 0;
	} else if(p2<s2) {
		if(p2>p1&&(p2-p1)%q1==0)printf("%lld\n",p2-1);
		else puts("-1");
		return 0;
	}
	int a=q1,b=q2,c=p2-p1,x,y;
	int t=exgcd(a,b,x,y);
	if(c%t) {
		puts("-1");
		return 0;
	}
	a=b/t;
	int ans=((x*c/t)%a+a)%a*q1+p1;
	while(ans<p1||ans<p2)ans+=q1;
	cout<<ans-1<<endl;
	return 0;
}