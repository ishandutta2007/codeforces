#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define N 100000
#define L 10
using namespace std;
struct compl_{
	#define P 5
	ull a[P];
	compl_(ull A=0,ull B=0,ull C=0,ull D=0,ull E=0){a[0]=A,a[1]=B,a[2]=C,a[3]=D,a[4]=E;}
	ull& operator [](int i){return a[i];}
	compl_ operator +(compl_ b){return compl_(a[0]+b[0],a[1]+b[1],a[2]+b[2],a[3]+b[3],a[4]+b[4]);}
	compl_ operator -(compl_ b){return compl_(a[0]-b[0],a[1]-b[1],a[2]-b[2],a[3]-b[3],a[4]-b[4]);}
	compl_ operator *(compl_ b)
	{
		compl_ c;
		for(int i=0;i<P;i++)
		if(a[i]) for(int j=0;j<P;j++)
				if(b[j]) c[(i+j)%P]+=a[i]*b[j];
		return c;
	}
	compl_ operator *(int p)
	{
		compl_ c;
		for(int i=0;i<P;i++) c[(p+i)%5]=(p&1)?-a[i]:a[i];
		return c;
	}
}f[N];
compl_ ksm(compl_ a,ull b)
{
	compl_ r(1);
	for(;b;b>>=1){if(b&1) r=r*a;a=a*a;}
	return r;
}
void fft(compl_ f[],int opt)
{
	for(int mid=1;mid<N;mid*=L)
	{
		for(int p=0;p<N;p++)
		if(p/mid%L==0)
		{
			compl_ swp[L];
			for(int i=0;i<L;i++)
				for(int j=0;j<L;j++)
				swp[i]=swp[i]+(f[p+j*mid]*((ull)i*j*(opt==1?1:L-1)%L));
			for(int i=0;i<L;i++) f[p+i*mid]=swp[i];
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		f[a][0]++;
	}
	fft(f,1);
	for(int i=0;i<N;i++) f[i]=ksm(f[i],n);
	fft(f,-1);
	ull inv5=6723469279985657373ull;
	for(int i=0;i<n;i++)
	{
		ull res=(f[i][0]-f[i][4])*inv5/32ull%(1ull<<58);
		cout<<res<<endl;
	}
	return 0;
}