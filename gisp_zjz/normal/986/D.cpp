#include<bits/stdc++.h>
#define N 524288
#define M 10
#define pi acos(-1.0) // PI
using namespace std;
typedef complex<double> E;
typedef long long ll;
vector <E> p1,p2;
int n,m,cnt[N],p,k,r,ans,nc,dg[N];
char s[N*3];
struct poly{
    vector <ll> x;
    int len;
    void print()
    {
        for (int j=x.size()-1;j>=0;j--) printf("%d",x[j]);
        printf("\n");
    }
    void operator *=(const int &u){
        x.resize(len+1);
        for (int i=0;i<len;i++) x[i]*=u;
        //for (int i=0;i<len;i++) printf("%d ",x[i]); printf("\n");
        for (int i=0;i<len;i++) {
            x[i+1]+=x[i]/1000;
            x[i]%=1000;
        }
        if (x[len]) len++;
        //for (int i=0;i<len;i++) printf("%d ",x[i]); printf("\n");
    }
}t,d,o;
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

poly mult(poly u,poly v)
{
    poly tmp;
    tmp.len=u.len+v.len;
    int ll=tmp.len;
    int l=1; while (l<ll) l<<=1;
    p1.resize(l);
    p2.resize(l);
    tmp.x.resize(l);
    for (int i=0;i<u.len;i++) p1[i]=1.0*u.x[i];
    for (int i=u.len;i<l;i++) p1[i]=0;
    fft(p1,l,1);
    for (int i=0;i<l;i++) p2[i]=p1[i]*p1[i];
    fft(p2,l,-1);
    for (int i=0;i<ll;i++) tmp.x[i]=(long long)(p2[i].real()+0.5);
    for (int i=0;i<ll;i++) {
        tmp.x[i+1]+=tmp.x[i]/1000;
        tmp.x[i]%=1000;
    }
    if (!tmp.x[ll-1]) tmp.len--;
    return tmp;
}

poly pow_(int y){
    poly rt=o;
    for (int i=21;i>=0;i--){
        rt=mult(rt,rt);
        if (y&(1<<i)) rt*=3;
    }
    return rt;
}

bool check(){
    if (d.len<nc) return false;
    if (d.len>nc) return true;
    for (int i=nc-1;i>=0;i--){
        if (d.x[i]==dg[i]) continue;
        return d.x[i]>dg[i];
    }
    return true;
}

int main()
{
    //cin>>n;
    //o.x.resize(1); o.x[0]=1; o.len=1;
    //d=pow_(n);
    //d.print();

    scanf("%s",s);
    n=strlen(s); int p10=1;
    if (n==1&&s[0]=='1'){cout<<1<<endl;return 0;}
    for (int i=n-1;i>=0;i--) {
        dg[nc]+=p10*(s[i]-'0');
        p10*=10;
        if (p10==1000) p10=1,nc++;
    }
    if (p10!=1) nc++;
    m=int(2.0959032742894*n);
    m=max(0,m-4);
    o.x.resize(1); o.x[0]=1; o.len=1;
    r=m; d=pow_(m);
    while (!check()) d*=3,r++;
    ans=r*3;
    r=m; d=pow_(m); d*=2;
    while (!check()) d*=3,r++;
    ans=min(ans,r*3+2);
    r=m; d=pow_(m); d*=4;
    while (!check()) d*=3,r++;
    ans=min(ans,r*3+4);
    cout << ans << endl;

	return 0;
}