#include<bits/stdc++.h>
#define maxn 200005
#define eps 1e-7
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
inline int dcmp(double a)
{
	if(fabs(a) < 1e-7) return 0;
	return a>0?1:-1;
}

int n,m,npt;
double len[maxn],arrtim[maxn];
inline double sqr(double x){ return x*x; }
struct Point{	
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	Point operator +(const Point &B)const{ return Point(x+B.x,y+B.y); }
	Point operator -(const Point &B)const{ return Point(x-B.x,y-B.y); }
	Point operator *(const double B)const{ return Point(x*B,y*B); }
	double Len(){ return sqrt(sqr(x)+sqr(y)); }
}st,P[maxn],dir[maxn];
double dist(Point A,Point B){ return (B-A).Len(); }
double C;
double tl[maxn*10],tr[maxn*10];
int ct[maxn*10],cnt_t;
inline bool cmp(const int &u,const int &v){ return tl[u] < tl[v]; }
inline double diV(double t){ return floor(t / C);}
inline double dmod(double t){
	return t - C * floor(t / C);
}

bool ERROR = 0;
void Insert(double s,double t){	
	if(dcmp(diV(t) - diV(s)) == 1){
		if(dcmp(dmod(t) - dmod(s)) == 1 || dcmp(diV(t)-diV(s)-1) == 1) 
			ERROR = 1;
		else {
			tl[++cnt_t] = dmod(s) , tr[cnt_t] = C;
			tl[++cnt_t] = 0 , tr[cnt_t] = dmod(t);
		}
	}
	else{
		tl[++cnt_t] = dmod(s) , tr[cnt_t] = dmod(t);
	}
}

inline bool check(double mid){
	double tnow=0;
	cnt_t = ERROR = 0;
	Point st1 = P[1] , st2 = st;
	for(int npt1=2,npt2=npt;npt1<=n+1 && npt2 <= npt + n;){
		double lim1 = arrtim[npt1] , lim2 = arrtim[npt2] - C;
		double A1 = st1.x - st2.x , A2 = dir[npt1-1].x-dir[npt2-1].x;
		double B1 = st1.y - st2.y , B2 = dir[npt1-1].y-dir[npt2-1].y;
		double A = sqr(A2) + sqr(B2) , B = 2 * A1 * A2 + 2 * B1 * B2 , C = sqr(A1) + sqr(B1) - mid * mid;
		double delta = sqr(B) - 4 * A * C;
		if(dcmp(delta) == -1) 
			Insert(tnow , min(lim1,lim2));
		else{
			delta = sqrt(delta);
			if(dcmp(A) != 0){		
				double x1 = (-B-delta)/(2*A) , x2 = (-B+delta)/(2*A);
				if(x1 > 0)
					Insert(tnow , min(min(lim1,lim2),tnow + x1));
				if(x2+tnow < min(lim1,lim2))
					Insert(max(x2+tnow,tnow),min(lim1,lim2));
			}
			else if(dcmp(B) == 0){	
				if(C > 0) Insert(tnow,min(lim1,lim2));
			}
			else if(dcmp(B) == 1){
				double x = - C / B;
				Insert(max(tnow,tnow+x),min(lim1,lim2));
			}
			else{
				double x = -C / B;
				Insert(tnow,min(min(lim1,lim2),tnow+x));
			}
		}
		double tnxt = min(lim1,lim2);
		if(dcmp(lim1-tnxt)!=1) st1=P[npt1],npt1++;
		else st1 = st1 + dir[npt1-1] * (tnxt - tnow);
		if(dcmp(lim2-tnxt)!=1) st2=P[npt2],npt2++;
		else st2 = st2 + dir[npt2-1] * (tnxt - tnow);
		tnow = tnxt;
	}
	if(ERROR) return 0;
	
	double Max = eps;
	for(int i=1;i<=cnt_t;i++) ct[i] =i;
	sort(ct+1,ct+1+cnt_t,cmp);
	for(int i=1;i<=cnt_t;i++){
		if(dcmp(tl[ct[i]]-Max) == 1){
			return 1;
		}
		Max = max(Max , tr[ct[i]]);
	}
	if(dcmp(Max-C) == -1) return 1;
	return 0;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&P[i].x,&P[i].y);
	}
	P[n+1]=P[1];
	for(int i=1;i<=n;i++){
		len[i] = dist(P[i],P[i+1]) , 
		C+=len[i] , arrtim[i+1] = C,
		dir[i] = (P[i+1] - P[i])*(1/(P[i+1]-P[i]).Len());
	}
	for(int i=1;i<=n;i++){
		arrtim[n+i+1] = C + arrtim[i+1],
		dir[i+n] = dir[i],
		P[i+n] = P[i] , len[i+n] = len[i];
	}
	C /= m;
	int id = 1;
	double sel = C;
	for(;dcmp(len[id]-sel)!=1;id++) sel-=len[id];
	id = (id-1) + 1;
	st = P[id] + dir[id] * sel;
	npt = id + 1;
	double l = 0,r = 10000,mid;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(check(mid)) r = mid;
		else l = mid + eps;
	}
	printf("%.7lf",l);
}