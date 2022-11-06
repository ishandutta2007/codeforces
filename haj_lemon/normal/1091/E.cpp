#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
bool comp(const int &a,const int &b){return a>b;}
struct seg{int l,r,su,s1;}t[N*4];
int n,a[N],ansmi,ansma;
void build(int nu,int l,int r){
	t[nu].l=l;t[nu].r=r;t[nu].su=0;t[nu].s1=r-l+1;
	if (t[nu].l!=t[nu].r){build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);}
}
void add(int nu,int y,int z){
	if (!y) return ;
	if (t[nu].l==t[nu].r)t[nu].su+=z;
	else{
		if (y<=(t[nu].l+t[nu].r)/2)add(nu*2,y,z);else add(nu*2+1,y,z);
		t[nu].su=t[nu*2].su+t[nu*2+1].su;
		t[nu].s1=t[nu*2].s1+t[nu*2+1].s1;
	}
}
int delma(int nu){
	if (t[nu].l==t[nu].r){
		t[nu].su--;
		return t[nu].l;
	}else{
		int x;
		if (t[nu*2+1].su!=0)x=delma(nu*2+1);else x=delma(nu*2);
		t[nu].su=t[nu*2].su+t[nu*2+1].su;
		t[nu].s1=t[nu*2].s1+t[nu*2+1].s1;
		return x;
	}
}
int que1(int nu,int l,int r){
	if (l>r) return 0;
	if (t[nu].l==l&&t[nu].r==r)return t[nu].su;
	int mid=(t[nu].l+t[nu].r)/2;
	if (l>mid)return que1(nu*2+1,l,r);
	if (r<=mid)return que1(nu*2,l,r);
	return que1(nu*2,l,mid)+que1(nu*2+1,mid+1,r); 
}
int que2(int nu,int l,int r){
	if (l>r)return 0;
	if (t[nu].l==l&&t[nu].r==r)return t[nu].s1;
	int mid=(t[nu].l+t[nu].r)/2;
	if (l>mid)return que2(nu*2+1,l,r);
	if (r<=mid)return que2(nu*2,l,r);
	return que2(nu*2,l,mid)+que2(nu*2+1,mid+1,r); 
}
int que(int nu,int w){
	if (t[nu].l==t[nu].r) return t[nu].l;
	if (w>t[nu*2+1].su) return que(nu*2,w-t[nu*2+1].su);
	return que(nu*2+1,w);
}
int quew(int nu,int su){
	if (t[nu].l==t[nu].r)return t[nu].l;
	if (t[nu*2].s1<su) return quew(nu*2+1,su-t[nu*2].s1);
	else return quew(nu*2,su);
}
void fei(int nu,int we){
	if (t[nu].l==t[nu].r){t[nu].s1=0;t[nu].su=0;}
	else{
		if (we<=(t[nu].l+t[nu].r)/2)fei(nu*2,we);else fei(nu*2+1,we);
		t[nu].su=t[nu*2].su+t[nu*2+1].su;
		t[nu].s1=t[nu*2].s1+t[nu*2+1].s1;
	}
}
void del(int x){
	if (!x) return ;
	int we=que(1,x);
	int l=que2(1,1,we),r=que1(1,we+1,n),j=que1(1,we,n);
	if (l!=1){int s=quew(1,l-1);add(1,s,x-r);add(1,we,r-x);}
	if (l!=n){int t=quew(1,l+1);add(1,t,j-x);fei(1,we);}
}
int main(){
//	freopen("d.in","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1,comp);
	build(1,1,n);
	for (int i=1;i<=n;i++)add(1,a[i],1);
	for (int i=1;i<=n;i++){
		if (t[1].su){
			int p=delma(1);p=que2(1,1,p);int q=t[1].su;
			ansmi+=max(0,p-q);del(min(p,q));
		}
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)add(1,a[i],1);
	int s=ansmi;
	for (int i=1;i<=n;i++){
		if (t[1].su){
			int p=delma(1);p=que2(1,1,p);int q=t[1].su;
			if (s){p--;s--;}
			if (p>q||p<0){cout<<"-1"<<endl;return 0;}
			del(p);
		}
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)add(1,a[i],1);
	for (int i=1;i<=n;i++){
		if (t[1].su){
			int p=delma(1);p=que2(1,1,p);int q=t[1].su;
			if (p){ansma++;p--;}
			if (p){
				if (p>q){cout<<"-1"<<endl;return 0;}
				del(p);
			}
		}
	}
	for (int i=ansmi;i<=ansma;i+=2)printf("%d ",i);
	return 0;
}