#include<bits/stdc++.h>
using namespace std;
#define N 205
typedef long long ll;
const double eps=1e-9;
const double PI=acos(-1.0);
int n,Q;
struct Matrix{
	double g[N][N];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					c.g[i][j]+=a.g[i][k]*b.g[k][j];
				}
			}
		}
		return c;
	}
}A[15];
struct Vector{
	double g[N];	
	Vector(){memset(g,0,sizeof(g));}
	friend Vector operator * (const Vector &a,const Matrix &b){
		Vector c;
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				c.g[j]+=a.g[k]*b.g[k][j];		
			}
		}
		return c;
	}
};
struct Point{
	int x,y;	
	Point(int _x=0,int _y=0):x(_x),y(_y){}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);	
	}
}p[N];
vector<vector<int> > Lines;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(8);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;++i){
		int m=0;
		static pair<double,int> t[N];
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			t[++m]=make_pair(atan2((p[j]-p[i]).x,(p[j]-p[i]).y),j);
			if(t[m].first<=0)t[m].first+=PI;
		}
		sort(t+1,t+m+1);
		int cnt=1;
		for(int j=2;j<=m;++j){
			cnt+=fabs(t[j].first-t[j-1].first)>eps;
		}
		A[0].g[i][i]=1.0;
		for(int j=1,k=1;j<=m;j=k+1){
			k=j;
			while(k<n&&fabs(t[k].first-t[k+1].first)<=eps)++k;
			vector<int> jb(1,i);
			for(int p=j;p<=k;++p){
				double tmp=1.0/cnt/(k-j+2);
				A[0].g[t[p].second][i]+=tmp;
				A[0].g[i][i]-=tmp;
				jb.push_back(t[p].second);
			}
			sort(jb.begin(),jb.end());
			Lines.push_back(jb);
		}
	}
	sort(Lines.begin(),Lines.end());
	Lines.erase(unique(Lines.begin(),Lines.end()),Lines.end());
	for(int i=1;i<=14;++i){
		A[i]=A[i-1]*A[i-1];
	}
	cin>>Q;
	while(Q--){
		int t,m;
		cin>>t>>m;
		double mx;
		{
			Vector ans;
			ans.g[t]=1;
			for(int i=14;i>=0;--i){
				if(m>>i&1)ans=ans*A[i];
			}
			mx=(*max_element(ans.g+1,ans.g+n+1));
		}
		{
			--m;
			Vector ans;
			ans.g[t]=1;
			for(int i=14;i>=0;--i){
				if(m>>i&1)ans=ans*A[i];
			}
			for(auto Line:Lines){
				double tot=0;
				for(auto x:Line){
					tot+=ans.g[x]/Line.size();
				}
				mx=max(mx,tot);
			}
		}
		cout<<mx<<'\n';
	}
	return 0;
}