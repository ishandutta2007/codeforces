#include<iostream>
#include<vector>
#include<complex>
#include<cmath>
using namespace std;
typedef double ld;
#define M_PI 3.14159265358979323846
struct FFT
{
    vector<complex<ld> > org, res, tmp,e;
    int n;
    vector<complex<ld> > compute_inverse( vector<complex<ld> > x)
    {
        // x's length must be a power of 2
        org=x;
        n=x.size();
        res =vector<complex<ld > > (n);
        tmp =vector<complex<ld > > (n);
        e =vector<complex<ld > > (n);
        for (int i=0;i<n;i++)
            e[i] = exp(((ld)2*M_PI*i*complex<ld> (0,1))/(ld)n);
        fft(n);
        for(int i=0;i<n;i++)
            res[i]/=n;
        return res;
    }
    vector<complex<ld> > poly_mult(vector<complex<ld> > u, vector<complex < ld > > v)
    {
        int s = u.size()+v.size();
        u.resize(s);
        v.resize(s);
        while((((int)u.size())&((-(int)u.size()))) != (int)u.size())
        {
            u.push_back(0);
            v.push_back(0);
        }
        vector<complex<ld> > dftu = compute(u), dftv = compute(v),res;
        for(int i=0;i<(int)dftu.size();i++)
            res.push_back(dftu[i]*dftv[i]);
        return compute_inverse(res);
    }
    vector<complex<ld> > compute( vector<complex<ld> > x)
    {
        // x's length must be a power of 2
        org=x;
        n=x.size();
        res =vector<complex<ld > > (n);
        tmp =vector<complex<ld > > (n);
        e =vector<complex<ld > > (n);
        for (int i=0;i<n;i++)
            e[i] = exp(-((ld)2*M_PI*i*complex<ld> (0,1))/(ld)n);
        fft(n);
        return res;
    }

    void fft(int l, int p=0,int s=1,int q=0)
    {
        if(l==1)
        {
            res[q]=org[p];
            return;
        }
        int pt = 0;
        fft(l/2,p,2*s,q);
        fft(l/2,p+s,2*s,q+l/2);
        for(int i=0;i<l/2;i++)
        {
            tmp[i] = res[q+i]+e[pt]*res[q+l/2+i];
            tmp[i+l/2] = res[q+i] - e[pt]*res[q+l/2+i];
            pt+=s;
            pt%=n;
        }
        for(int i=0;i<l;i++)
            res[q+i]=tmp[i];
    }
};
vector<complex<ld> >p,q,r;
int n;
ld x,a;
ld ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> x;
	p.resize(n+1);
	q.resize(n+1);
	ans=(ld)1*n*(n+1)/2;
	p[0]+=1;
	q[n]+=1;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> a;
		if(a<x) cnt++;
		p[cnt]+=1;
		q[n-cnt]+=1;
	}
	FFT fft;
	r=fft.poly_mult(p,q);
	for(int i=n+1; i<=2*n ;i++){
		ans-=round(r[i].real());
	}
	cout << (long long)round(ans);
	for(int i=n+1; i<=2*n ;i++){
		cout << ' ' << (long long)round(r[i].real());
	}
	cout << endl;
}