#include<bits/stdc++.h>
#define maxn 300000
#define pi acos(-1.0) // PI

using namespace std;
typedef complex<double> E;
typedef long long ll;
vector <E> u,v;
ll cnt[maxn],n,x,a[maxn],b[maxn],c[maxn],d[maxn],r;
void brc(vector<E> &y,int l) //  O(logn)
{
	register int i,j,k;
	for(i=1,j=l/2;i<l-1;i++)
	{
		if(i<j)	swap(y[i],y[j]); // 
								// i<j
		k=l/2;
		while(j>=k) // 1001
		{
			j-=k;
			k/=2;
		}
		if(j<k)	j+=k;
	}
}

void fft(vector<E> &y,int l,double on)
{
	register int h,i,j,k;
	E u,t;
	brc(y,l); // 
	for(h=2;h<=l;h<<=1) // 
	{
		// 
		E wn(cos(on*2*pi/h),sin(on*2*pi/h));
		for(j=0;j<l;j+=h) // 
		{
			E w(1,0); // 
			for(k=j;k<j+h/2;k++) // 
			{
				u=y[k];
				t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn; // 
			} // 
		}
	}
	if (on==-1) for(i=0;i<l;i++) y[i]/=l; // IDFT
}

void solve(int l,int r){
    if (l==r) {cnt[a[l]]++; return ;}
    int mid=(l+r)>>1;
    solve(l,mid); solve(mid+1,r);
    int ll=1; while (ll<r-l+2) ll<<=1;
    for (int i=0;i<ll;i++) c[i]=d[i]=0;
    int p=0,q=0;
    for (int i=mid;i>=l;i--) p+=a[i],c[p]++;
    for (int i=mid+1;i<=r;i++) q+=a[i],d[q]++;
    u.resize(ll); v.resize(ll);
    //for (int i=0;i<ll;i++) cout << c[i] << ' '; cout << endl;
    //for (int i=0;i<ll;i++) cout << d[i] << ' '; cout << endl;
    for (int i=0;i<ll;i++) u[i]=(double)1.0*c[i];
    for (int i=0;i<ll;i++) v[i]=(double)1.0*d[i];
    fft(u,ll,1);
    fft(v,ll,1);
    for (int i=0;i<ll;i++) u[i]=u[i]*v[i];
    fft(u,ll,-1);
    for (int i=0;i<ll;i++) cnt[i]+=(long long)(u[i].real()+0.5);
    //for (int i=0;i<ll;i++) cout << (long long)(u[i].real()+0.5) << ' '; cout << endl;
}

int main(){
    cin >> n >> x;
    for (int i=0;i<n;i++) {
        scanf("%lld",&r);
        if (r<x) a[i]=1; else a[i]=0;
    }
    solve(0,n-1);
    for (int i=0;i<=n;i++) cout << cnt[i] << ' ';
    cout << endl;
}