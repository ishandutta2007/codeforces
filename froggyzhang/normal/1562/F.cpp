#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,ntp[N];
inline ll Ask(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	ll l;
	cin>>l;
	return l;
}
inline ll Lcm(int x,int y){
	return 1LL*x*y/__gcd(x,y);
}
mt19937 rnd(time(0));
void Solve(){
	cin>>n;
	if(n<=100){
		static ll c[105][105];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				c[i][j]=c[j][i]=Ask(i,j);
			}
		}
		if(n==3){
			for(int i=1;i<=200000;++i){
				int a[3]={i,i+1,i+2};
				do{
					if(Lcm(a[0],a[1])==c[1][2]&&Lcm(a[1],a[2])==c[2][3]&&Lcm(a[0],a[2])==c[1][3]){
						cout<<"! "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
						return;
					}
				}while(next_permutation(a,a+3));	
			}
			assert(false);
		}
		cout<<"! ";
		for(int i=1;i<=n;++i){
			ll x=0;
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				x=__gcd(c[i][j],x);
			}
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	int H=250,mx=-1,pos=-1;
	while(H--){
		ll g=0;
		int u=rnd()%n+1;
		for(int i=1;i<=20;++i){
			int v;
			do{v=rnd()%n+1;}while(u==v);
			g=__gcd(g,Ask(u,v));
		}
		if(!ntp[g]){
			if(g>mx)mx=g,pos=u;
		}
	}
	assert(~mx);
	static int a[N];
	for(int i=1;i<=n;++i){
		a[i]=(i==pos?mx:Ask(i,pos)/mx);
	}
	cout<<"! ";
	for(int i=1;i<=n;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=n;j+=i)ntp[j]=1;
		}		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}