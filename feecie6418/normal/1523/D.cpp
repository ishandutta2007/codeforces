#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],ans=0,anscnt=0;
int n,m,p,f[40005],b[105];
char str[105];
void Do(){
	int x=(((ll)rand()<<15)|rand())%n+1;
	int t=0;
	for(int i=0;i<m;i++)if(a[x]&(1ll<<i))b[t]=i,t++;
	for(int i=0;i<(1<<t);i++)f[i]=0;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=0;j<t;j++)if(a[i]&(1ll<<b[j]))s+=(1<<j);
		f[s]++;
	}
	for(int i=0;i<t;i++)for(int j=0;j<(1<<t);j++)if(!(j&(1<<i)))f[j]+=f[j+(1<<i)];
	for(int i=0;i<(1<<t);i++){
		if(f[i]*2>=n&&__builtin_popcount(i)>anscnt){
			anscnt=__builtin_popcount(i);
			ans=0;
			for(int j=0;j<t;j++)if(i&(1<<j))ans+=(1ll<<b[j]);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&p),srand(time(0));
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		for(int j=0;j<m;j++)if(str[j]=='1')a[i]+=(1ll<<j);
	}
	for(int i=1;i<=30;i++)Do();
	for(int i=0;i<m;i++)if(ans&(1ll<<i))cout<<1;else cout<<0;
}