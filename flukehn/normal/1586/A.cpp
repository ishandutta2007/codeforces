#include<bits/stdc++.h>
using namespace std;
const int M=1e7+11;
int np[M],p[M],tot;
const int N=211;
int a[N];
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	np[1]=1;
	for(int i=2;i<M;++i){
		if(!np[i]){
			p[tot++]=i;
		}
		for(int j=0,k;j<tot&&(k=i*p[j])<M;++j){
			np[k]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
	int T;cin>>T;
	while(cin>>n){
		int s=0;
		for(int i=1;i<=n;++i)cin>>a[i],s+=a[i];
		//cerr<<s<<endl;
		if(!np[s]){
			int i;
			for(i=1;i<=n;++i)if(np[s-a[i]])break;
			cout<<n-1<<"\n";
			for(int j=1;j<=n;++j)if(j!=i)cout<<j<<" \n"[j==n||(j==n-1&&i==n)];
		}else{
			cout<<n<<"\n";
			for(int i=1;i<=n;++i)cout<<i<<" \n"[i==n];
		}
	}
}