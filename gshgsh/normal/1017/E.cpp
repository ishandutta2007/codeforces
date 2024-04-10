#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ld long double
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define polygon vector<Vector>
#define eps 1e-12
#define MAXN 400001
int N,M,tot,nxt[MAXN];ld x[MAXN],y[MAXN];
struct Vector
{
	ld x,y;Vector(ld a=0,ld b=0){x=a,y=b;}ld len(){return sqrt(x*x+y*y);}void in(){int a,b;scanf("%d%d",&a,&b);x=a,y=b;}void out(){printf("%.8Lf %.8Lf\n",x,y);}
	Vector operator+(Vector a){return Vector(x+a.x,y+a.y);}Vector operator-(Vector a){return Vector(x-a.x,y-a.y);}
	Vector operator*(ld a){return Vector(x*a,y*a);}Vector operator/(ld a){return Vector(x/a,y/a);}
	ld dot(Vector a){return x*a.x+y*a.y;}ld cross(Vector a){return x*a.y-y*a.x;}
	bool operator<(Vector a)const{return x<a.x||(x==a.x&&y<a.y);}
};
polygon getpol(polygon a)
{
	sort(a.begin(),a.end());int N=a.size();polygon ans;
	For(i,0,N-1){while(ans.size()>1&&(ans[ans.size()-1]-ans[ans.size()-2]).cross(a[i]-ans[ans.size()-1])<eps)ans.pop_back();ans.push_back(a[i]);}
	int k=ans.size();FOR(i,N-2,0){while(ans.size()>k&&(ans[ans.size()-1]-ans[ans.size()-2]).cross(a[i]-ans[ans.size()-1])<eps)ans.pop_back();ans.push_back(a[i]);}ans.pop_back();return ans;
}
int main()
{
	cin>>N>>M;polygon a(N),b(M);For(i,0,N-1)a[i].in();For(i,0,M-1)b[i].in();a=getpol(a),b=getpol(b);N=a.size(),M=b.size();if(N!=M){cout<<"NO\n";return 0;}
	For(i,0,N-1)x[++tot]=(a[(i+1)%N]-a[i]).len(),x[++tot]=(a[(i+2)%N]-a[(i+1)%N]).dot(a[(i+1)%N]-a[i])/(a[(i+2)%N]-a[(i+1)%N]).len()/(a[(i+1)%N]-a[i]).len()-2;For(i,tot+1,tot*2)x[i]=x[i-tot];
	For(i,0,N-1)y[i*2+1]=(b[(i+1)%N]-b[i]).len(),y[i*2+2]=(b[(i+2)%N]-b[(i+1)%N]).dot(b[(i+1)%N]-b[i])/(b[(i+2)%N]-b[(i+1)%N]).len()/(b[(i+1)%N]-b[i]).len()-2;
	int j=0;For(i,2,tot){while(j&&abs(y[i]-y[j+1])>eps)j=nxt[j];j+=abs(y[i]-y[j+1])<eps;nxt[i]=j;}
	j=0;For(i,1,tot*2){while(j&&abs(x[i]-y[j+1])>eps)j=nxt[j];j+=abs(x[i]-y[j+1])<eps;if(j==tot){cout<<"YES\n";return 0;}}cout<<"NO\n";return 0;
}