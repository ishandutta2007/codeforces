#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}


#define Maxn 105
int a[Maxn];

int n;
int px,py;
pii query(){
	int x,y;
	scanf("%d%d",&x,&y);
	pii res=pii(x-px,y-py);
	px=x;py=y;
	return res;
}

void ask(int x){
	printf("+ %d\n",x);fflush(stdout);
}

int go(int x){
	int t=1;
	while(t*(t-1)/2<x)t++;return t;
}

int main(){
	scanf("%d%d%d",&n,&px,&py);
	ask(2);pii tt=query();
	ask(1);pii s1=query();//(a2+1)a3
	ask(3);pii s3=query();
	ask(1);pii s2=query();//(a2+1)(a3+1)
	a[2]=s2.SE-s1.SE;a[3]=s2.SE/a[2];
	if(s1.FR>0)a[1]=go(s1.FR)+2;
	else if(s2.FR>0)a[1]=go(s2.FR)+1;
	else a[1]=2;
	int lst=s3.SE-(a[1]-1)*a[2];
	rep(i,3,n-2){
		ask(i+1);
		pii to=query();
		if(to.FR>0)a[i+1]=go(to.FR)+1;
		else{
			if(lst)a[i+1]=2;
			else a[i+1]=1;
		}
		lst=to.SE-a[i]*a[i-1];
	}
	a[n]=lst/a[n-2];a[1]--;
	rep(i,1,n-1)a[i]--;
	printf("! ");rep(i,1,n)printf("%d ",a[i]);fflush(stdout);
	return 0;
}