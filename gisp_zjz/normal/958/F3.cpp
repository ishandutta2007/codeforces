#include<bits/stdc++.h>
#define N 200005
#define M 1009
#define pi acos(-1.0) // PI
using namespace std;
typedef complex<double> E;
int n,m,cnt[N],p,k,r;
struct poly{
    vector <E> x;
    int len;
    /*
    void print()
    {
        for (int j=0;j<len;j++) printf("%.5f ",x[j].real());
        printf("\n");
    }
    */
}t;
char a[N/2],b[N/2];
int sum[N]; // sum
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
	if(on==-1)	for(i=0;i<l;i++)	y[i]/=l; // IDFT
}

bool operator <(poly u,poly v)
{
    return u.len>v.len;
}

poly mult(poly u,poly v)
{
    poly tmp;
    tmp.len=u.len+v.len-1;
    int ll=tmp.len;
    int l=1; while (l<ll) l<<=1;
    u.x.resize(l);
    v.x.resize(l);
    tmp.x.resize(l);
    for (int i=u.len;i<l;i++) u.x[i]=0;
    for (int i=v.len;i<l;i++) v.x[i]=0;
    //u.print();v.print();
    fft(u.x,l,1);
    fft(v.x,l,1);
    for (int i=0;i<l;i++) tmp.x[i]=u.x[i]*v.x[i];
    fft(tmp.x,l,-1);
    //tmp.print();
    for (int i=0;i<l;i++) tmp.x[i]=1.0*((long long)(tmp.x[i].real()+0.5)%M);
    return tmp;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    priority_queue <poly> q;
	for (int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        cnt[p]++;
    }
    for (int i=1;i<=m;i++)
    if (cnt[i]){
        t.x.resize(cnt[i]+1);
        t.len=cnt[i]+1;
        for (int j=0;j<=cnt[i];j++) t.x[j]=1.0;
        q.push(t);
    }
    while (q.size()>1){
        poly u=q.top(); q.pop();
        poly v=q.top(); q.pop();
        t=mult(u,v);
        q.push(t);
    }
    t=q.top();
    printf("%d\n",int(t.x[k].real()+0.5));
	return 0;
}