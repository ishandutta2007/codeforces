#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
const db pi=acos(-1),eps=1e-8;
struct point{db x,y;}a[100005];
db Dot(point x,point y){return x.x*y.x+x.y*y.y;}
db Cross(point x,point y){return x.x*y.y-x.y*y.x;}
db Dis(point x,point y){return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);}
point operator +(point x,point y){return {x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
int st[100005],top,n,st2[100005],top2,l[100005],r[100005],on[100005];
db R;
bool cmp(point x,point y){
	if(Cross(x-a[1],y-a[1]))return Cross(x-a[1],y-a[1])>0;
	return Dis(a[1],x)<Dis(a[1],y);
}
bool in(point a,point b,point c){
	db mx=(a.x+b.x)/2.0,my=(a.y+b.y)/2.0;
	db tox=-(b.y-a.y),toy=b.x-a.x,D=Dis(a,b);
	db dis=sqrt(R*R-D*0.25);
	D=sqrt(D);
	tox*=dis/D,toy*=dis/D;
	db ox=mx+tox,oy=my+toy;
	return (ox-c.x)*(ox-c.x)+(oy-c.y)*(oy-c.y)<=R*R+eps;
}
db Cirarea(point a,point b){
	db theta=asin(sqrt(Dis(a,b))/2/R);
	return theta*R*R-R*R*sin(2*theta)/2;
}
int main(){
	cin>>n>>R;
	if(n==1)return cout<<0<<'\n',0;
	int mny=1e9,mnx=1e9,mnp=0;
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf",&a[i].x,&a[i].y);
		if(a[i].y<mny)mny=a[i].y,mnx=a[i].x,mnp=i;
		else if(a[i].y==mny&&a[i].x<mnx)mnx=a[i].x,mnp=i;
	}
	swap(a[mnp],a[1]),sort(a+2,a+n+1,cmp);
	st[++top]=1,st[++top]=2;
	for(int i=3;i<=n;i++){
		while(top>1&&Cross(a[st[top]]-a[st[top-1]],a[i]-a[st[top-1]])<=eps)top--;
		st[++top]=i;
	}
	for(int i=2;i<=top;i++)r[st[i-1]]=st[i],l[st[i]]=st[i-1];
	l[st[1]]=st[top],r[st[top]]=st[1];
	queue<int> q;
	for(int i=1;i<=top;i++)on[st[i]]=1,q.push(st[i]);
	while(!q.empty()){
		int i=q.front();
		q.pop();
		if(!on[i])continue;
		if(!in(a[i],a[r[i]],a[l[i]])){
			if(in(a[l[i]],a[r[i]],a[i])){
				on[i]=0,q.push(l[i]),q.push(r[i]);
				r[l[i]]=r[i],l[r[i]]=l[i];
			}
			else {
				on[r[i]]=0,q.push(i),q.push(r[r[i]]);
				l[r[r[i]]]=i,r[i]=r[r[i]];
			}
		}
		else if(!in(a[l[i]],a[i],a[r[i]])){
			if(in(a[l[i]],a[r[i]],a[i])){
				on[i]=0,q.push(l[i]),q.push(r[i]);
				r[l[i]]=r[i],l[r[i]]=l[i];
			}
			else {
				on[l[i]]=0,q.push(l[l[i]]),q.push(i);
				r[l[l[i]]]=i,l[i]=l[l[i]];
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(on[i]){
			db ans=Cirarea(a[i],a[r[i]]);
			int x=r[i];
			while(x!=i){
				ans+=Cirarea(a[x],a[r[x]]);
				ans+=0.5*Cross(a[x]-a[i],a[r[x]]-a[i]);
				x=r[x];
			}
			printf("%.10Lf\n",ans);
			return 0;
		}
}