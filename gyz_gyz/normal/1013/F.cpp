#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,nn,mm,x,y,r,a1,a2,p[N],q[N];
char s[N],t[N],ch;
int main(){
	scanf("%s",s+1);scanf("%s",t+1);ch='a';
	rep(i,1,500000){
		if(s[i]!=ch){
			n++;p[n]=x;x=0;ch='a'+'b'-ch;
		}x++;
		if(!s[i])break;
	}ch='b';x=0;
	rep(i,1,500000){
		if(t[i]!=ch){
			m++;q[m]=x;x=0;ch='a'+'b'-ch;
		}x++;
		if(!t[i])break;
	}
	if((!p[1])&&(!q[1])){
		n--;rep(i,1,n)p[i]=p[i+1];
		m--;rep(i,1,m)q[i]=q[i+1];
	}
	nn=n;mm=m;
	if(m-n>2){
		r=(m-n+1)/4*2;mm-=r+1;
		nn+=r-1;if(nn==r)nn++;
	}else if(n-m>2){
		r=(n-m+1)/4*2;nn-=r+1;
		mm+=r-1;if(mm==r)mm++;
	}
	if(abs(nn-mm)>1){
		if(!p[1]){
			n--;rep(i,1,n)p[i]=p[i+1];
			m++;dep(i,m+1,2)q[i]=q[i-1];q[1]=0;
		}else if(!q[1]){
			m--;rep(i,1,m)q[i]=q[i+1];
			n++;dep(i,n+1,2)p[i]=p[i-1];p[1]=0;
		}
	}r=0;
	if(m-n>2){
		r=(m-n+1)/4*2;x=0;
		rep(i,1,r+1)x+=q[i];
		a1=p[1];a2=x;x=p[1];y=q[r+1];
		dep(i,n+r-1,r+1)p[i]=p[i-r+1];
		rep(i,1,r)p[i]=q[i];
		rep(i,1,m-r-1)q[i]=q[i+r+1];
		p[r+1]+=y;q[1]+=x;m-=r+1;
		n+=r-1;if(n==r)n++;
	}else if(n-m>2){
		r=(n-m+1)/4*2;x=0;
		rep(i,1,r+1)x+=p[i];
		a1=x;a2=q[1];x=q[1];y=p[r+1];
		dep(i,m+r-1,r+1)q[i]=q[i-r+1];
		rep(i,1,r)q[i]=p[i];
		rep(i,1,n-r-1)p[i]=p[i+r+1];
		q[r+1]+=y;p[1]+=x;n-=r+1;
		m+=r-1;if(m==r)m++;
	}x=y=0;
	printf("%d\n",(r>0)+max(n,m)-1);
	if(r)printf("%d %d\n",a1,a2);
	p[n+1]=p[n+2]=q[m+1]=q[m+2]=0;
	rep(i,1,max(n,m)-1){
		x+=p[i];y+=q[i];
		printf("%d %d\n",x,y);
		x^=y;y^=x;x^=y;
	}
}