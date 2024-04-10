//by yjz
#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
const int mxc=1e8;
const int B=1e4;
int brand(){return rand()<<15|rand();}
vector<int>ansh,ansv;
int D;
void query(int x,int y)
{
	printf("0 %d %d\n",x-mxc,y-mxc);
	fflush(stdout);
	scanf("%d",&D);
	if(D==-1)exit(0);
}
bool check(int x,int y,bool v)
{
	for(int i=0;i<3;i++)
	{
		if(v)query(x,brand()%(mxc*2));else query(brand()%(mxc*2),y);
		if(D!=0)return false;
	}
	return true;
}
bool check1(int x,int y)
{
	if(x<0||y<0||x>2*mxc||y>2*mxc)return false;
	query(x,y);
	if(D!=0)return false;
	return true;
}
void solvev(int l,int r,int y)
{
	if(l>r)return;
	int m=l+r>>1;
	query(m,y);
	int d=D;
	if(d>m-l&&d>r-m)return;
	if(m-d>=l&&check1(m-d,y))ansv.PB(m-d);
	if(d!=0&&m+d<=r&&check1(m+d,y))ansv.PB(m+d);
	solvev(l,m-d-1,y);
	solvev(m+d+1,r,y);
}
void solveh(int l,int r,int x)
{
	if(l>r)return;
	int m=l+r>>1;
	query(x,m);
	int d=D;
	if(d>m-l&&d>r-m)return;
	if(m-d>=l&&check1(x,m-d))ansh.PB(m-d);
	if(d!=0&&m+d<=r&&check1(x,m+d))ansh.PB(m+d);
	solveh(l,m-d-1,x);
	solveh(m+d+1,r,x);
}
int main()
{
	srand(time(NULL));
	int curx=0,cury=0;
	while(curx<=2*mxc&&cury<=2*mxc)
	{
		query(curx,cury);
		int d=D;
		if(d>=B)break;
		if(d==0)
		{
			if(check(curx,cury,0))cury+=B;
			else curx+=B;
		}
		else
		{
			if(check1(curx,cury-d)||check1(curx,cury+d))cury+=d+B;
			else curx+=d+B;
		}
	}
	for(int i=0;i<=2*mxc;i+=B*2-1)solvev(i,min(2*mxc,i+B*2-2),cury);
	for(int i=0;i<=2*mxc;i+=B*2-1)solveh(i,min(2*mxc,i+B*2-2),curx);
	printf("1 %d %d\n",ansv.size(),ansh.size());fflush(stdout);
	for(auto x:ansv)printf("%d ",x-mxc);puts("");fflush(stdout);
	for(auto x:ansh)printf("%d ",x-mxc);puts("");fflush(stdout);
	return 0;
}