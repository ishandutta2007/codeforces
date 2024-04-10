#include<bits/stdc++.h>
using namespace std;

mt19937 Rand(time(0));

typedef long long LL;

const int N=100000;

int n,st,x;

void into(){
  cin>>n>>st>>x;
}

struct thing{
  int p,x,r;
  thing(int P=0,int X=0,int R=0){p=P;x=X;r=R;}
}a[N+9];

void Get_ans(){
  int ca=0;
  for (int i=1;i<=n;++i)
	if (i^st) a[++ca].p=i;
  for (int i=1;i<=5;++i) shuffle(a+1,a+n,Rand);
  int m=min(n-1,1000);
  a[0].p=st;
  for (int i=0;i<=m;++i){
	cout<<"? "<<a[i].p<<endl;
	cin>>a[i].x>>a[i].r;
  }
  sort(a+1,a+m+1,[&](const thing &a,const thing &b){return a.x<b.x;});
  if (x<=a[0].x) {cout<<"! "<<a[0].x<<endl;exit(0);}
  for (int i=1;i<=m;++i)
	if (x==a[i].x) {cout<<"! "<<a[i].x<<endl;exit(0);}
  a[m+1].x=(1<<30)-1;
  for (int i=0;i<=m;++i)
	if (a[i].x<=x&&a[i+1].x>=x){
	  int p=a[i].r;
	  if (p==-1) {cout<<"! "<<-1<<endl;exit(0);}
	  for (;2333;){
		cout<<"? "<<p<<endl;
		int now,r;
		cin>>now>>r;
		if (now>=x) {cout<<"! "<<now<<endl;exit(0);}
		p=r;
		if (p==-1) {cout<<"! "<<-1<<endl;exit(0);}
	  }
	}
}

void work(){
  Get_ans();
}

void outo(){
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}