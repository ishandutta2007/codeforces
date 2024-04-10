#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
typedef complex<double> C;
int g[1<<19],N;
C a[1<<19],b[1<<19];
void FFTinit(int k){
	for (int i=1;i<N;i++) g[i]=g[i>>1]>>1|((i&1)<<k);
}
void FFT(C *a,int f)
{
	int i,j,k,p;
	for (i=0;i<N;i++)
		if (g[i]>i) swap(a[i],a[g[i]]);
	for (i=1;i<N;i<<=1)
	{
		C e(cos(pi/i),f*sin(pi/i));
		for (j=0;j<N;j+=i<<1)
		{
			C w(1,0);for (k=0;k<i;k++,w*=e)
			{
				C x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
}
vector<LL> multi(vector<LL> x,vector<LL> y){
    N=x.size()+y.size()-1;
    for(int cnt=0,i=1;;i<<=1,cnt++){
		if(i>=N){
			N=i;
			FFTinit(cnt-1);
			break;
		}
	}
    for(int i=0;i<N;i++)
        a[i]=0;
    for(int i=0;i<N;i++)
        b[i]=0;
    for(int i=0;i<x.size();i++)
    a[i]=x[i];
    for(int i=0;i<y.size();i++)
    b[i]=y[i];
    FFT(a,1); FFT(b,1);
    for(int i=0;i<N;i++)
    a[i]=a[i]*b[i];
    FFT(a,-1);
    vector<LL> ret;
    ret.clear();
    for(int i=0;i<x.size()+y.size()-1;i++)
    ret.pb((LL)(a[i].real()/N+0.5));
    // test
    while(ret.back()==0)
    ret.pop_back();
    return ret;
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    vector<LL> v;
    int cnt=1;
    LL ans=0;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a<x)
        v.pb(cnt),cnt=1;
        else
        cnt++;
    }
    v.pb(cnt);
    for(auto it:v)
    ans+=(LL)it*(it-1)/2;
    //printf("%d ",it);
    //printf("\n");
    vector<LL> v2=v;
    reverse(v2.begin(),v2.end());
    vector<LL> res=multi(v,v2);
    printf("%lld ",ans);
    for(int i=v.size()-2;i>=0;i--)
    printf("%lld ",res[i]);
    for(int i=0;i<n-1-v.size()+2;i++)
    printf("0 ");
    printf("\n");
}