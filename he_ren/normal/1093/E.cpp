#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXB = 1e3 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n,a[MAXN],b[MAXN];

int lB[MAXB],rB[MAXB],bId[MAXN],tot;
int val[MAXN];

void calcAll(void)
{
	static int cur[MAXB];
	static int tmp[MAXN];
	
	for(int i=1; i<=tot; ++i) cur[i]=lB[i];
	for(int i=1; i<=n; ++i) tmp[b[i]]=i;
	
	for(int i=1; i<=n; ++i)
	{
		int now = bId[tmp[i]];
		val[cur[now]] = i;
		++cur[now];
	}
}

void init(void)
{
	tot=sqrt(n);
	for(int i=1; i<=tot; ++i)
		lB[i]=(i-1)*tot+1,
		rB[i]=lB[i]+tot-1;
	chk_max(rB[tot],n);
	for(int i=1; i<=tot; ++i)
		for(int j=lB[i]; j<=rB[i]; ++j)
			bId[j]=i;
	calcAll();
}

int query(int l,int r,int x,int y)
{
	int res=0;
	if(bId[l]==bId[r])
	{
		for(int i=l; i<=r; ++i)
			if(x<=b[i] && b[i]<=y) ++res;
		return res;
	}
	
	int nowl=bId[l];
	for(int i=l; i<=rB[nowl]; ++i)
		if(x<=b[i] && b[i]<=y) ++res;
	int nowr=bId[r];
	for(int i=lB[nowr]; i<=r; ++i)
		if(x<=b[i] && b[i]<=y) ++res;
	
	for(int i=nowl+1; i<nowr; ++i)
		res += upper_bound(val+lB[i],val+rB[i]+1,y) - upper_bound(val+lB[i],val+rB[i]+1,x-1);
	return res;
}

struct Oper
{
	int x,y;
};
vector<Oper> upd; 

int main(void)
{
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		a[x]=i;
	}
	for(int i=1; i<=n; ++i)
		scanf("%d",&b[i]),
		b[i]=a[b[i]];
	init();
	
	int sqn = sqrt(n*(log(sqrt(n))/log(2)));
	while(Q--)
	{
		int oper,x,y;
		scanf("%d%d%d",&oper,&x,&y);
		if(oper==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int ans = query(l,r,x,y);
			for(int i=0; i<(int)upd.size(); ++i)
			{
				int xx=upd[i].x, yy=upd[i].y;
				if(l<=xx && xx<=r && x<=b[xx] && b[xx]<=y) --ans;
				if(l<=yy && yy<=r && x<=b[yy] && b[yy]<=y) --ans;
				swap(b[xx],b[yy]);
				if(l<=xx && xx<=r && x<=b[xx] && b[xx]<=y) ++ans;
				if(l<=yy && yy<=r && x<=b[yy] && b[yy]<=y) ++ans;
			}
			for(int i=upd.size()-1; i>=0; --i)
				swap(b[upd[i].x],b[upd[i].y]);
			printf("%d\n",ans);
		}
		else
		{
			upd.push_back((Oper){x,y});
			if((int)upd.size()>=sqn)
			{
				for(int i=0; i<(int)upd.size(); ++i)
					swap(b[upd[i].x],b[upd[i].y]);
				calcAll();
				upd.clear();
			}
		}
	}
	return 0;
}