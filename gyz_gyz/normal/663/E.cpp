#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define pb push_back
using namespace std;
vector<int>t0;
int n,m,b[100001];
char S[20][100000];
struct pt{int x;vector<int>a[21];
	pt friend operator +(pt a,pt b){pt s;s.x=a.x+1;
		rep(i,0,n-s.x)s.a[i].clear();
		rep(i,0,n-s.x){
			rep(j,0,(1<<a.x)-1)
				s.a[i].pb(a.a[i][j]+b.a[i+1][j]);
			rep(j,0,(1<<a.x)-1)
				s.a[i].pb(a.a[i+1][j]+b.a[i][j]);
		}return s;
	}
};
pt sol(int x,int l,int r){int mid=r+1;
	if(l>r){pt s;s.x=x;
		rep(i,0,n-s.x){
			s.a[i].clear();rep(j,0,(1<<s.x)-1)s.a[i].pb(0);
		}return s;
	}
	if(!x){pt s;s.x=0;
		rep(i,0,n){
			s.a[i].clear();s.a[i].pb(min(i,n-i)*(r-l+1));
		}return s;
	}
	rep(i,l,r)if((b[i]>>(x-1))&1){mid=i;break;}
	return sol(x-1,l,mid-1)+sol(x-1,mid,r);
}
void write(pt x){int ans=n*m;
	rep(i,0,(1<<n)-1)ans=min(ans,x.a[0][i]);
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,n-1)scanf("%s",S[i]);
	rep(i,1,n)rep(j,1,m)
		if(S[i-1][j-1]=='1')b[j]+=1<<(i-1);
	sort(b+1,b+m+1);
	write(sol(n,1,m));
}