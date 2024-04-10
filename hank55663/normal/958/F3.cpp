#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
#define pi acos(-1)
int N;
typedef complex<double> C;
int g[1<<19];
C a[1<<19],b[1<<19];
int mod=1009;
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
vector<int> multi(vector<int> x,vector<int> y){
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
    vector<int> ret;
    ret.clear();
    for(int i=0;i<x.size()+y.size()-1;i++)
    ret.pb(((LL)(a[i].real()/N+0.5)%mod+mod)%mod);
    // test
    while(ret.back()==0)
    ret.pop_back();
    return ret;
}
bool operator<(const vector<int> &a,const vector<int> &b){
    return a.size()<b.size();
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
	int cnt[200005];
    MEM(cnt);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        //a=i%2+1;
        cnt[a]++;
    }
    typedef vector<int> vi;
    priority_queue<vi,vector<vi>,greater<vi> > pq;
    for(int i=1;i<=m;i++){
        if(cnt[i]!=0){
            vi v;
            for(int j=0;j<=cnt[i];j++)
              v.pb(1);
            pq.push(v);

        }
    }
    while(pq.size()>1){
        vi v1=pq.top();pq.pop();
        vi v2=pq.top();pq.pop();
        vi res = multi(v1,v2);
        pq.push(res);
    }
    printf("%d\n",pq.top()[k]);
}