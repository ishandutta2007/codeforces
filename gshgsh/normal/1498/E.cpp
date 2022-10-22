#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Tair pair<int,Pair>
#define F first
#define S second
#define MAXN 501
int N,a[MAXN];priority_queue<Tair>q;
bool ask(int a,int b){cout<<"? "<<a<<' '<<b<<endl;string x;cin>>x;return x[0]=='Y';}
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];For(i,1,N)For(j,1,N)if(i!=j&&a[i]>=a[j])q.push({a[i]-a[j],{i,j}});
	while(!q.empty()){int a=q.top().S.F,b=q.top().S.S;q.pop();if(ask(a,b)){cout<<"! "<<a<<' '<<b<<endl;return 0;}}cout<<"! 0 0\n";return 0;
}