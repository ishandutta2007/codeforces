#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
int lcm[N][N],val[100010],c[N];
map<int,map<int,int> >f;
int rand_d() {
	return rand()<<15|rand();
}
int get(int x) {
	int P=1;
	for(int i=2;i*i<=x;i++)
		while(x%i==0) {
			x/=i;
			P=i;
		}
	if(x!=1)P=x;
	return P;
}
signed main() {
	cout.tie(0);
	int T,n;
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		if(n<=100) {
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++) {
					cout<<"? "<<i<<' '<<j<<endl;
					scanf("%lld",lcm[i]+j);
					lcm[j][i]=lcm[i][j];
				}
			int Min=1e9;
			for(int k=2;k<=n;k+=2) {
				int X,Y,Max=0;
				for(int i=1;i<=n;i++)
					for(int j=i+1;j<=n;j++)
						if(!c[i]&&!c[j]&&Max<lcm[i][j])
							X=i,Y=j,Max=lcm[i][j];
				val[X]=sqrt(Max),val[Y]=Max/val[X];
				c[X]=c[Y]=1;
				Min=val[X];
				for(int i=1;i<=n;i++) {
					if(k==n) {
						if(val[i]!=val[Y]+1)continue;
						if(lcm[i][Y]==val[Y]*(val[Y]+1))break;
						if(lcm[i][X]==val[Y]*(val[Y]+1)) {
							swap(val[X],val[Y]);
							break;
						}
					} else if(!c[i]) {
						if(lcm[i][X]==val[X]*(val[X]-1))break;
						if(lcm[i][Y]==val[X]*(val[X]-1)) {
							swap(val[X],val[Y]);
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(!c[i])val[i]=Min-1;
			cout<<"!";
			for(int i=1;i<=n;i++)
				cout<<' '<<val[i];
			cout<<endl;
			continue;
		}
		f.clear();
		int Max=0,X,Y,a;
		for(int i=1;i<=5000&&i<=1ll*(n-1)*n/2;i++) {
			int x=rand_d()%n+1,y=rand_d()%n+1;
			if(x>y)swap(x,y);
			if(f[x][y]||x==y) {
				i--;
				continue;
			}
			cout<<"? "<<x<<' '<<y<<endl;
			scanf("%lld",&a);
			a=get(a);
			if(a>Max) {
				Max=a;
				X=x,Y=y;
			}
			f[x][y]=1;
		}
		int x;
		for(x=1;x<=n;x++)
			if(x!=X&&x!=Y)break;
		cout<<"? "<<x<<' '<<X<<endl;
		scanf("%lld",&a);
		if(Max==get(a))x=X;
		else x=Y;//lakjgdshdjlkgfajsh,kf
		val[x]=Max;
		for(int i=1;i<=n;i++)
			if(i!=x) {
				cout<<"? "<<i<<' '<<x<<endl;
				scanf("%lld",val+i);
				val[i]/=Max;
			}
		cout<<"!";
		for(int i=1;i<=n;i++)
			cout<<' '<<val[i];
		cout<<endl;
	}
	return 0;
}