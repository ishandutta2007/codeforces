#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,h[705],cnt,size[705];
struct edge{int to,next;}e[1405];
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
const int MAX=50;
struct node {
	int num[MAX];
	node & operator = (const char*);
	node & operator = (int);
	node();
	node(int);
	bool operator > (const node &) const;
	bool operator < (const node &) const;
	bool operator <= (const node &) const;
	bool operator >= (const node &) const;
	bool operator != (const node &) const;
	bool operator == (const node &) const;
	node operator + (const node &) const;
	node operator - (const node &) const;
	node operator * (const node &) const;
	node operator / (const node &) const;
	node operator % (const node &) const;
	node & operator += (const node &);
	node & operator -= (const node &);
	node & operator *= (const node &);
	node & operator /= (const node &);
	node & operator %= (const node &);
}f[705][705],g[705];
node & node::operator = (const char* c) {
	memset(num,0,sizeof(num));
	int n=strlen(c),j=1,k=1;
	for (int i=1; i<=n; i++) {
		if (k==10000) j++,k=1;
		num[j]+=k*(c[n-i]-'0');
		k*=10;
	}
	num[0]=j;
	return *this;
}
node & node::operator = (int a) {
	char s[MAX];
	sprintf(s,"%d",a);
	return *this=s;
}
node::node() {
	memset(num,0,sizeof(num));
	num[0]=1;
}
node::node (int n) {
	*this = n;
}
bool node::operator > (const node &b) const {
	if (num[0]!=b.num[0]) return num[0]>b.num[0];
	for (int i=num[0]; i>=1; i--)
		if (num[i]!=b.num[i])
			return (num[i]>b.num[i]);
	return false;
}
bool node::operator < (const node &b) const {
	return b>*this;
}
bool node::operator <= (const node &b) const {
	return !(*this>b);
}

bool node::operator >= (const node &b) const {
	return !(b>*this);
}

bool node::operator != (const node &b) const {
	return (b>*this)||(*this>b);
}

bool node::operator == (const node &b) const {
	return !(b>*this)&&!(*this>b);
}
node node::operator + (const node &b) const {
	node c;
	c.num[0] = max(num[0], b.num[0]);
	for (int i=1; i<=c.num[0]; i++) {
		c.num[i]+=num[i]+b.num[i];
		if (c.num[i]>=10000) {
			c.num[i]-=10000;
			c.num[i+1]++;
		}
	}
	if (c.num[c.num[0]+1]>0) c.num[0]++;
	return c;
}
node node::operator - (const node &b) const {
	node c;
	c.num[0] = num[0];
	for (int i=1; i<=c.num[0]; i++) {
		c.num[i]+=num[i]-b.num[i];
		if (c.num[i]<0) {
			c.num[i]+=10000;
			c.num[i+1]--;
		}
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return c;
}
node & node::operator += (const node &b) {
	return *this=*this+b;
}

node & node::operator -= (const node &b) {
	return *this=*this-b;
}
node node::operator * (const node &b) const {
	node c;
	c.num[0] = num[0]+b.num[0]+1;
	for (int i=1; i<=num[0]; i++) {
		for (int j=1; j<=b.num[0]; j++) {
			c.num[i+j-1]+=num[i]*b.num[j];
			c.num[i+j]+=c.num[i+j-1]/10000;
			c.num[i+j-1]%=10000;
		}
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return c;
}
node & node::operator *= (const node &b) {
	return *this=*this*b;
}
node node::operator % (const node &b) const {
	node c, d;
	c.num[0] = num[0]+b.num[0]+1;
	d.num[0] = 0;
	for (int i=num[0]; i>=1; i--) {
		memmove(d.num+2, d.num+1, sizeof(d.num)-sizeof(int)*2);
		d.num[0]++;
		d.num[1]=num[i];
		int left=0, right=9999, mid;
		while (left < right) {
			mid = (left+right)/2;
			if (b*node(mid) <= d) left=mid+1;
			else right=mid;
		}
		c.num[i]=right-1;
		d=d-b*node(right-1);
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return d;

}
node & node::operator /= (const node &b) {
	return *this=*this/b;
}

node & node::operator %= (const node &b) {
	return *this=*this%b;
}
node node::operator / (const node& b) const {
	node c, d;
	c.num[0] = num[0]+b.num[0]+1;
	d.num[0] = 0;
	for (int i=num[0]; i>=1; i--) {
		memmove(d.num+2, d.num+1, sizeof(d.num)-sizeof(int)*2);
		d.num[0]++;
		d.num[1]=num[i];
		int left=0, right=9999, mid;
		while (left < right) {
			mid = (left+right)/2;
			if (b*node(mid) <= d) left=mid+1;
			else right=mid;
		}
		c.num[i]=right-1;
		d=d-b*node(right-1);
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return c;
}
ostream & operator << (ostream & o, node &n) {
	o<<n.num[n.num[0]];
	for (int i=n.num[0]-1; i>=1; i--) {
		o.width(4);
		o.fill('0');
		o<<n.num[i];
	}
	return o;
}
istream & operator >> (istream & in, node &n) {
	char s[MAX];
	in>>s;
	n=s;
	return in;
}
void DFS(int x,int prt){
	int i,j,k,y;size[x]=1;f[x][1]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;DFS(y,x);
		for(j=size[x]+size[y];~j;--j)g[j]=f[x][j];
		for(j=size[x];j>=1;--j){
			for(k=size[y];~k;--k){
				g[j+k]=max(g[j+k],f[x][j]*f[y][k]);
			}
		}
		size[x]+=size[y];for(j=size[x];~j;--j)f[x][j]=g[j];
	}
	for(j=size[x];~j;--j)f[x][0]=max(f[x][0],f[x][j]*j);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	DFS(1,0);cout<<f[1][0]<<endl;
	return 0;
}