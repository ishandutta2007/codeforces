#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=102;
int n,a[N],b[N],c[N],t1,s1,t2,s2,t3,s3,s,t;
V ask(int p,int&x,int&y){
	cout<<"+ "<<p<<endl;
	cin>>x>>y,x-=s,y-=t,s+=x,t+=y;
}
I find(int x){FOR(i,1,n+n)if(i*(i-1)==x*2)return i;}
int main(){
	cin>>n>>s>>t;
	FOR(i,2,n-2)ask(i,a[i],b[i]);
	ask(n,s1,t1),ask(n-1,s2,t2),ask(n,s3,t3);
	c[n]=find(s3)-1,c[n-2]=t3-t1-1,c[n-1]=t3/(c[n-2]+1)-1;
	c[n-3]=(t2-(c[n-2]+1)*(c[n]+1))/(c[n-2]+1)-1;
	ROF(i,n-4,1)c[i]=(b[i+2]-((c[i+1]+1)*c[i+3]+c[i+3]*c[i+4]))/(c[i+1]+1)-1;
	c[1]++,cout<<"! ";
	FOR(i,1,n)cout<<c[i]<<' ';
	return 0;
}