#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int N=111;
int a[N];
int n;
int ask(){
	//cerr<<n<<endl;
	cout<<"? ";
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
	//cout<<endl;
	cout.flush();
	int x;
	cin>>x;
	return x;
}
int p[N];
int main(){
#ifdef flukehn
	//freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	srand(time(0));
	cin>>n;
	int u,v;
	u=v=1;
	for(int i=1;i<=n-1;++i){
		if(u){
			a[n]=1;
			for(int j=1;j<=n-1;++j)a[j]=u+1;
			int w=ask();
			if(!w){
				p[n]=u;
				u=0;
			}else{
				p[w]=-u;
				++u;
			}
		}
		if(v){
			a[n]=n;
			for(int j=1;j<=n-1;++j)a[j]=n-v;
			int w=ask();
			if(!w){
				v=0;
			}else{
				p[w]=v;
				++v;
			}
		}
	}
	if(!p[n])p[n]=n;
	for(int i=1;i<n;++i)p[i]+=p[n];
	//for(int i=1;i<=n;++i)cout<<p[i]<<" \n"[i==n];

	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<p[i]<<" \n"[i==n];
	cout.flush();
}