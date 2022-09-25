#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define N 200020
const int inf=0x3f3f3f3f;
const ld eps=1e-10,PI=acos(-1.0L);
inline ll read(){
	ll x=0,f=1;
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
	ld x,y;
	Point(ld _x=0,ld _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	ld angle(){ 
		ld t=atan2(y,x);
		if(t<-eps) t+=2*PI;
		return t;
	}
}O,A[N];
Point Get(){
	ld a=read(),b=read(),c=read(),s=a+b+c;
	return Point(a/s,b/s);
}
int cnt1,cnt2;
char op[2];
struct cmp{
	bool operator () (const ld &x,const ld &y) const {
		return x+eps<y;
	}
};
multiset<ld,cmp> st;
ld Go(ld x){
	x+=PI;
	if(x>=2*PI)x-=2*PI;
	return x;
}
void Ins(Point x){
	if(fabs(x.x)<eps&&fabs(x.y)<eps) return void(cnt1++);
	ld y=x.angle();
	if(st.find(y)==st.end()&&st.find(Go(y))!=st.end())cnt2++;
	st.insert(y);
}
void Del(Point x){
	if(fabs(x.x)<eps&&fabs(x.y)<eps)return void(cnt1--);
	ld y=x.angle();
	st.erase(st.find(y));
	if(st.find(y)==st.end()&&st.find(Go(y))!=st.end())cnt2--;
}
int main(){
	O=Get();
	int Q=read();
	while(Q--){
		scanf("%s",op);
		if(*op=='A') Ins(A[++n]=(Get()-O));
		else Del(A[read()]);
		int ans=0;
		if(cnt1)ans=1;
		else if(cnt2)ans=2;
		else{
			int f=1;
			if(st.empty())f=0;
			else{
				if(*st.rbegin()-*st.begin()<PI+eps)f=0;
				else{
					auto y=st.upper_bound(PI),x=y;
					--x;
					if(*x+2*PI-*y<PI+eps)f=0;
				}
			}
			if(f)ans=3;
		}
		printf("%d\n",ans);
	}
	return 0;
}